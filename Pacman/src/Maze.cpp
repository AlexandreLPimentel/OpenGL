#include "stdafx.h"
#include "Maze.h"
#include "Ghost.h"
#include <stdio.h>

int powersnumber = 0;
FILE *file = NULL;
extern Maze* maze;

Maze::Maze()
{
	int tmp[31][28] =
		{11, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,13,11, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,13,
		  9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,10, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,10,
		  9, 1, 6, 7, 7, 4, 1, 6, 7, 7, 7, 4, 1,10, 9, 1, 6, 7, 7, 7, 4, 1, 6, 7, 7, 4, 1,10,
		  9, 2,10,15,15, 9, 1,10,15,15,15, 9, 1,10, 9, 1,10,15,15,15, 9, 1,10,15,15, 9, 2,10,
		  9, 1, 5, 8, 8, 3, 1, 5, 8, 8, 8, 3, 1, 5, 3, 1, 5, 8, 8, 8, 3, 1, 5, 8, 8, 3, 1,10,
		  9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,10,
		  9, 1, 6, 7, 7, 4, 1, 6, 4, 1, 6, 7, 7, 7, 7, 7, 7, 4, 1, 6, 4, 1, 6, 7, 7, 4, 1,10,
		  9, 1, 5, 8, 8, 3, 1,10, 9, 1, 5, 8, 8,13,11, 8, 8, 3, 1,10, 9, 1, 5, 8, 8, 3, 1,10,
		  9, 1, 1, 1, 1, 1, 1,10, 9, 1, 1, 1, 1,10, 9, 1, 1, 1, 1,10, 9, 1, 1, 1, 1, 1, 1,10,
		 12, 7, 7, 7, 7, 4, 1,10,12, 7, 7, 4, 0,10, 9, 0, 6, 7, 7,14, 9, 1, 6, 7, 7, 7, 7,14,
		 15,15,15,15,15, 9, 1,10,11, 8, 8, 3, 0, 5, 3, 0, 5, 8, 8,13, 9, 1,10,15,15,15,15,15,
		 15,15,15,15,15, 9, 1,10, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10, 9, 1,10,15,15,15,15,15,
		 15,15,15,15,15, 9, 1,10, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10, 9, 1,10,15,15,15,15,15,
		 15,15,15,15,15, 9, 1, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 3, 1,10,15,15,15,15,15,
		 15,15,15,15,15, 9, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,10,15,15,15,15,15,
		 15,15,15,15,15, 9, 1, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 4, 1,10,15,15,15,15,15,
		 15,15,15,15,15, 9, 1,10, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10, 9, 1,10,15,15,15,15,15,
		 15,15,15,15,15, 9, 1,10, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10, 9, 1,10,15,15,15,15,15,
		 15,15,15,15,15, 9, 1,10, 9, 0, 6, 7, 7, 7, 7, 7, 7, 4, 0,10, 9, 1,10,15,15,15,15,15,
		 11, 8, 8, 8, 8, 3, 1, 5, 3, 0, 5, 8, 8,13,11, 8, 8, 3, 0, 5, 3, 1, 5, 8, 8, 8, 8,13,
		  9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,10, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,10,
		  9, 1, 6, 7, 7, 4, 1, 6, 7, 7, 7, 4, 1,10, 9, 1, 6, 7, 7, 7, 4, 1, 6, 7, 7, 4, 1,10,
		  9, 2, 5, 8,13, 9, 1, 5, 8, 8, 8, 3, 1, 5, 3, 1, 5, 8, 8, 8, 3, 1,10,11, 8, 3, 2,10, 
		  9, 1, 1, 1,10, 9, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1,10, 9, 1, 1, 1,10,
		 12, 7, 4, 1,10, 9, 1, 6, 4, 1, 6, 7, 7, 7, 7, 7, 7, 4, 1, 6, 4, 1,10, 9, 1, 6, 7,14,
		 11, 8, 3, 1, 5, 3, 1,10, 9, 1, 5, 8, 8,13,11, 8, 8, 3, 1,10, 9, 1, 5, 3, 1, 5, 8,13,
		  9, 1, 1, 1, 1, 1, 1,10, 9, 1, 1, 1, 1,10, 9, 1, 1, 1, 1,10, 9, 1, 1, 1, 1, 1, 1,10,
		  9, 1, 6, 7, 7, 7, 7,14,12, 7, 7, 4, 1,10, 9, 1, 6, 7, 7,14,12, 7, 7, 7, 7, 4, 1,10,
		  9, 1, 5, 8, 8, 8, 8, 8, 8, 8, 8, 3, 1, 5, 3, 1, 5, 8, 8, 8, 8, 8, 8, 8, 8, 3, 1,10,
		  9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,10,
		 12, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,14};
	for(int i=0;i<28;i++) for(int j=0;j<31;j++) maze[j][i]=tmp[j][i];
    score = 0;
	loadText();
}


bool Maze::colisao(int x, int y){
	return (maze[y][x]>2);
}

