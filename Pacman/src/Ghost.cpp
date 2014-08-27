#include "stdafx.h"
#include "Ghost.h"
#include <stdio.h>

extern int ghostTime;

Ghost::Ghost(float x, float y, Maze* maze_tmp, Pacman* pac, int sizex, int sizey, GLfloat r, GLfloat g, GLfloat b){
	proxpos=0;
	movement=0;
    direction = 0;
	movem = MOVE;
	power = 0;
	size_x=sizex;
	size_y=sizey;
	maze = maze_tmp;
	h = y;
	w = x;
	red = r;
	green = g;
	blue = b;
	pacman = pac;
    Sen = 0.75*sin(PI*2.0/VOLTAS);
    Cos = 0.75*cos(PI*2.0/VOLTAS);
    Cos2 = 0.75*cos(PI/4);
    Sen2 = 0.75*sin(PI/4);
	Cosn = 0.75*cos(PI/8);
	Senn = 0.75*sin(PI/8);
    drawwing = true;
}

void Ghost::draw(){
	if(!drawwing) return;
    glPushMatrix();
	glTranslatef(w+0.5,h+0.5,0);

	float diffX = pacman->getX()-w;
	float diffY = pacman->getY()-h;
	
	if(diffX==0){
		if(diffY>0) glRotatef(180,0,0,1);
	}
	else if(diffY==0){
			if(diffX>0) glRotatef(90,0,0,1);
			else glRotatef(-90,0,0,1);
		}
		else{	
			double angulo = (atan((pacman->getX()-w)/(pacman->getY()-h)))* (180/PI);
			if(diffY>0) glRotatef(180-angulo, 0, 0, 1);
			else glRotatef(-angulo, 0, 0, 1);

		}
	desenhaOlhos();

	//TEST MODE
    GLfloat mat_ambient[] = { red, green, blue, 0.0 };
	GLfloat mat_diffuse[] = { red, green, blue, 0.0 };
    GLfloat mat_specular[] = { red, green, blue, 0.0 };
    GLfloat mat_shininess[] = { 20.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    //END

	desenhaForma();

	glPopMatrix();
}

void Ghost::desenhaForma(){
	int n;
	glPushMatrix();

	float AB[3] = {Cos-0.75, Sen, 0};
	float AC[3] = {-0.75, Sen, 0.5};
	float AE[3] = {0, 0, -1};

	float normal_t[] = {AB[1]*AC[2]-AB[2]*AC[1], -AB[0]*AC[2]+AB[2]*AC[0], AB[0]*AC[1]-AB[1]*AC[0]};
	float normal_r[] = {AE[1]*AB[2]-AE[2]*AB[1], -AE[0]*AB[2]+AE[2]*AB[0], AE[0]*AB[1]-AE[1]*AB[0]};

	for(n = 0; n < VOLTAS; n++){
		glBegin(GL_TRIANGLES);
			glNormal3fv(normal_t);
			glVertex3f(0.75, 0, 1);		//A
			glVertex3f(Cos, Sen, 1);	//B
			glVertex3f(0, 0, 1.5);		//C
		glEnd();
		glBegin(GL_QUADS);
			glNormal3fv(normal_r);
			glVertex3f(0.75, 0, 1);		//A
			glVertex3f(Cos, Sen, 1);	//B
			glVertex3f(Cos, Sen, 0);	//D
			glVertex3f(0.75, 0, 0);		//E
		glEnd();
		glRotatef(360.0/VOLTAS, 0, 0, 1);
	}
	glPopMatrix();
	
	glPushMatrix();
	float FH[3] = {Cosn-0.75,Senn,-0.5};
	float FG[3] = {Cos2-0.75,Sen2,0};
	float normal_b[3] = {FH[1]*FG[2]-FH[2]*FG[1], -FH[0]*FG[2]+FH[2]*FG[0], FH[0]*FG[1]-FH[1]*FG[0]};
	for(n = 0; n < 8; n++){
		glBegin(GL_TRIANGLES);
			glNormal3fv(normal_b);
			glVertex3f(0.75, 0, 0);			//F
			glVertex3f(Cosn, Senn, -0.5);	//H
			glVertex3f(Cos2, Sen2, 0);		//G
		glEnd();
		glRotatef(360.0/8, 0, 0, 1);
	}
	glPopMatrix();
}

void Ghost::desenhaOlhos(){
	desenhaEsfera(0.3,-0.85, 1.0, 0.15, 0.0,0.0,0.0); //Pupila 1
	desenhaEsfera(-0.3,-0.85, 1.0, 0.15, 0.0,0.0,0.0); //Pupila 2

	desenhaEsfera(0.3,-0.7, 0.9, 0.3, 1.0,1.0,1.0); //Olho 1
	desenhaEsfera(-0.3,-0.7, 0.9, 0.3, 1.0,1.0,1.0); //Olho 2
}

void Ghost::desenhaEsfera(float x, float y, float z, float raio, float red, float green, float blue){
	glPushMatrix();
    //TEST MODE
	GLfloat mat_ambient[] = { red, green, blue, 0.0 };
	GLfloat mat_diffuse[] = { red, green, blue, 0.0 };
    GLfloat mat_specular[] = { red, green, blue, 0.0 };
    GLfloat mat_shininess[] = { 20.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    //END
    glTranslatef(x,y,z);
	glutSolidSphere(raio,20,20);
	glPopMatrix();
}

void Ghost::calc_nova_direccao_colider(){
    
}

void fantasmarenasce(int fantasma){
    Ghost *fantasmaarenascer = NULL;
    switch (fantasma) {
        case 0:
            fantasmaarenascer=blinky;
            break;
        case 1:
            fantasmaarenascer=clyde;
            break;
        case 2:
            fantasmaarenascer=pinky;
            break;
        case 3:
            fantasmaarenascer=inky;
            break;
    }
    fantasmaarenascer->drawwing = true;
    fantasmaarenascer->power = true;
    fantasmaarenascer->h = 14;
    fantasmaarenascer->w = 14;
}

void Ghost::move(){
    if(!drawwing) return;
    const int raio = 1.0;
    if((round(h+raio) >= round(pacman->y-raio) && round(h+raio)<=round(pacman->y-raio) && round(w)==round(pacman->x))
	|| (round(w+raio) >= round(pacman->x-raio) && round(w+raio)<=round(pacman->x-raio) && round(h)==round(pacman->y))
	|| (round(h-raio) <= round(pacman->y+raio) && round(h-raio)>=round(pacman->y+raio) && round(w)==round(pacman->x))
	|| (round(w-raio) <= round(pacman->x+raio) && round(w-raio)>=round(pacman->x+raio) && round(h)==round(pacman->y))
	|| (round(w)==round(pacman->x) && round(h)==round(pacman->y))){
        if(power){
            drawwing = false;
            int fantasmarenascente = (this == clyde)?1:((this==pinky?2:((this==inky)?3:0)));
            glutTimerFunc(5000, fantasmarenasce, fantasmarenascente);
        }else{
			extern Pacman* pac;
			pac->died=true;
			pinky->h = 13;
			pinky->w = 13;
			pinky->proxpos=0;
			blinky->h = 11;
			blinky->w = 13;
			blinky->proxpos=0;
			inky->h = 13;
			inky->w = 11;
			inky->proxpos=0;
			clyde->h = 13;
			clyde->w = 15;
			clyde->proxpos=0;
		}
    }
	//srand(time(NULL)+red+green+blue);
    if(proxpos==(1/MOVE)){
        if(power) ghostTime = 40*(3/2);
        else ghostTime = 40;
        if(!ver_colisao_lados()) calc_nova_direccao(0,0);
		if(ver_colisao(direction)){
            if(!ver_colisao(movement)) proxpos=0;
            else return;
        }else{
            movement=direction;
            proxpos=0;
        }
    }
    
    //printf("X: %f, Y: %f.\n", w, h);
    
	//move-se
	proxpos++; 
    
	switch((int)movement){
		case 0:
			h-=movem;
			return;
		case 180:
			h+=movem;
			return;
		case -90:
			w-=movem;
			return;
		case 90:
			w+=movem;
			return;
	}
}

int Ghost::round(float n){
	int ret = (int) n;
	if((n-ret)>=0.5) ret++;
	return ret;
}

bool Ghost::ver_colisao(GLfloat direction){
	switch((int)direction){
		case 0: return colisao(round(w), round(h-1));
		case 180: return colisao(round(w), round(h+1));
		case -90: return colisao(round(w-1), round(h));
		case 90: return colisao(round(w+1), round(h));
	}return false;
}

bool Ghost::colisao(int x, int y){
	return maze->colisao(x, y);
}

bool Ghost::ver_colisao_lados(){
	if((int)movement==90||(int)movement==-90)
		return (colisao(round(w),round(h-1))&&colisao(round(w),round(h+1)));
	else
		return (colisao(round(w-1),round(h))&&colisao(round(w+1),round(h)));
}

GLfloat Ghost::calc_nova_direccao(int percent, int option){

    GLfloat diffX = (pacman->x) - w;
    GLfloat diffY = (pacman->y) - h;
    GLfloat PDiffX = (diffX<0)?(-diffX):diffX;
    GLfloat PDiffY = (diffY<0)?(-diffY):diffY;

    GLfloat backerer = (movement==0)?180:((movement==180)?0:((movement==90)?-90:90));
    
    GLfloat directionX = (diffX<0)?-90:90;
    GLfloat directionY = (diffY<0)?0:180;
    
    if(power){
        directionX = -directionX;
        directionY = 180-directionY;
    }
    
    //if(directionX == backerer || directionY == backerer) return 0;
    
    if(rand()%100 < 75){
        if((PDiffX > PDiffY)){
            if(ver_colisao(direction = directionX) && ver_colisao(direction = directionY))
                direction = backerer;
        }else{
            if(ver_colisao(direction = directionY) && ver_colisao(direction = directionX))
                direction = backerer;
        }
    }else
        switch(rand()%4){
            case 0: direction = 0;break;
            case 1: direction = 90;break;
            case 2: direction = -90;break;
            case 3: direction = 180;break;
        }
    
    return 0;
}