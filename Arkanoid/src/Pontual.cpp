#include "Pontual.h"
#include <stdio.h>

Pontual::Pontual(){
}

void Pontual::Set(Vector3* ambiente, Vector3* difusa, Vector3* especular){
	SetLuz(ambiente, difusa, especular);
}

void Pontual::Define(int n){
	

	this->DefineLuz(n);

	GLfloat position[] = {GetPosicao()->GetX(), GetPosicao()->GetY(), GetPosicao()->GetZ(), 1};

	glLightfv(n, GL_POSITION, position);
	glLightf(n, GL_SPOT_EXPONENT, 1);
	glLightf(n, GL_CONSTANT_ATTENUATION, 1);
	glLightf(n, GL_QUADRATIC_ATTENUATION, 0.001);
}