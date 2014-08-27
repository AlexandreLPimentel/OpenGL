#include "Perspectiva.h"


struct PrimeiraPessoa : public Camara{

private:
	int x, int y;
public:
	void CalculaMatrizProjeccao();
	void CalculaMatrizVisualizacao();

};
