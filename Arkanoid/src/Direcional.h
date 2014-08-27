#include "FonteLuz.h"

#ifndef Direcional_h
#define Direcional_h


class Direcional : public FonteLuz{
	private:
		Vector3* direccao;
	public:
		Direcional();
		void Set(Vector3* ambiente, Vector3* difusa, Vector3* especular, Vector3* direccao);
		void Define(int n);
};

#endif