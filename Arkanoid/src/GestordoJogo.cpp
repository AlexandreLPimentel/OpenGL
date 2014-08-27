#include "GestordoJogo.h"
#include <time.h>
#include <stdio.h>



void GestordoJogo::TrataEventoDisplay(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LEQUAL);


	glPushMatrix();

	actual->CalculaMatrizProjeccao();
		
	actual->CalculaMatrizVisualizacao();

	glMatrixMode(GL_MODELVIEW);

	if(text){
		void* textsize = GLUT_BITMAP_TIMES_ROMAN_24;
		char c[200];
        glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.0,1.0,0.0);
        sprintf_s(c,"Game Over");
        glRasterPos3f(-70, 100, 0);
        for (char* car=c; *car != '\0'; car++){
            glutBitmapCharacter(textsize, *car);
        }
		sprintf_s(c,"Pontos: %d", points);
        glRasterPos3f(-60, 50, 0);
        for (char* car=c; *car != '\0'; car++){
            glutBitmapCharacter(textsize, *car);
        }
		sprintf_s(c,"Pressione r para reinciar o jogo");
        glRasterPos3f(-150, 0, 0);
        for (char* car=c; *car != '\0'; car++){
            glutBitmapCharacter(textsize, *car);
        }
		glEnable(GL_LIGHTING);
        glPopMatrix();
		glPopMatrix();
		glutSwapBuffers(); 
		return;
	}

	if(L)
		dir->Define(GL_LIGHT0);
	if(C){
		spot1->Define(GL_LIGHT1);
		spot2->Define(GL_LIGHT2);
		spot3->Define(GL_LIGHT3);
		spot4->Define(GL_LIGHT4);
	}

	pon->SetEstado(true);
	pon->Define(GL_LIGHT5);

	glEnable(GL_COLOR_MATERIAL);
	chao->desenha();
	glDisable(GL_COLOR_MATERIAL);

	parede->desenha();

	for (int j = 0; j < 6; j++)
		for (int i = 0; i < 9; i++)
			tijolos[i][j]->desenha();

	bola->desenha();

	nave->desenha();

	glFlush();

	glutSwapBuffers(); 
	glPopMatrix();

}

void GestordoJogo:: TrataEventoReshape(GLsizei w, GLsizei h){
	actual->SetAspect((GLfloat) (w) / (GLfloat) (h));
	glViewport(0, 0, w, h);
	//actual->CalculaMatrizProjeccao();
	//actual->CalculaMatrizVisualizacao();
}

void GestordoJogo::TrataEventoKeyPressed(unsigned char tecla, int x, int y){
	if(lives==0){
		if(tecla=='r'){
			text=false;
			Reinicia();
		}
		return;
	}

	if(tecla == LEFT){
		Vector3* tmp = new Vector3();
		tmp->Set(-10,0,0);
		Vector3* tmp2 = new Vector3();
		tmp2->Set(-10,0,0);
		nave->SetVelocidade(tmp);
		if(!bola->isMoving())
			bola->SetVelocidade(tmp2);
	}
	else if(tecla == RIGHT){
		Vector3* tmp = new Vector3();
		tmp->Set(10,0,0);
		Vector3* tmp2 = new Vector3();
		tmp2->Set(10,0,0);
		nave->SetVelocidade(tmp);
		if(!bola->isMoving())
			bola->SetVelocidade(tmp2);
	}
	else if(tecla == ' ')
		bola->dispara();
	else if(tecla =='1')
		actual=orto;
	else if(tecla=='2')
		actual=persp;
	else if(tecla=='3')
		actual=pp;
	else if(tecla=='l'||tecla=='L'){
		L=!L;
		if(L)
			glEnable(GL_LIGHT0);
		else
			glDisable(GL_LIGHT0);
		dir->SetEstado(L);
	}
	else if(tecla=='c'||tecla=='C'){
		C=!C;
		if(C){
			glEnable(GL_LIGHT1);
			glEnable(GL_LIGHT2);
			glEnable(GL_LIGHT3);
			glEnable(GL_LIGHT4);
		}
		else{
			glDisable(GL_LIGHT1);
			glDisable(GL_LIGHT2);
			glDisable(GL_LIGHT3);
			glDisable(GL_LIGHT4);
		}
		spot1->SetEstado(C);
		spot2->SetEstado(C);
		spot3->SetEstado(C);
		spot4->SetEstado(C);
	}
}

void GestordoJogo::TrataEventoTimer(){
	this->Actualiza();
	glutPostRedisplay();
}

