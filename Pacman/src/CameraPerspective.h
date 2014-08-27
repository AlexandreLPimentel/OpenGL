#ifndef pacman_CameraPerspective_h
#define pacman_CameraPerspective_h

#include "Camera.h"
#include "Pacman.h"

struct CameraPerspective : Camera{
    float aspect, near, far;
    float x,y,z,toX,toY,toZ;
    float upX,upY,upZ;
    virtual void changeAspect(float newAspect);
    virtual void update();
    virtual void pacChanged(Pacman *p);
	virtual void drawText(int score, int lives, Camera* cameraortho);
    CameraPerspective(float aspect, float near, float far, float x, float y, float toX, float toY);
};

#endif