void Maze::desenha_maze(void){
	
    //TEST MODE
	GLfloat mat_ambdif[] = { 0.0, 0.0, 0.7, 0.0 };
    GLfloat mat_specular[] = { 0.0, 0.0, 0.7, 0.0 };
    GLfloat mat_shininess[] = { 0.0 };
    float normal[] = {0, 0, 1};
    //END

	for(int i=0;i<28;i++){
		for(int j=0;j<31;j++){
			int a = maze[j][i];
			glPushMatrix();
			glTranslatef(i, j, 0);
			desenhaChao();
			switch(a){
				case 1:
                    //TEST MODE
                    mat_ambdif[0] = 1.0;
                    mat_ambdif[1] = 0.8;
                    mat_ambdif[2] = 0.0;
					mat_shininess[0] = 50.0;
                    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_specular);
					mat_specular[0] = 1.0;
                    mat_specular[1] = 0.8;
                    mat_specular[2] = 0.0;
					glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
                    glMaterialf(GL_FRONT, GL_SHININESS, 0.6);
                    //END
					glTranslatef(0.5,0.5,0);
					glutSolidSphere(0.2,10,10);
					break;
				case 2:
                    //TEST MODE
					mat_ambdif[0] = 1.0;
                    mat_ambdif[1] = 1.0;
                    mat_ambdif[2] = 1.0;
					mat_shininess[0] = 50.0;
                    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_specular);
                    mat_specular[0] = 1.0;
                    mat_specular[1] = 1.0;
                    mat_specular[2] = 1.0;
                    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_specular);
                    glMaterialf(GL_FRONT, GL_SHININESS, 0.6);
                    //END
					glTranslatef(0.5,0.5,0);
					glutSolidSphere(0.4,50,50);
					break;
				case 3:
					desenhaCubo(0.25,0.25,0,0.5,0,0,0.7);
					break;
				case 4:
					desenhaCubo(0.25,0.75,0,0.5,0,0,0.7);
					break;
				case 5:
					desenhaCubo(0.75,0.25,0,0.5,0,0,0.7);
					break;
				case 7:
					desenhaCubo(0.25,0.75,0,0.5,0,0,0.7);
				case 6:
					desenhaCubo(0.75,0.75,0,0.5,0,0,0.7);
					break;
				case 8:
					desenhaCubo(0.25,0.25,0,0.5,0,0,0.7);
					desenhaCubo(0.75,0.25,0,0.5,0,0,0.7);
					break;
				case 9:
					desenhaCubo(0.25,0.25,0,0.5,0,0,0.7);
					desenhaCubo(0.25,0.75,0,0.5,0,0,0.7);
					break;
				case 10:
					desenhaCubo(0.75,0.25,0,0.5,0,0,0.7);
					desenhaCubo(0.75,0.75,0,0.5,0,0,0.7);
					break;
				case 11:
					desenhaCubo(0.25,0.25,0,0.5,0,0,0.7);
					desenhaCubo(0.25,0.75,0,0.5,0,0,0.7);
					desenhaCubo(0.75,0.25,0,0.5,0,0,0.7);
					break;
				case 12:
					desenhaCubo(0.25,0.25,0,0.5,0,0,0.7);
					desenhaCubo(0.25,0.75,0,0.5,0,0,0.7);
					desenhaCubo(0.75,0.75,0,0.5,0,0,0.7);
					break;
				case 13:
					desenhaCubo(0.25,0.25,0,0.5,0,0,0.7);
					desenhaCubo(0.75,0.25,0,0.5,0,0,0.7);
					desenhaCubo(0.75,0.75,0,0.5,0,0,0.7);
					break;
				case 14:
					desenhaCubo(0.25,0.75,0,0.5,0,0,0.7);
					desenhaCubo(0.75,0.25,0,0.5,0,0,0.7);
					desenhaCubo(0.75,0.75,0,0.5,0,0,0.7);
					break;
				case 15:
					desenhaCubo(0.5,0.5,0,1,0,0,0.7);
					break;
				case 16:
					desenhaCubo(0.25,0.75,0,0.5,1.0,0.5,0.9);
					desenhaCubo(0.75,0.75,0,0.5,1.0,0.5,0.9);
				default:
					break;
			}
			glPopMatrix();
		}
	}
}

