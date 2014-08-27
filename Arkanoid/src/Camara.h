#include "Entidade.h"

#ifndef Camara_h
#define Camara_h

class Camara : public Entidade{

	protected:
		Vector3* center;
		Vector3* up;
		double relacao_aspecto;
	
	public:
		Camara();
		virtual void CalculaMatrizProjeccao() = 0;
		virtual void CalculaMatrizVisualizacao() = 0;
		void SetAspect(double relacao_aspecto);
		virtual void actualiza() = 0;
		void SetCenter(double x, double y, double z);
		void SetUp(double x, double y, double z);
};
#endif