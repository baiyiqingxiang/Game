
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
	GameState State; // 游戏状态
	GLboolean Keys[1024];
	GLuint Width;
	GLuint Height;
	// 构造函数
	Game(GLuint width, GLuint height);
	// 析构函数
	~Game();
	// 初始化游戏状态（加载所有的着色器、纹理、关卡）
	void Init();
	// 游戏循环
	void ProcessInput(GLfloat dt);
	void Update(GLfloat dt);
	void Render();
	
};

#endif // !GAME_H




