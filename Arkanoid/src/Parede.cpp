#include "Parede.h"

Parede::Parede(){

}

void Parede::desenha() {

	GLfloat mat_ambient[] = { 0.19225, 0.19225, 0.19225, 1.0 };
	GLfloat mat_diffuse[] = { 0.50754, 0.50754, 0.50754, 1.0 };
    GLfloat mat_specular[] = { 0.508273, 0.508273, 0.508273, 1.0 };
    GLfloat mat_shininess[] = { 51.2 };

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	//glColor3f(0.3f, 0.3f, 0.4f); //glColor3f(0.4f, 0.4f, 0.4f);
	glPushMatrix();
	//glLoadIdentity();
	glTranslatef((GLfloat)-243.75, (GLfloat)-237.75, (GLfloat)0);
	glScalef((GLfloat)0.5, (GLfloat)1, (GLfloat)-1);
	for(int i=0; i<20;i++){
		glutSolidCube((GLfloat)25);
		glTranslatef((GLfloat)0, (GLfloat)25.0, (GLfloat)0); //neste caso não há problema com o scale porque está a 1 no y
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef((GLfloat) 243.75, (GLfloat)-237.75, (GLfloat)0);
	glScalef((GLfloat)0.5, (GLfloat)1, (GLfloat)1);
	for(int i=0; i<20;i++){
		glutSolidCube((GLfloat)25);
		glTranslatef((GLfloat)0, (GLfloat)25.0, (GLfloat)0);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef((GLfloat)-237.75, (GLfloat)243.75, (GLfloat)0);
	glScalef((GLfloat)1, (GLfloat)0.5, (GLfloat)1);
	for(int i=0; i<19;i++){
		glutSolidCube((GLfloat)25);
		glTranslatef((GLfloat)25, (GLfloat)0.0, (GLfloat)0);
	}
	glutSolidCube((GLfloat)25);
	glPopMatrix();
	//glFlush();
}

void Parede::actualiza(){

}