#include "Camara.h"

Camara::Camara(){
	this->relacao_aspecto=0;
	this->center = new Vector3();
	this->up = new Vector3();
	center->Set(0,0,0);
	up->Set(0,0,0);
}

void Camara::SetAspect(double relacao_aspecto){
	this->relacao_aspecto=relacao_aspecto;
}

void Camara::SetCenter(double x, double y, double z){
	Vector3* tmp = new Vector3();
	tmp->Set(x, y, z);
	this->center = tmp;
}

void Camara::SetUp(double x, double y, double z){
	Vector3* tmp = new Vector3();
	tmp->Set(x, y, z);
	this->up = tmp;
}