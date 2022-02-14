
#ifndef SHADER_H
#define SHADER_H
#define GLEW_STATIC
#include <iostream>
#include <string>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Shader
{
public:
	GLuint ID;
	Shader();
	// 激活当前着色器
	Shader &Use();
	// 编译着色器
	void Compile(const GLchar* vertexSource, const GLchar* fragmentSource, const GLchar* geometrySource = nullptr);
	// Uniform设置函数
	void SetFloat(const GLchar* name, GLfloat value, GLboolean useShader = false);
	void SetInteger(const GLchar* name, GLint value, GLboolean useShader = false);
	void SetVector2f(const GLchar* name, GLfloat x, GLfloat y, GLboolean useShader = false);
	void SetVector2f(const GLchar* name, const glm::vec2& value, GLboolean useShader = false);
	void SetVector3f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader = false);
	void SetVector3f(const GLchar* name, const glm::vec3& value, GLboolean useShader = false);
	void SetVector4f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader = false);
	void SetVector4f(const GLchar* name, const glm::vec4& value, GLboolean useShader = false);
	void SetMatrix4(const GLchar* name, const glm::mat4& matrix,GLboolean useShader = false);
private:
	// 检查编译错误
	void CheckCompileErrors(GLuint obj, std::string type);
};
#endif // !SHADER_CLASS_H

