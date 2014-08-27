#pragma once

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
struct Camera;
#include "Maze.h"

#define MOVE 0.25 //MAX = 1
#define STARTDIR -90

struct Pacman
{
    GLfloat x, y, direction, movement;
	Camera *camera;
	Maze* maze;
	int teclaUp, teclaDown, teclaLeft, teclaRight, proxpos;
	bool died;
    void desenhaEsfera(GLfloat x, GLfloat y, GLfloat z, GLfloat raio, GLfloat red, GLfloat green, GLfloat blue);
    Pacman(GLfloat x, GLfloat y, Maze* maze,int teclaUp, int teclaDown, int teclaLeft, int teclaRight, Camera* camera);
	bool colisao(int x, int y);
    void draw();
    void move();
	void receiveKey(int key);
	float getX();
	float getY();
	bool ver_colisao(GLfloat direction);
	void move_pacman();
	int round(float n);
	int lives;
	void drawExplosion();
	float particulas_x[100];
	float particulas_y[100];
	float particulas_z[100];
	bool particulas_z_direction[100];
	float seed_x[100];
	float seed_y[100];
	float seed_z[100];
	bool firstIter;
};

