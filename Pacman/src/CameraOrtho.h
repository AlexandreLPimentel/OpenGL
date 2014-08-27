#ifndef pacman_CameraOrtho_h
#define pacman_CameraOrtho_h
#include "Camera.h"

struct CameraOrtho : Camera{
    float left, right, bottom, top, near, far, usedBottom, usedRight;
    virtual void changeAspect(float newAspect);
    virtual void update();
    CameraOrtho(float left, float right, float bottom, float top, float near, float far);
};

#endif
