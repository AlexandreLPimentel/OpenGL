#include "TerrenoJogo.h"
#include <stdio.h>

#define DEFINITION 10.0f

TerrenoJogo::TerrenoJogo(){
	LoadTexture("texture.raw");
}


void TerrenoJogo::actualiza(){

}


void TerrenoJogo::DesenhaTelha(int x, int y){        
    const GLfloat chao_a[] = {0.1f, 0.1f, 0.1f, 1.0f};
    const GLfloat chao_d[] = {0.1f, 0.1f, 0.1f, 1.0f};
    const GLfloat chao_s[] = {0.0f, 0.0f, 0.0f, 1.0f};
    const GLfloat shiny    = 0;
    glMaterialfv(GL_FRONT, GL_AMBIENT,  chao_a);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  chao_d);
    glMaterialfv(GL_FRONT, GL_SPECULAR, chao_s);
    glMaterialf (GL_FRONT, GL_SHININESS, shiny);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texture);
    glPushMatrix();
        glBegin(GL_QUADS);
            glNormal3f(0.0, 0.0, 1.0);        // Normal da face
            glTexCoord2f(.1, .1); glVertex3f( 10+x,  10+y, -12.5);
            glTexCoord2f(0., .1); glVertex3f(-10+x,  10+y, -12.5);
            glTexCoord2f(0., 0.); glVertex3f(-10+x, -10+y, -12.5);
            glTexCoord2f(.1, 0.); glVertex3f( 10+x, -10+y, -12.5);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void TerrenoJogo::desenha() {
	ReloadTexture();
    int i, j;
    glColor3f(0.7, 0.7, 0.7);
    for(i = -240; i <= 240; i += 20) {
        for( j= -240; j <= 240; j += 20){
            glPushMatrix();
			DesenhaTelha(i,j);
            glPopMatrix();
        }
    }
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void TerrenoJogo::LoadTexture(const char * filename){

    FILE* file = fopen(filename, "r");
    fread(my_texels, 256*256*4, 1, file);
    // allocates a texture name
    glGenTextures( 1, &texture );
    // selects our current texture
    glBindTexture( GL_TEXTURE_2D, texture );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 256, 256, 0, GL_RGBA, GL_UNSIGNED_BYTE, my_texels);
	fclose(file);
}

void TerrenoJogo::ReloadTexture(){
	glBindTexture( GL_TEXTURE_2D, texture );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 256, 256, 0, GL_RGBA, GL_UNSIGNED_BYTE, my_texels);
}