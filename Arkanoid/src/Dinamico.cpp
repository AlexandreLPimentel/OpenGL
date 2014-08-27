#include "Dinamico.h"

Dinamico::Dinamico(){
	velocidade = new Vector3();
	velocidade->Set(0,0,0);
}

void Dinamico::SetVelocidade(Vector3* velocidade){
	this->velocidade = velocidade;
}

Vector3* Dinamico::GetVelocidade(){
	return this->velocidade;
}