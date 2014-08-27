#include "Bola.h"


Bola::Bola(){
	srand(time(NULL));
	free = false;
	//myLight = GL_LIGHT5;
	
	Vector3 *specular = new Vector3();
	Vector3 *diffuse = new Vector3();
	Vector3 *ambient = new Vector3();
	Vector3 *position = new Vector3();
	Vector3 *direction = new Vector3();

	specular->Set(0.5,0.5,0.5);
	diffuse->Set(0.4,0.4,0.4);
	ambient->Set(0.3,0.3,0.3);
	direction->Set(0.0, 0.0, -1.0);

	/*pon = new Spot();
	position->Set(0.0, 0.0, 100.0);
	pon->Set(ambient, diffuse, specular, direction, 60, 1);
	pon->SetPosicao(position);*/
}

void Bola::desenha(){
	GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 0.3 };
	GLfloat mat_diffuse[] = { 0.9, 0.9, 0.9, 0.3 };
    GLfloat mat_specular[] = { 0.9, 0.9, 0.9, 0.3 };
    GLfloat mat_shininess[] = { 100 };

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);

//	pon->Define(myLight);

	glPushMatrix();
	//glLoadIdentity();
	glTranslatef(GetPosicao()->GetX(), GetPosicao()->GetY(), GetPosicao()->GetZ());
	glutSolidSphere(7, 20, 20);
	glPopMatrix();
}

void Bola::actualiza(){
	Vector3* velocidade_tmp = GetVelocidade();
	Vector3* posicao_tmp = GetPosicao();
	if(!isMoving()){
		if(posicao_tmp->GetX()+velocidade_tmp->GetX()<-210)
			SetPosicao(-210, posicao_tmp->GetY(), posicao_tmp->GetZ());
		else if(posicao_tmp->GetX()+velocidade_tmp->GetX()>210)
			SetPosicao(210, posicao_tmp->GetY(), posicao_tmp->GetZ());
		else
			SetPosicao(posicao_tmp->GetX()+velocidade_tmp->GetX(), posicao_tmp->GetY(), posicao_tmp->GetZ());
		velocidade_tmp->Set(0,0,0);
		this->SetVelocidade(velocidade_tmp);
	}
	else{
		SetPosicao(posicao_tmp->GetX()+velocidade_tmp->GetX(), posicao_tmp->GetY()+velocidade_tmp->GetY(), posicao_tmp->GetZ());
	}
	/*if(velocidade_tmp->GetY()<0){
		glEnable(myLight);}
	else
		glDisable(myLight);
	pon->SetPosicao(this->GetPosicao());
	pon->Define(myLight);*/
}

void Bola::dispara(){
	Vector3* velocidade_tmp = new Vector3();
	float a, x, y;
	int b;
	if(isMoving())
		return;
	do{
		a = (float)rand() / (float)RAND_MAX;
	}while(a<0.1);

	x = a;
	y = 1;

	b = (int) rand() % 2;
	if(b)
		x=-x;

	velocidade_tmp->Set(x*7, y*7, 0);
	this->SetVelocidade(velocidade_tmp);
	
	free = true;
}

bool Bola::isMoving(){
	return free;
}

void Bola::stop(){
	this->free=false;
	Vector3* velocidade_tmp = new Vector3();
	velocidade_tmp->Set(0,0,0);
	this->SetVelocidade(velocidade_tmp);
}