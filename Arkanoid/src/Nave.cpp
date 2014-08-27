#include "Nave.h"
#include "cmath"

Nave::Nave(){

}


void Nave::desenha(){
	

	
	GLfloat mat_ambient1[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat mat_diffuse1[] = { 0.7, 0.7, 0.7, 1.0 };
    GLfloat mat_specular1[] = { 0.7, 0.7, 0.7, 1.0 };
    GLfloat mat_shininess1[] = { 0.1 };

	GLfloat mat_ambient2[] = { 0.9, 0.0, 0.0, 1.0 };
	GLfloat mat_diffuse2[] = { 0.9, 0.0, 0.0, 1.0 };
    GLfloat mat_specular2[] = { 0.9, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess2[] = { 0.1 };

	glPushMatrix();
	glTranslatef(GetPosicao()->GetX(), GetPosicao()->GetY(), GetPosicao()->GetZ());

	
	float normal[] = {0,0,1};
	float normal2[] = {1,0,1};
	float normal3[] = {1,0,0};
	float normal4[] = {-1,0,1};
	float normal5[] = {-1,0,1};

	for(int n = 0; n < 8; n++){



		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_ambient1);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);
		
		glBegin(GL_QUADS);
		glNormal3fv(normal);
		glVertex3f(20, 2.1, 5);	
		glVertex3f(20, -2.1, 5);	
		glVertex3f(-20, -2.1, 5);	
		glVertex3f(-20, 2.1, 5);		
		glEnd();

		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient2);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_ambient2);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess2);

		glBegin(GL_QUADS);
		glNormal3fv(normal);
		glVertex3f(25, 2.1, 5);	
		glVertex3f(25, -2.1, 5);	
		glVertex3f(20, -2.1, 5);	
		glVertex3f(20, 2.1, 5);		
		glEnd();

		glBegin(GL_QUADS);
		glNormal3fv(normal);
		glVertex3f(-25, 2.1, 5);	
		glVertex3f(-25, -2.1, 5);	
		glVertex3f(-20, -2.1, 5);	
		glVertex3f(-20, 2.1, 5);		
		glEnd();

		glBegin(GL_QUADS);
		glNormal3fv(normal2);
		glVertex3f(25, 2.1, 5);	
		glVertex3f(25, -2.1, 5);
		glVertex3f(27.5, -1.05, 2.5);
		glVertex3f(27.5, 1.05, 2.5);	
		glEnd();

		glBegin(GL_TRIANGLES);
		glNormal3fv(normal3);
		glVertex3f(27.5, -1.05, 2.5);
		glVertex3f(27.5, 1.05, 2.5);
		glVertex3f(27.5, 0, 0);
		glEnd();

		glBegin(GL_QUADS);
		glNormal3fv(normal4);
		glVertex3f(-25, 2.1, 5);	
		glVertex3f(-25, -2.1, 5);
		glVertex3f(-27.5, -1.05, 2.5);
		glVertex3f(-27.5, 1.05, 2.5);	
		glEnd();

		glBegin(GL_TRIANGLES);
		glNormal3fv(normal3);
		glVertex3f(-27.5, -1.05, 2.5);
		glVertex3f(-27.5, 1.05, 2.5);
		glVertex3f(-27.5, 0, 0);
		glEnd();

		glRotatef(45.0, 1, 0, 0);
	}



	/*

	glTranslatef(30,0,0);
	//glScalef(2.5, 1, 2.5);
	glutSolidSphere(5,20,20); 
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-30,0,0);
	//glScalef(2.5, 1, 2.5);
	glutSolidSphere(5,20,20);
	glPopMatrix();

	//barra

	glPushMatrix();
	glScalef(5, 1, 1);
	glutSolidCube(10);
	glPopMatrix();

	
	//riscas
	//glColor3f(1,0,0);

	glPushMatrix();
	glTranslatef(27.5,0,0);
	glScalef(0.5,1,1);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-27.5,0,0);
	glScalef(0.5,1,1);
	glutSolidCube(10);
	glPopMatrix();
	*/
	glPopMatrix();
}

void Nave::actualiza(){
	Vector3* velocidade_tmp = GetVelocidade();
	Vector3* posicao_tmp = GetPosicao();
	if(posicao_tmp->GetX()+velocidade_tmp->GetX()<-210)
		SetPosicao(-210, posicao_tmp->GetY(), posicao_tmp->GetZ());
	else if(posicao_tmp->GetX()+velocidade_tmp->GetX()>200)
		SetPosicao(210, posicao_tmp->GetY(), posicao_tmp->GetZ());
	else
		SetPosicao(posicao_tmp->GetX()+velocidade_tmp->GetX(), posicao_tmp->GetY(), posicao_tmp->GetZ());
	velocidade_tmp->Set(0,0,0);
	this->SetVelocidade(velocidade_tmp);
}

/*
struct Nave () {
	glPushMatrix();
	glutSolidCube (GLdouble 50);
	glScalef(GLfloat 2, GLfloat 1, GLfloat 1);
	glTranslatef(GLfloat 0, GLfloat 750, GLfloat 0);
	glutSolidSphere (GLdouble 25, GLint 1, GLint 1);
	glTranslafef(GLfloat 50, GLfloat 750, GLfloat 0);
	glutSolidSphere (GLdouble 25, GLint 1, GLint 1);
	glTranslafef(GLfloat -50, GLfloat 750, GLfloat 0);
	glSolidCube (GLdouble 50);
	glScalef(GLfloat .2, GLfloat 1, GLfloat 1);
	glTranslatef(GLfloat 40, GLfloat 750, GLfloat 0);
	glSolidCube (GLdouble 50);
	glScalef(GLfloat .2, GLfloat 1, GLfloat 1);
	glTranslatef(GLfloat -40, GLfloat 750, GLfloat 0);
	glPopMatrix();
}
*/