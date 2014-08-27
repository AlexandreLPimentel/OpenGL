#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Dinamico.h"
#include "Spot.h"


#ifndef Bola_h
#define Bola_h

class Bola : public Dinamico{

private:
	bool free;
	int myLight;
	Spot* pon;

public:
	Bola();
	void desenha();
	void actualiza();
	void dispara();
	bool isMoving();
	void stop();

};

#endif