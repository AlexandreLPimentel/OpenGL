#include "Camara.h"

#ifndef Ortogonal_h
#define Ortogonal_h

class Ortogonal : public Camara{

    private:
		double esquerda;
		double direita;
		double fundo;
		double top;
		double proximo;
		double distante;
	
	public:
		Ortogonal();
		void SetCamera(double relacao_aspecto, double esquerda, double direita, double fundo, double top, double proximo, double distante);
		void CalculaMatrizProjeccao();
		void CalculaMatrizVisualizacao();
		void actualiza();
};

#endif