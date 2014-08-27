#include <stdlib.h>
#include "GL\glut.h"
#include "GestordoJogo.h"

GestordoJogo* jogo;
GLsizei w2, h2;

void myReshape(GLsizei w, GLsizei h) {
	jogo->TrataEventoReshape(w,h);
}

void myDisplay() {
	jogo->TrataEventoDisplay();
}

void myTimer(int value){
	jogo->TrataEventoTimer();
    glutTimerFunc(33, myTimer, 1);

}

void normalKeyboard(unsigned char key, int x, int y){
	jogo->TrataEventoKeyPressed(key,x,y);
}

void specialKeyboard(int key, int x, int y){
	if(key==GLUT_KEY_LEFT)
		jogo->TrataEventoKeyPressed(LEFT,x,y);
	if(key==GLUT_KEY_RIGHT)
		jogo->TrataEventoKeyPressed(RIGHT,x,y);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	jogo = new GestordoJogo;
	jogo->Inicializa();
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (-1, -1);
	glutCreateWindow("Arkanoid");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutTimerFunc(33, myTimer , 1);
	glutSpecialFunc(specialKeyboard);
	glutKeyboardFunc(normalKeyboard);
	glutMainLoop();
}