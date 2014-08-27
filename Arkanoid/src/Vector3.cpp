#include "Vector3.h"

float Vector3::GetX(){
	return x;
}

float Vector3::GetY(){
	return y;
}

float Vector3::GetZ(){
	return z;
}

void Vector3::Set(float x, float y, float z){
	this->x=x;
	this->y=y;
	this->z=z;
}
Vector3::Vector3(){
	x=0;
	y=0;
	z=0;
}