#include <time.h>
#include <stdlib.h>
#include "GL\glut.h"
#include "Entidade.h"
#include "Camara.h"
#include "Ortogonal.h"
#include "Perspectiva.h"
#include "FonteLuz.h"
#include "Direcional.h"
#include "Spot.h"
#include "Pontual.h"
#include "Nave.h"
#include "Bola.h"
#include "Parede.h"
#include "Tijolo.h"
#include "TerrenoJogo.h"
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#define LEFT 'a'
#define RIGHT 'd'

#ifndef GestordoJogo_h
#define GestordoJogo_h

class GestordoJogo{

	private:
		int lives, points;
		bool text;
		bool C, L;
		Direcional* dir;
		Spot* spot1, *spot2, *spot3, *spot4;
		Pontual* pon;
		Ortogonal* orto;
		Perspectiva* persp, *pp, *pp2;
		Camara* actual;
		Nave* nave;
		Bola* bola;
		Parede* parede;
		Tijolo* tijolo;
		TerrenoJogo* chao;
		Vector3* vector0;
		unsigned char lastKey;
		Tijolo* tijolos[9][6];
		int Colisao(Vector3* a, Vector3* b);
		bool desenhaNave;

    public:
		void TrataEventoDisplay();
		void TrataEventoReshape(GLsizei w, GLsizei h);
		void TrataEventoKeyPressed(unsigned char tecla, int x, int y);
		void TrataEventoTimer();
		void TrataEventoIdle();
		void Actualiza();
		void Inicializa();
		void Reinicia();
		GLuint LoadTextureRAW(const char * filename, int wrap);
};

#endif