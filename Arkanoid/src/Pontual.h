#include "FonteLuz.h"

#ifndef Pontual_h
#define Pontual_h


class Pontual : public FonteLuz{
	private:
		GLfloat distancia;
	public:
		Pontual();
		void Set(Vector3* ambiente, Vector3* difusa, Vector3* especular);
		void Define(int n);
};

#endif