void Maze::desenhaCubo(GLfloat x, GLfloat y, GLfloat z, GLfloat size, GLfloat red, GLfloat green, GLfloat blue){
	glPushMatrix();
    //TEST MODE
    GLfloat mat_ambdif[] = { red, green, blue, 0.0 };
	GLfloat mat_specular[] = { 0, 0, 0, 0.0 };
    GLfloat mat_shininess[] = { 0.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_ambdif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    //END
	glTranslatef(x,y,z);
	glScalef(1,1,1/size);
	glutSolidCube(size);
	glPopMatrix();
}

void Maze::loadText(){
	char* filename = "ground_texture.raw";
	text = LoadTextureRAW(filename, true);
}

void Maze::desenhaChao(){
	
	
	glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	
	GLfloat mat_dif[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat mat_amb[] = {0.5f, 0.5f, 0.5f, 1.0f};
	GLfloat mat_shininess[] = { 0.0 };
	GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 0.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	
	glBindTexture( GL_TEXTURE_2D, text);
	GLfloat normal[] = {0,0,1};
	glBegin(GL_QUADS);
		glNormal3fv(normal);
		glTexCoord2d(0.5, -0.5); glVertex3f(0.0, 0.0, -0.5);
		glTexCoord2d(1.5, -0.5); glVertex3f(1.0, 0.0, -0.5);
		glTexCoord2d(1.5, 1.5); glVertex3f(1.0, 1.0, -0.5);
		glTexCoord2d(-0.5, 1.5); glVertex3f(0.0, 1.0, -0.5);
	glEnd();

	glDisable(GL_TEXTURE_2D);


	glPopMatrix();


	/*
	//GLfloat mat_ambdif[] = { 0.0, 0.0, 0.3, 0.0 };
	//GLfloat mat_shininess[] = { 0.0 };
	//GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 0.0 };
	glPushMatrix();
	//glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_ambdif);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glBindTexture(GL_TEXTURE_2D, texture);

	 // select modulate to mix texture with color for shading
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

    // when texture area is small, bilinear filter the closest mipmap
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                     GL_LINEAR_MIPMAP_NEAREST );
    // when texture area is large, bilinear filter the first mipmap
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    // if wrap is true, the texture wraps over at the edges (repeat)
    //       ... false, the texture ends at the edges (clamp)
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                     wrap ? GL_REPEAT : GL_CLAMP );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
                     wrap ? GL_REPEAT : GL_CLAMP );

    // build our texture mipmaps
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,
                       GL_RGB, GL_UNSIGNED_BYTE, data );

    // free buffer
    free( data );

	glBegin(GL_QUADS);
		glNormal3fv(normal);
		glTexCoord2d(-0.5, -0.5); glVertex3f(-0.5, -0.5, -0.5);
		glTexCoord2d(1.5, -0.5);glVertex3f(1.5, -0.5, -0.5);
		glTexCoord2d(1.5, 1.5);glVertex3f(1.5, 1.5, -0.5);
		glTexCoord2d(-0.5, 1.5);glVertex3f(-0.5, 1.5, -0.5);
	glEnd();
	glPopMatrix();*/
}

void powerDown(int value){    //Poem os fantasmas normais outra vez
	if(value != powersnumber) return;
    blinky->red = 1.0;
    blinky->green = 0.0;
    blinky->blue = 0.0;
    blinky->power = false;
    
    pinky->red = 1.0;
    pinky->green = 0.5;
    pinky->blue = 0.8;
    pinky->power = false;
    
    inky->red = 0.0;
    inky->green = 1.0;
    inky->blue = 0.8;
    inky->power = false;
    
    clyde->red = 1.0;
    clyde->green = 0.5;
    clyde->blue = 0.2;
    clyde->power = false;
    
    maze->power = false;
}

bool Maze::give_pos_pac(int x, int y){
	if(maze[y][x]==1){
		score++;
		if(score==240) exit(0);
	}
	
	if(maze[y][x]==2){
        blinky->red = 1.0;
        blinky->green = 1.0;
        blinky->blue = 1.0;
        blinky->power = true;
        
        pinky->red = 1.0;
        pinky->green = 1.0;
        pinky->blue = 1.0;
        pinky->power = true;
        
        inky->red = 1.0;
        inky->green = 1.0;
        inky->blue = 1.0;
        inky->power = true;
        
        clyde->red = 1.0;
        clyde->green = 1.0;
        clyde->blue = 1.0;
        clyde->power = true;
        power = true;
        
        glutTimerFunc(10000, powerDown, ++powersnumber); //Chama em 10 segundos essa função.
    }

    if((maze[y][x]==1)||(maze[y][x]==2)) maze[y][x]=0;
	return power;
}

// load a 16x16 RGB .RAW file as a texture
GLuint Maze::LoadTextureRAW( const char * filename, int wrap )
{
    GLuint texture;
    int width, height;
    char*  data;
    FILE * file;

    // open texture data
    file = fopen( filename, "rb" );
    if ( file == NULL ) return 0;

    // allocate buffer
    width = 16;
    height = 16;
    data = (char*)malloc( width * height * 3 );

    // read texture data
    fread( data, width * height * 3, 1, file );
    fclose( file );

    // allocate a texture name
    glGenTextures( 1, &texture );

    // select our current texture
    glBindTexture( GL_TEXTURE_2D, texture );

    // select modulate to mix texture with color for shading
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

    // when texture area is small, bilinear filter the closest mipmap
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                     GL_LINEAR_MIPMAP_NEAREST );
    // when texture area is large, bilinear filter the first mipmap
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    // if wrap is true, the texture wraps over at the edges (repeat)
    //       ... false, the texture ends at the edges (clamp)
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                     wrap ? GL_REPEAT : GL_CLAMP );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
                     wrap ? GL_REPEAT : GL_CLAMP );

    // build our texture mipmaps
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,
                       GL_RGB, GL_UNSIGNED_BYTE, data );

    // free buffer
    free( data );

    return texture;
}