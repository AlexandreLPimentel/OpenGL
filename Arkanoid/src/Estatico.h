#include "Objecto.h"

#ifndef Estatico_h
#define Estatico_h

class Estatico : public Objecto{

public:
	Estatico();
	virtual void desenha() = 0;
	virtual void actualiza() = 0;
	
};

#endif