void GestordoJogo::TrataEventoIdle(){

}
void GestordoJogo::Actualiza(){
	
	if(lives==0){
		text = true;
		actual=orto;
		return;
	}

	nave->actualiza();
	bola->actualiza();
	Vector3* nave_pos = nave->GetPosicao();
	persp->SetEye(nave_pos->GetX(), nave_pos->GetY()-50, nave_pos->GetZ()+200);
	persp->SetCenter(nave_pos->GetX(), nave_pos->GetY()+100, nave_pos->GetZ());
	pp->SetEye(nave_pos->GetX(), nave_pos->GetY()+5, nave_pos->GetZ());
	pp->SetCenter(nave_pos->GetX(), nave_pos->GetY()+10, nave_pos->GetZ());
	pon->SetPosicao(bola->GetPosicao()->GetX(),bola->GetPosicao()->GetY(),bola->GetPosicao()->GetZ()+50);

	int tipo;
	
	Vector3* velocidade = bola->GetVelocidade();
	Vector3* velocidade_tmp = new Vector3();

	tipo = this->Colisao(bola->GetPosicao(), bola->GetVelocidade());
	switch(tipo){
		case 0: //NAO COLIDE
			break;
		case 1: //LEFT OR RIGHT
			velocidade_tmp->Set(-velocidade->GetX(), velocidade->GetY(), velocidade->GetZ());
			bola->SetVelocidade(velocidade_tmp);
			break;
		case 2: //UP OR DOWN
			velocidade_tmp->Set(velocidade->GetX(), -velocidade->GetY(), velocidade->GetZ());
			bola->SetVelocidade(velocidade_tmp);
			if(velocidade_tmp->GetY()<0)
				glEnable(GL_LIGHT5);
			else
				glDisable(GL_LIGHT5);
			break;
		case 3: //CORNER
			velocidade_tmp->Set(-velocidade->GetX(), -velocidade->GetY(), velocidade->GetZ());
			bola->SetVelocidade(velocidade_tmp);
			break;
		case 4: //OUT OF BOUNDS
			bola->stop();
			velocidade_tmp->Set(nave->GetVelocidade()->GetX(),nave->GetVelocidade()->GetY(),nave->GetVelocidade()->GetZ());
			Vector3* nova_pos = new Vector3();
			nova_pos->Set(nave->GetPosicao()->GetX(),nave->GetPosicao()->GetY()+15,nave->GetPosicao()->GetZ());
			bola->SetPosicao(nova_pos);
			lives--;
			glDisable(GL_LIGHT5);
			break;
	}
}

void GestordoJogo::Reinicia(){
	lives = 3;
	points = 0;
	text = false;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 6; j++)
			tijolos[i][j]->Restore();
	
	Vector3* vector01 = new Vector3();
	vector01->Set(0.0,0.0,0.0);
	Vector3* vector02 = new Vector3();
	vector02->Set(0.0,0.0,0.0);

	nave->SetPosicao(0.0, -220.0,0.0);
	nave->SetVelocidade(vector01);
	bola->SetPosicao(0.0,-205.0,0.0);
	bola->SetVelocidade(vector02);

}

