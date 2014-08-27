#ifndef pacman_Camera_h
#define pacman_Camera_h
#include "Pacman.h"
#include <stdio.h>

struct Camera{
	int teclaUp, teclaDown, teclaLeft, teclaRight, lightInUse;
    virtual void changeAspect(float newAspect) = 0;
    virtual void update() = 0;
    virtual void pacChanged(Pacman *p){}
	void linkToPacman(Pacman *p){
		p->camera = this;
        pacChanged(p);
	}
    virtual void receiveKey(int key){}
	virtual void drawText(int score, int lives, Camera* cameraortho) {
	//CODIGO A FUNCIONAR PARA CAMARA ORTHO
		void* textsize = GLUT_BITMAP_TIMES_ROMAN_24;
		char c[200];
        glPushMatrix();
		//glDisable(lightInUse);
        glDisable(GL_LIGHTING);
		glColor3f(1.0,1.0,1.0);
        sprintf(c,"Score: %d", score);
        glRasterPos3f(0.5, 13, 2);
        for (char* car=c; *car != '\0'; car++){
            glutBitmapCharacter(textsize, *car);
        }
		char l[200];
		sprintf(l,"Vidas: %d", lives);
		glRasterPos3f(0.5, 17, 2);
		for (char* liv=l; *liv != '\0'; liv++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *liv);
        }
		//glEnable(lightInUse);
		glEnable(GL_LIGHTING);
        glPopMatrix();
	}
};

#endif
