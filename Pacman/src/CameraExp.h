#ifndef pacman_CameraExp_h
#define pacman_CameraExp_h
#include "CameraPerspective.h"

struct CameraExp : CameraPerspective{
    int teclaUp, teclaDown, teclaLeft, teclaRight;
    virtual void receiveKey(int key){
        
    }
    CameraExp(float aspect, float near, float far, float x, float y, float toX, float toY,int teclaUp,int teclaDown,int teclaLeft,int teclaRight):CameraPerspective(aspect,near,far,x,y,toX,toY){
        this->teclaUp = teclaUp;
        this->teclaDown = teclaDown;
        this->teclaLeft = teclaLeft;
        this->teclaRight = teclaRight;
    }
};

#endif
