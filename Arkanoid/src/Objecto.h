#include "Entidade.h"

#ifndef Objecto_h
#define Objecto_h

class Objecto : public Entidade{
	
	public:
		virtual void desenha() = 0; 
		virtual void actualiza() = 0;
};

#endif