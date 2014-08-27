#include "Tijolo.h"

Tijolo::Tijolo(){
	exists = true;
}

void Tijolo::desenha() {

	if(!exists){
		return;
	}

	
	GLfloat mat_ambient[] = { r/3, g/3, b/3, 1.0 };
	GLfloat mat_diffuse[] = { r/2, g/2, b/2, 1.0 };
	GLfloat mat_specular[] = { r/2, g/2, b/2, 1.0 };
    GLfloat mat_shininess[] = { 100 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		glPushMatrix();
		glTranslatef(GetPosicao()->GetX()-12.5, GetPosicao()->GetY(), GetPosicao()->GetZ());
		if(GetPosicao()->GetX()<0)
			glScalef((GLfloat)1.0, (GLfloat)0.6, (GLfloat)1.0);
		else
			glScalef((GLfloat)1.0, (GLfloat)0.6, (GLfloat)-1.0);
		glutSolidCube((GLfloat)25);
		glTranslatef(25.0,0.0,0.0);
		glutSolidCube((GLfloat)25);
		glPopMatrix();

}

void Tijolo::actualiza(){

}

void Tijolo::SetCor(float r, float g, float b){
	this->r=r;
	this->g=g;
	this->b=b;
}

bool Tijolo::Exists(){
	return exists;
}

void Tijolo::Destroy(){
	exists = false;
}

void Tijolo::Restore(){
	exists = true;
}