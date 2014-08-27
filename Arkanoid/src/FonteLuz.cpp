#include "FonteLuz.h"
#include <stdio.h>

FonteLuz::FonteLuz(){
	ligada = false;
}


void FonteLuz::SetLuz(Vector3* ambiente, Vector3* difusa, Vector3* especular){
	this->ambiente=ambiente;
	this->difusa=difusa;
	this->especular=especular;
}

void FonteLuz::SetEstado(bool estado){
	ligada = estado;
}

bool FonteLuz::GetEstado(){
	return ligada;
}

void FonteLuz::DefineLuz(int n){ //n é o número desta luz
	
	GLfloat ambient[] = {ambiente->GetX(), ambiente->GetY(), ambiente->GetZ(), 1.0f};
    GLfloat specular[] = {especular->GetX(), especular->GetY(), especular->GetZ(), 1.0f};
	GLfloat diffuse[] = {difusa->GetX(), difusa->GetY(), difusa->GetZ(), 1.0f};


	glLightfv(n, GL_SPECULAR, specular);
    glLightfv(n, GL_DIFFUSE, diffuse);
    glLightfv(n, GL_AMBIENT, ambient);
	this->n=n;
}

int FonteLuz::GetN(){
	return n;
}


void FonteLuz::actualiza(){}


/*Iluminação global (ano passado, com alterações)
void globalLight(void){
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDisable(GL_LIGHT1);
    
    GLfloat ambient[] ={Rf, Gf, Bf, Af};
    GLfloat specular[] = {Rf, Gf, Bf, Af};
    GLfloat diffuse[] = {Rf, Gf, Bf, Af};
    
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    
    GLfloat position[] = {f, f, f, f};
    
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glEnable(GL_DEPTH_TEST);

}

//Spotlight (ano passado, com alterações)
void spotlight(void){
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);
    glDisable(GL_LIGHT0);
    
    GLfloat ambient[] ={Rf, Gf, Bf, Af};
    GLfloat specular[] = {Rf, Gf, Bf, Af};
    GLfloat diffuse[] = {Rf, Gf, Bf, Af};
    
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
    
    GLfloat position[] = {(nave_pos->GetX), (nave_pos->GetY), (nave_pos->GetZ), 1.0};
    GLfloat direction[] = {0.0f, 1.0f, 0.0f};
   
    GLfloat gambient[] ={Rf, Gf, Bf, Af};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, gambient);
    
    glLightfv(GL_LIGHT1, GL_POSITION, position);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 10.0);
    glEnable(GL_DEPTH_TEST);
}*/