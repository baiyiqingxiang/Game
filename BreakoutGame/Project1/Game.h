
#ifndef GAMECLASS_H
#define GAMECLASS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>


enum  GameState 
{
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};
class Game
{
public:
	GameState State; // ��Ϸ״̬
	GLboolean Keys[1024];
	GLuint Width;
	GLuint Height;
	// ���캯��
	Game(GLuint width, GLuint height);
	// ��������
	~Game();
	// ��ʼ����Ϸ״̬���������е���ɫ���������ؿ���
	void Init();
	// ��Ϸѭ��
	void ProcessInput(GLfloat dt);
	void Update(GLfloat dt);
	void Render();
	
};

#endif // !GAME_H




