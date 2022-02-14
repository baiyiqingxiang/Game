#ifndef TEXTURE2DCLASS_H
#define TEXTURE2DCLASS_H

#include <GL/glew.h>

class Texture2D
{
public:
	GLuint ID;
	GLuint Width;
	GLuint Height;
	GLuint Internal_Format;
	GLuint Image_Format;
	GLuint Wrap_S;
	GLuint Wrap_T;
	GLuint Fielter_Min;
	GLuint Fielter_Max;
	Texture2D();
	void Generate(GLuint width, GLuint height, unsigned char* data);
	void Bind() const;
};


#endif // !TEXTURE2DCLASS_H



