#include "Camara.h"

#ifndef Perspectiva_h
#define Perspectiva_h


class Perspectiva : public Camara{

private:
	double fov, proximo, distante, x, y ,z;
	
public:
	Perspectiva();
	void CalculaMatrizProjeccao();
	void CalculaMatrizVisualizacao();
	void SetCamera(double relacao_aspecto, double fov, double proximo, double distante);
	void SetEye(double x, double y, double z);
	void actualiza();
	//void SetCenter(double x, double y, double z);
	//void SetUp(double x, double y, double z);

};

#endif