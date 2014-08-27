#include "Estatico.h"

#ifndef TerrenoJogo_h
#define TerrenoJogo_h

class TerrenoJogo : public Estatico{
private:
	GLubyte my_texels[256][256][4];
	GLuint texture;
public:
	TerrenoJogo();
	void desenha();
	void actualiza();
	void DesenhaTelha(int x, int y);
	void LoadTexture(const char * filename);
	void ReloadTexture();
};

#endif