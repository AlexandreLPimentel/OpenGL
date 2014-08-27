#include "Estatico.h"

#ifndef Tijolo_h
#define Tijolo_h

class Tijolo : public Estatico{

private:
	float r, g, b;
	bool exists;

public:
	Tijolo();
	void desenha();
	void actualiza();
	void SetCor(float r, float g, float b);
	bool Exists();
	void Destroy();
	void Restore();
};

#endif