#include "stdafx.h"
#include "CameraPerspective.h"

void CameraPerspective::changeAspect(float newAspect){
    aspect = newAspect;
    update();
}

void CameraPerspective::update(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, -aspect, near, far);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	gluLookAt(x, y, 10, toX, toY, 0, 0, 0, 1);
}

CameraPerspective::CameraPerspective(float aspect, float near, float far, float x, float y, float toX, float toY){
    this->aspect = aspect;
    this->near = near;
    this->far = far;
    this->x = x;
    this->y = y;
    this->toX = toX;
    this->toY = toY;
}

void CameraPerspective::pacChanged(Pacman *p){
    const float distancia = 5;
    x=p->x;
    y=p->y+distancia;
    toX = p->x;
    toY = p->y;
}

void CameraPerspective::drawText(int score, int lives, Camera* cameraortho){
		char c[200];
        glPushMatrix();
        //glDisable(lightInUse);
		glDisable(GL_LIGHTING);
		cameraortho->update();
		glColor3f(1.0,1.0,1.0);
        sprintf(c,"Score: %d", score);
        glRasterPos3f(0, 1, 2);
        for (char* car=c; *car != '\0'; car++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *car);
        }
		char l[200];
		sprintf(l,"Vidas: %d", lives);
		glRasterPos3f(23.5, 1, 2);
		for (char* liv=l; *liv != '\0'; liv++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *liv);
        }
		this->update();
        //glEnable(lightInUse);
		glEnable(GL_LIGHTING);
        glPopMatrix();
}