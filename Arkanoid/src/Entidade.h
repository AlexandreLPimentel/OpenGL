#include <stdlib.h>
#include <time.h>
#include "GL/glut.h"
#include "Vector3.h"

#ifndef Entidade_h
#define Entidade_h

class Entidade{

	private:
		Vector3* posicao;
		
    public:
		Entidade();
		virtual void actualiza() = 0;
		Vector3* GetPosicao();
		void SetPosicao(float x, float y, float z);
		void SetPosicao(Vector3* p);
	
};

#endif