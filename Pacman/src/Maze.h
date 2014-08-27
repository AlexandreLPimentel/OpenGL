#pragma once

#include "stdafx.h"
class Ghost;
extern Ghost* blinky, *pinky, *inky, *clyde;
class Maze
{
private:
	int maze[31][28];
	void desenhaCubo(GLfloat x, GLfloat y, GLfloat z, GLfloat size, GLfloat red, GLfloat green, GLfloat blue);
	void desenhaChao();
	
public:
	GLuint text;
	void loadText();
	Maze();
	bool colisao(int x, int y);
	void desenha_maze(void);
	bool give_pos_pac(int x, int y);
	bool power;
	int score;
	GLuint LoadTextureRAW( const char * filename, int wrap );
};

