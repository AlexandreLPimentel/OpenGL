#include "Direcional.h"

Direcional::Direcional(){
}

void Direcional::Set(Vector3* ambiente, Vector3* difusa, Vector3* especular, Vector3* direccao){
	this->SetLuz(ambiente, difusa, especular);
	this->direccao = direccao;
}

void Direcional::Define(int n){

	this->DefineLuz(n);

	GLfloat position[] = {GetPosicao()->GetX(), GetPosicao()->GetY(), GetPosicao()->GetZ(), 0};
	GLfloat direction[] = {direccao->GetX(), direccao->GetY(), direccao->GetZ()};

	glLightfv(n, GL_POSITION, position);
    glLightfv(n, GL_SPOT_DIRECTION, direction);
	glLightf(n, GL_SPOT_CUTOFF, 180);
}