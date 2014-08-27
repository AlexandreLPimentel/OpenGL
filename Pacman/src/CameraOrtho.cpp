#include "stdafx.h"
#include "CameraOrtho.h"

void CameraOrtho::update(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(left, usedRight, usedBottom, top, near, far);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void CameraOrtho::changeAspect(float newAspect){
    if (newAspect<=1){
        usedBottom = bottom/newAspect;
        usedRight = right;
    }else{
        usedBottom = bottom;
        usedRight = right*newAspect;
    }
    update();
}

CameraOrtho::CameraOrtho(float left, float right, float bottom, float top, float near, float far){
    this->left = left;
    this->right = right;
    this->bottom = bottom;
    this->top = top;
    this->near = near;
    this->far = far;
    this->usedRight = right;
    this->usedBottom = bottom;
}