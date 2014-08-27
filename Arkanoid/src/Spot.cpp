#include "Spot.h"
#include <stdio.h>

Spot::Spot(){
}

void Spot::Set(Vector3* ambiente, Vector3* difusa, Vector3* especular, Vector3* direccao, GLfloat cut_off, GLfloat expoente){
	SetLuz(ambiente, difusa, especular);
	this->direccao = direccao;
	this->cut_off = cut_off;
	this->expoente = expoente;
}

void Spot::Define(int n){
	

	this->DefineLuz(n);

	GLfloat position[] = {GetPosicao()->GetX(), GetPosicao()->GetY(), GetPosicao()->GetZ(), 1};
	GLfloat direction[] = {direccao->GetX(), direccao->GetY(), direccao->GetZ()};

	glLightfv(n, GL_POSITION, position);
    glLightfv(n, GL_SPOT_DIRECTION, direction);
	glLightf(n, GL_SPOT_CUTOFF, cut_off);
	glLightf(n, GL_SPOT_EXPONENT, expoente);
	glLightf(n, GL_CONSTANT_ATTENUATION, 1);
}