void GestordoJogo::Inicializa(){

	C=false;
	L=false;
	lives = 3;
	points = 0;
	text = false;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glEnable(GL_CULL_FACE);


	GLfloat light[] = {0,0,0,1};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light);
	
	//luz global
	Vector3 *specular = new Vector3();
	Vector3 *diffuse = new Vector3();
	Vector3 *ambient = new Vector3();
	Vector3 *direction = new Vector3();
	Vector3 *position = new Vector3();
	specular->Set(0.5,0.5,0.5);
	diffuse->Set(0.4,0.4,0.4);
	ambient->Set(0.3,0.3,0.3);

	direction->Set(0.0, 0.0, -1.0);
	position->Set(0.0, 0.0, 50.0);

	dir = new Direcional();
	dir->Set(ambient, diffuse, specular, direction);
	dir->SetLuz(ambient, diffuse, specular);
	dir->SetPosicao(position);
	//fim luz global

	//candeeiros
	Vector3 *specular2 = new Vector3();
	Vector3 *diffuse2 = new Vector3();
	Vector3 *ambient2 = new Vector3();
	specular2->Set(0.8,0.8,0.8);
	diffuse2->Set(0.7,0.7,0.7);
	ambient2->Set(0.4,0.4,0.4);

	spot1 = new Spot();
	spot2 = new Spot();
	spot3 = new Spot();
	spot4 = new Spot();

	Vector3 *position1 = new Vector3();
	Vector3 *position2 = new Vector3();
	Vector3 *position3 = new Vector3();
	Vector3 *position4 = new Vector3();

	position1->Set(-250.0, -250.0, 100.0);
	position2->Set(-250.0,  250.0, 100.0);
	position3->Set( 250.0, -250.0, 100.0);
	position4->Set( 250.0,  250.0, 100.0);


	spot1->Set(ambient2, diffuse2, specular2, direction, 60, 1);
	spot1->SetPosicao(position1);
	spot2->Set(ambient2, diffuse2, specular2, direction, 60, 1);
	spot2->SetPosicao(position2);
	spot3->Set(ambient2, diffuse2, specular2, direction, 60, 1);
	spot3->SetPosicao(position3);
	spot4->Set(ambient2, diffuse2, specular2, direction, 60, 1);
	spot4->SetPosicao(position4);
	//fim candeeiros

	//point

	pon = new Pontual();

	Vector3 *position5 = new Vector3();
	position5->Set(0.0,-205.0,50.0);
	pon->Set(ambient2, diffuse2, specular2);
	pon->SetPosicao(position5);


	//fim point


	//camaras

	Vector3* nave_pos = new Vector3();
	nave_pos->Set(0.0, -220.0,0.0);

	orto = new Ortogonal();
	persp = new Perspectiva();
	pp = new Perspectiva();

	orto->SetCamera(1.0, -250.0, 250.0, -250.0, 250.0, -250.0, 250.0);
	persp->SetCamera(1.0, 90.0, 10.0, 1000.0);
	persp->SetCenter(nave_pos->GetX(), nave_pos->GetY()-50, nave_pos->GetZ()+100);
	persp->SetEye(nave_pos->GetX(), nave_pos->GetY(), nave_pos->GetZ());
	persp->SetUp(0,0,1);
	pp->SetCamera(1.0, 90.0, 20.0, 1000.0);
	pp->SetCenter(nave_pos->GetX(), nave_pos->GetY()+10, nave_pos->GetZ());
	pp->SetEye(nave_pos->GetX(), nave_pos->GetY()+5, nave_pos->GetZ());
	pp->SetUp(0,0,1);
	actual = orto;

	//fim camaras

	//objectos

	Vector3* vector01 = new Vector3();
	vector01->Set(0.0,0.0,0.0);
	Vector3* vector02 = new Vector3();
	vector02->Set(0.0,0.0,0.0);

	nave = new Nave();
	bola = new Bola();
	parede = new Parede();
	chao = new TerrenoJogo();

	nave->SetPosicao(0.0, -220.0,0.0);
	nave->SetVelocidade(vector01);
	bola->SetPosicao(0.0,-205.0,0.0);
	bola->SetVelocidade(vector02);
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 6; j++){
			tijolos[i][j] = new Tijolo();
			tijolos[i][j]->SetPosicao(-204.0+51*i, 220.0-20*j, 0.0);
			switch(j){
				case 5:
					tijolos[i][j]->SetCor(1.0, 0.0, 0.0);
					break;
				case 4:
					tijolos[i][j]->SetCor(0.0, 0.0, 1.0);
					break;
				case 3:
					tijolos[i][j]->SetCor(0.0, 1.0, 0.0);
					break;
				case 2:
					tijolos[i][j]->SetCor(0.5, 0.5, 0.7);
					break;
				case 1:
					tijolos[i][j]->SetCor(0.9, 0.5, 0.6);
					break;
				case 0:
					tijolos[i][j]->SetCor(0.4, 0.4, 0.4);
					break;
			}
		}

}


int GestordoJogo::Colisao(Vector3* a, Vector3* b){
		float nextX = a->GetX() /*+ b->GetX()*/;
		float nextY = a->GetY() /*+ b->GetY()*/;
		float nextZ = a->GetZ() /*+ b->GetZ()*/;


		if(nextX>230||nextX<-230){
			if(nextY>230)
				return 3;
			return 1;
		}

		if(nextY>230)
			return 2;



		float naveX = nave->GetPosicao()->GetX();
		float naveY = nave->GetPosicao()->GetY();
		//float naveY = nave->GetPosicao()->GetZ();

		if(nextY<naveY+5)
			return 4;

		
		if(((int)nextY < (int) naveY+10)&&((int)nextY > (int) naveY-10))
			if( ( ((int)nextX) < ((int) naveX + 30) ) && ( ((int)nextX) > ((int) naveX - 30) ))
				return 2;
		
		int i=100;
		int j=100;

		if(nextY>112.5&&nextY<130)
			j=5;
		if(nextY>130&&nextY<150)
			j=4;
		if(nextY>150&&nextY<170)
			j=3;
		if(nextY>170&&nextY<190)
			j=2;
		if(nextY>190&&nextY<210)
			j=1;
		if(nextY>210&&nextY<227.5)
			j=0;


		if(nextX>-250.0&&nextX<-178.5)
			i=0;
		if(nextX>-178.5&&nextX<-127.5)
			i=1;
		if(nextX>-127.5&&nextX<-76.5)
			i=2;
		if(nextX>-76.5&&nextX<-25.5)
			i=3;
		if(nextX>-25.5&&nextX<25.5)
			i=4;
		if(nextX>25.5&&nextX<76.5)
			i=5;
		if(nextX>76.5&&nextX<127.5)
			i=6;
		if(nextX>127.5&&nextX<178.5)
			i=7;
		if(nextX>178.5&&nextX<250.0)
			i=8;
		
		if(i!=100&&j!=100&&tijolos[i][j]->Exists()){
			tijolos[i][j]->Destroy();
			points++;
			return 2;
		}

		return 0;
}