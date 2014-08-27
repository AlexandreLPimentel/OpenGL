#include "PrimeiraPessoa.h"


void PrimeiraPessoa::CalculaMatrizProjeccao(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80, relacao_aspecto, 0, 500);
}


void PrimeiraPessoa::CalculaMatrizVisualizacao(float relacao_aspecto, int x, int y){
	if (relacao_aspecto > 1)
		gluLookAt(x, y, 20, x, 500, 0, 0, 0, 1);
	else
		gluLookAt(x, y / relacao_aspecto, 20 / relacao_aspecto, x, 400, 0, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}