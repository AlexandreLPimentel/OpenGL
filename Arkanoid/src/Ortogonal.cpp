#include "Ortogonal.h"
#include "Vector3.h"
#include <stdio.h>

Ortogonal::Ortogonal(){
}

void Ortogonal::SetCamera(double relacao_aspecto, double esquerda, double direita,
					double fundo, double top, double proximo, double distante){
					
					this->relacao_aspecto = relacao_aspecto;
					this->esquerda = esquerda;
					this->direita = direita;
					this->fundo = fundo;
					this->top = top;
					this->proximo = proximo;
					this->distante = distante;
					
}


void Ortogonal::CalculaMatrizProjeccao(){
	double a,b;
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	if(this->relacao_aspecto <= 1){
		a=fundo/this->relacao_aspecto;
		b=top/this->relacao_aspecto;
		glOrtho(esquerda, direita, a, b, proximo, distante);
	}
	else{
		a=esquerda*this->relacao_aspecto;
		b=direita*this->relacao_aspecto;
		glOrtho(a, b, fundo, top, proximo, distante);
	}
    
	}
	
	
	
void Ortogonal::CalculaMatrizVisualizacao(){
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	//A Ortogonal e so a identidade aqui, na Perspectiva e que nao (usar gluLookAt)
}


void Ortogonal::actualiza(){}