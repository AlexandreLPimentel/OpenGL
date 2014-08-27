#include "stdafx.h"
#include "Proj.h"
#include "CameraPerspective.h"
#include "CameraOrtho.h"

void ghostTimerBlack(int value);

int ghostTime = 40;
extern bool power;
GLfloat x, y;

void myReshape(GLsizei w, GLsizei h) {
    GLfloat aspect = (GLfloat)w/(GLfloat)h;
    glViewport(0, 0, w, h);
	camera->changeAspect(aspect);
	x=w/2;
	y=h/2;
}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	camera->drawText(maze->score, pac->lives, cameraVector[0]);
    camera->update();
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	maze->desenha_maze();
	pac->draw();
	blinky->draw();
	pinky->draw();
	inky->draw();
	clyde->draw();
	glutSwapBuffers(); 
}

void myTimer(int value){
	pac->move();
	glutPostRedisplay();
    glutTimerFunc(40, myTimer, 1);
}

void ghostTimerWhite(int value){
    blinky->move();
	pinky->move();
	inky->move();
	clyde->move();
	glutPostRedisplay();
    if(maze->power) glutTimerFunc(60, ghostTimerWhite, 1);
    else glutTimerFunc(40, ghostTimerBlack, 1);
}

void ghostTimerBlack(int value){
    blinky->move();
	pinky->move();
	inky->move();
	clyde->move();
	glutPostRedisplay();
    if(maze->power) glutTimerFunc(60, ghostTimerWhite, 1);
    else glutTimerFunc(40, ghostTimerBlack, 1);
}

void normalKeyboard(unsigned char key, int x, int y){
	if( ('0'<key) && (key<'3') )
		camera = cameraVector[key-'1'];
    else if (key == '0'){
        glDisable(GL_LIGHT1);
        GLfloat blabla[] = {0,0,0,1};
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, blabla);
        glEnable(GL_LIGHT0);
		//camera->lightInUse=GL_LIGHT0;
    }else if (key == '9'){
        glDisable(GL_LIGHT0);
        GLfloat blabla[] = {0.1,0.1,0.1,1};
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, blabla);
        glEnable(GL_LIGHT1);
		//camera->lightInUse=GL_LIGHT1;
    }
}


void specialKeyboard(int key, int x, int y){
	pac->receiveKey(key);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (300, 100); 
    glutCreateWindow("Pacman"); 
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
    GLfloat blabla[] = {0,0,0,1};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, blabla);
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(myReshape);
	glutTimerFunc(33, myTimer, 1);
    glutTimerFunc(ghostTime, ghostTimerBlack, 1);
    glutSpecialFunc(specialKeyboard);
	glutKeyboardFunc(normalKeyboard);
    maze = new Maze();
    cameraVector = new Camera*[2];
    cameraVector[0] = new CameraOrtho(0,28,31,0,-2,2);
    cameraVector[1] = new CameraPerspective(1, 1, 41, 0, 0, 14, 14);
    pac = new Pacman(14.0, 23.0, maze, GLUT_KEY_UP, GLUT_KEY_DOWN, GLUT_KEY_LEFT, GLUT_KEY_RIGHT, cameraVector[1]);
    //Falta algo
    camera = cameraVector[0];
    //Falta algo
	blinky = new Ghost(13, 11, maze, pac, 31, 28, 1.0f, 0.0f, 0.0f);
	pinky = new Ghost(13, 13, maze, pac, 31, 28, 1.0f, 0.5f, 0.8f);
	inky = new Ghost(11, 13, maze, pac, 31, 28, 0.0f, 1.0f, 0.8f);
	clyde = new Ghost(15, 13, maze, pac, 31, 28, 1.0f, 0.5f, 0.2f);
    glutMainLoop();
}