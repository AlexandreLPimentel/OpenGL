#include "Perspectiva.h"


Perspectiva::Perspectiva(){
}

void Perspectiva::CalculaMatrizProjeccao(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, relacao_aspecto, proximo/*10*/, distante/*300*/);

}


void Perspectiva::CalculaMatrizVisualizacao(){
	Vector3* eye = this->GetPosicao();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye->GetX(), eye->GetY(), eye->GetZ(),
		this->center->GetX(), this->center->GetY(), this->center->GetZ(),
		this->up->GetX(), this->up->GetY(), this->up->GetZ());

}

void Perspectiva::SetEye(double x, double y, double z){
	this->SetPosicao(x,y,z);
}

void Perspectiva::actualiza(){}

void Perspectiva::SetCamera(double relacao_aspecto, double fov, double proximo, double distante){
	this->SetAspect(relacao_aspecto);
	this->fov=fov;
	this->proximo=proximo;
	this->distante=distante;
}
