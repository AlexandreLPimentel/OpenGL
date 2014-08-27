#include "Entidade.h"


Entidade::Entidade(){
	posicao = new Vector3();

}

Vector3* Entidade::GetPosicao(){
	return posicao;
}

void Entidade::SetPosicao(float x, float y, float z){
	posicao->Set(x, y, z);
}

void Entidade::SetPosicao(Vector3* p){
	posicao = p;
}