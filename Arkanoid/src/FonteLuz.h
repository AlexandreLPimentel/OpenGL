#include "Entidade.h"

#ifndef FonteLuz_h
#define FonteLuz_h


class FonteLuz : public Entidade{

	private:
		Vector3* ambiente;
		Vector3* difusa;
		Vector3* especular;
		bool ligada;
		int n;
	
	protected:
		int GetN();

	public:
		void DefineLuz(int n);
		
		FonteLuz();
		void SetLuz(Vector3* ambiente, Vector3* difusa, Vector3* especular);
		void SetEstado(bool estado);
		bool GetEstado();
		virtual void Define(int n) = 0;
		void actualiza();

};

#endif
