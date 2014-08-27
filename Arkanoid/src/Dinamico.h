#include <stdlib.h>
#include <time.h>
#include "Objecto.h"

#ifndef Dinamico_h
#define Dinamico_h

class Dinamico : public Objecto{
	
	private:
		Vector3* velocidade;
	public:
		Dinamico();
		virtual void desenha() = 0; 
		virtual void actualiza() = 0;
		void SetVelocidade(Vector3* velocidade);
		Vector3* GetVelocidade();
};

#endif