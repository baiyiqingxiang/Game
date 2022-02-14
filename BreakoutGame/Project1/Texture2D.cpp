#include "Texture2D.h"

Texture2D::Texture2D():Width(0), Height(0), Internal_Format(GL_RGB),Image_Format(GL_RGB), Wrap_S(GL_REPEAT), Wrap_T(GL_REPEAT), Fielter_Min(GL_LINEAR), Fielter_Max(GL_LINEAR)
{
	// ����1������
	glGenTextures(1, &this->ID);
}

void Texture2D::Generate(GLuint width, GLuint height, unsigned char* data)
{
	this->Width = width;
	this->Height = height;
	// �󶨹���ǰ������ID
	glBindTexture(GL_TEXTURE_2D, this->ID);
	// ��������
	glTexImage2D(GL_TEXTURE_2D, 0, this->Internal_Format, this->Width, this->Height, 0, this->Image_Format,GL_UNSIGNED_BYTE, (void *)data);
	// ������˷�ʽ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->Wrap_S);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->Wrap_T);
	// �༶��Զ��������˷�ʽ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->Fielter_Min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->Fielter_Max);
	// ��Ĭ�ϵ�����
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, this->ID);
}

