#include "Shader.h"

Shader& Shader::Use()
{
	glUseProgram(this->ID);
	return *this;
}

void Shader::Compile(const GLchar* vertexSource, const GLchar* fragmentSource, const GLchar* geometrySource)
{
	GLuint sVertex;
	GLuint sFragment;
	GLuint sGeometry;

	// 生成顶点着色器
	sVertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(sVertex, 1, &vertexSource, NULL);
	glCompileShader(sVertex);
	CheckCompileErrors(sVertex, "VERTEX SHADER");

	// 生成片段着色器
	sFragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(sFragment, 1, &fragmentSource, NULL);
	glCompileShader(sFragment);
	CheckCompileErrors(sFragment, "FRAGMENT SHADER");

	// 几何着色器
	if (geometrySource != nullptr)
	{
		sGeometry = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(sGeometry, 1, &geometrySource, NULL);
		glCompileShader(sGeometry);
		CheckCompileErrors(sGeometry, "Geometry SHADER");
	}
	// 创建着色器程序
	this->ID = glCreateProgram();
	// 连接着色器
	glAttachShader(this->ID, sVertex);
	glAttachShader(this->ID, sFragment);
	if (geometrySource != nullptr)
	{
		glAttachShader(this->ID, sGeometry);
	}
	glLinkProgram(this->ID);
	CheckCompileErrors(this->ID, "PROGREAM");
	// 当链接到程序之后删除着色器
	glDeleteShader(sVertex);
	glDeleteShader(sFragment);
	if (geometrySource != nullptr)
	{
		glDeleteShader(sGeometry);
	}
	
}

void Shader::SetFloat(const GLchar* name, GLfloat value, GLboolean useShader)
{
	if (useShader)
	{
		this->Use();
	}
	glUniform1f(glGetUniformLocation(this->ID, name), value);
}

void Shader::SetInteger(const GLchar* name, GLint value, GLboolean useShader)
{
	if (useShader)
	{
		this->Use();
	}
	glUniform1i(glGetUniformLocation(this->ID, name), value);
}

void Shader::SetVector2f(const GLchar* name, GLfloat x, GLfloat y, GLboolean useShader)
{
	if (useShader)
	{
		this->Use();
	}
	glUniform2f(glGetUniformLocation(this->ID, name), x, y);
}

void Shader::SetVector2f(const GLchar* name, const glm::vec2& value, GLboolean useShader)
{
	if (useShader)
	{
		this->Use();
	}
	glUniform2f(glGetUniformLocation(this->ID, name), value.x, value.y);
}

void Shader::SetVector3f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader)
{
	if (useShader)
	{
		this->Use();
	}
	glUniform3f(glGetUniformLocation(this->ID, name), x, y, z);
}

void Shader::SetVector3f(const GLchar* name, const glm::vec3& value, GLboolean useShader)
{
	if (useShader)
	{
		this->Use();
	}
	glUniform3f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z);
}

void Shader::SetVector4f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader)
{
	if (useShader)
	{
		this->Use();
	}
	glUniform4f(glGetUniformLocation(this->ID, name), x, y, z, w);
}

void Shader::SetVector4f(const GLchar* name, const glm::vec4& value, GLboolean useShader)
{
	if (useShader)
	{
		this->Use();
	}
	glUniform4f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z, value.w);
}

void Shader::SetMatrix4(const GLchar* name, const glm::mat4& matrix, GLboolean useShader)
{
	if (useShader)
	{
		this->Use();
	}
	glUniformMatrix4fv(glGetUniformLocation(this->ID, name), 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::CheckCompileErrors(GLuint obj, std::string type)
{
	GLint success;
	GLchar infoLog[1024];

	if (type != "PROGREAM")
	{
		glGetShaderiv(obj, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(obj, 1024, NULL, infoLog);
			std::cout << "------------------" << std::endl;
			std::cout << "ERROR--SHADER--COMPILE" << "\n" << " Type:" << type << "\n" << "Log:" << infoLog << std::endl;
			std::cout <<"-------------------" << std::endl;
		}
	}
	else
	{
		glGetProgramiv(obj, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(obj, 1024, NULL, infoLog);
			std::cout << "------------------" << std::endl;
			std::cout << "ERROR--SHADER--LINK" << "\n" << " Type:" << type << "\n" << "Log:" << infoLog << std::endl;
			std::cout << "-------------------" << std::endl;
		}

	}
}
