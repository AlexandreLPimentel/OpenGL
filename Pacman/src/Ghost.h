#pragma once

#include "stdafx.h"
#include "Maze.h"
#include "cmath"
#include "Pacman.h"
#include "time.h"
#include "stdlib.h"

#define MOVE 0.25
#define VOLTAS 30.0
#define STARTDIR -90
#define PI 3.14159265

extern Ghost* blinky;
extern Ghost* pinky;
extern Ghost* inky;
extern Ghost* clyde;

class Ghost
{
	private:
		int sentido;	//1 = cima, 2 = diagonal superior direita, 3 = direita, 4 = diagonal inferior direita,
						//5 = baixo, 6 = diagonal inferior esquerda, 7 = esquerda, 8 = diagonal superior esquerda
		int size_x, size_y, proxpos;
        GLfloat Sen,Cos,Sen2,Cos2,Senn,Cosn,x,y,movement, direction;
		Maze* maze;
		Pacman* pacman;
		void desenhaForma();
		void desenhaOlhos();
		void desenhaEsfera(float x, float y, float z, float raio, float red, float green, float blue);
		int round(float n);
		bool colisao(int x, int y);
		bool ver_colisao(GLfloat direction);
		bool ver_colisao_lados();
		GLfloat calc_nova_direccao(int percent, int option);
	public:
        bool drawwing;
		bool power;
        GLfloat red;
        GLfloat green;
        GLfloat blue;
        float h, w, movem;
		Ghost(float x, float y, Maze* maze_tmp, Pacman* pac, int sizex, int sizey, GLfloat r, GLfloat g, GLfloat b);
		void draw();
        void move();
        void calc_nova_direccao_colider();
};
