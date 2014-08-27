#include "stdafx.h"
#include "Pacman.h"
#include "Camera.h"
#include "Maze.h"
#include "stdlib.h"
#include "cmath"


Pacman::Pacman(GLfloat x, GLfloat y, Maze* maze,int teclaUp, int teclaDown, int teclaLeft, int teclaRight, Camera *camera){
	this->x = (int) x;
    this->y = (int) y;
	this->lives = 3;
	this->died = false;
	direction = STARTDIR;
	movement = STARTDIR;
	proxpos = 0;
	this->maze = maze;
	this->teclaUp = teclaUp;
	this->teclaDown = teclaDown;
	this->teclaLeft = teclaLeft;
	this->teclaRight = teclaRight;
    this->camera = camera;
	firstIter = true;
}

void Pacman::draw(){

	if(this->died){
		drawExplosion();
		return;
	}

	glPushMatrix();
	glTranslatef(x+0.5,y+0.5,0);
	glRotatef(movement,0,0,1);
    
    
    //Coisas da luz de minerio
    GLfloat light_position[] = { 0.0, 1.0, 1.0, 1.0};
    GLfloat light_direction[] = {0.0,-1.0,0.0, 1.0};
	GLfloat light_ambient[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat light_difuse[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat light_spec[] = { 1.0, 1.0, 1.0, 1.0};
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_difuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_spec);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 20);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 1.0);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION,light_direction);
    //Fim das coisas da luz de mineiro
    
	desenhaEsfera(0, 0, 0, 1, 1, 1, 0); //Pacman (bola amarela)

	desenhaEsfera(0.25, -0.5, 0.6, 0.3, 1, 1, 1); //Olho 1
	desenhaEsfera(-0.25, -0.5, 0.6, 0.3, 1, 1, 1); //Olho 2

	desenhaEsfera(0.25, -0.7, 0.7, 0.15, 0, 0, 0); //Pupila 1
	desenhaEsfera(-0.25, -0.7, 0.7, 0.15, 0, 0, 0); //Pupila 2

	desenhaEsfera(0.15, -0.35, 0.95, 0.1, 0, 0, 0); //Sobrancelha 1a
	desenhaEsfera(0.25, -0.3, 1.0, 0.1, 0, 0, 0); //Sobrancelha 1b
	desenhaEsfera(0.35, -0.3, 1.0, 0.1, 0, 0, 0); //Sobrancelha 1c
	desenhaEsfera(0.45, -0.35, 0.95, 0.1, 0, 0, 0); //Sobrancelha 1d

	desenhaEsfera(-0.15,-0.35, 0.9, 0.1, 0, 0, 0); //Sobrancelha 2a
	desenhaEsfera(-0.25,-0.3, 1.0, 0.1, 0, 0, 0); //Sobrancelha 2b
	desenhaEsfera(-0.35,-0.3, 1.0, 0.1, 0, 0, 0); //Sobrancelha 2c
	desenhaEsfera(-0.45,-0.35, 0.9, 0.1, 0, 0, 0); //Sobrancelha 2d
	glPopMatrix();
}


void Pacman::move(){
    //N‹o se pode por o c—digo o move_pacman aqui????
	move_pacman();
	camera->pacChanged(this);
}

void Pacman::move_pacman(){
	if(this->died) return;
	//Se já tiver chegado à próxima posição...
	maze->give_pos_pac(round(x), round(y));
	if(proxpos==(1/MOVE))
		if(ver_colisao(direction))
            if(!ver_colisao(movement)) proxpos=0;
			else return;
		else{
			movement=direction;
			proxpos=0;
		}
	//move-se
	proxpos++;
    //printf("X: %f, Y: %f.\n", x,y);
	switch((int)movement){
		case 0:
			y-=MOVE;
			return;
		case 180:
			y+=MOVE;
			return;
		case -90:
			x-=MOVE;
			return;
		case 90:
			x+=MOVE;
			return;
	}
}

bool Pacman::ver_colisao(GLfloat direction){
	switch((int)direction){
		case 0: return colisao(round(x), round(y-1));
		case 180: return colisao(round(x), round(y+1));
		case -90: return colisao(round(x-1), round(y));
		case 90: return colisao(round(x+1), round(y));
	}return false;
}

void Pacman::desenhaEsfera(GLfloat x, GLfloat y, GLfloat z, GLfloat raio, GLfloat red, GLfloat green, GLfloat blue){
	glPushMatrix();
    //TEST MODE
    //glColor3f(red, green, blue);
    GLfloat mat_specular[] = { red, green, blue, 0.0 };
    GLfloat mat_shininess[] = { 50.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    //END
	glTranslatef(x,y,z);
	glutSolidSphere(raio,10,10);
	glPopMatrix();
}

bool Pacman::colisao(int x, int y){
	return maze->colisao(x, y);
}

void Pacman::receiveKey(int key){
	if(key == teclaUp) direction = 0;
	else if(key == teclaLeft) direction = -90;
	else if(key == teclaDown) direction = 180;
	else if(key == teclaRight) direction = 90;
}

float Pacman::getX(){
	return x;
}

float Pacman::getY(){
	return y;
}

int Pacman::round(float n){
	int ret = (int) n;
	if((n-ret)>=0.5) ret++;
	return ret;
}

void Pacman::drawExplosion(){
	if(firstIter){
		for(int n=0; n<100; n++){
			seed_x[n]=(float)rand()/(float)RAND_MAX*2-1;
			seed_y[n]=(float)rand()/(float)RAND_MAX*2-1;
			seed_z[n]=((float)rand())/(float)RAND_MAX;
			while(seed_z[n]<=0.1)
				seed_z[n]=(float)rand()/(float)RAND_MAX;
			particulas_x[n]=this->x;
			particulas_y[n]=this->y;
			particulas_z[n]=0;
			particulas_z_direction[n]=false;
		}
		firstIter=false;
	}
	bool all_done = true;
	for(int n=0; n<100; n++){
		if(particulas_z[n]>=-0.5){
			all_done = false;
			particulas_x[n]+=seed_x[n];
			particulas_y[n]+=seed_y[n];
			if(particulas_z_direction[n])
				particulas_z[n]-=seed_z[n];
			else
				particulas_z[n]+=seed_z[n];
			if(particulas_z[n]>=1)
				particulas_z_direction[n]=true;
			desenhaEsfera(particulas_x[n], particulas_y[n], particulas_z[n], 0.2, ((float)rand())/(float)RAND_MAX, ((float)rand())/(float)RAND_MAX, ((float)rand())/(float)RAND_MAX);
		}
	}
	if(all_done){
		died=false;
		lives--;
		if(lives==0) exit(0);
		firstIter=true;
		this->x=14.0;
		this->y=23.0;
		direction = STARTDIR;
		movement = STARTDIR;
		proxpos = 0;
	}
}