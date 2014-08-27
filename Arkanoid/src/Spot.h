#include "FonteLuz.h"

#ifndef Spot_h
#define Spot_h


class Spot : public FonteLuz{
	private:
		Vector3* direccao;
		GLfloat cut_off;
		GLfloat expoente;
	public:
		Spot();
		void Set(Vector3* ambiente, Vector3* difusa, Vector3* especular, Vector3* direccao, GLfloat cut_off, GLfloat expoente);
		void Define(int n);
};

#endif