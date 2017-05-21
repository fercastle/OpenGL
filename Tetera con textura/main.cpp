#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <SOIL/SOIL.h> //Libreria para funsiones de textura
using namespace std;
GLuint textura[0];//donde guardamos la textura
float cZ=2.0;//posicion de la camara eje Z

float rotateX, rotateY;  // variables para rotación con teclas especiales 
void display() {
       // LLamada a función dibujo 
    glClearColor(0.0, 0.0, 0.0, 0.0);
    //GLfloat light_position [] = { 1.0, 1.0, 1.0, 0.0 };
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
    glLoadIdentity();
    //Posicion de la camara
    gluLookAt (0.0, 2.0,cZ , 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    //Rotacion
    glRotatef(rotateY,0,1,0);
    glRotatef(rotateX,1,0,0);
    // Funcion Para Cargar la Imagen
      textura[0] = SOIL_load_OGL_texture 
    (
        "textura.jpg",//Nombre de la Imagen
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
     //se habilitan las funciones para la autogeneracion de cooredenas esfericas
  glEnable(GL_TEXTURE_2D);
   glEnable(GL_TEXTURE_GEN_S);
   glEnable(GL_TEXTURE_GEN_T);
   glEnable(GL_TEXTURE_GEN_R);

    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, textura[0]);
    //glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glutSolidTeapot(1.0);
    glFlush ();
    glutSwapBuffers();    
}

void special(int key, int x, int y) {
       // control de teclas especiales 
    if ( key == GLUT_KEY_LEFT )
       rotateY -= 15;
    else if ( key == GLUT_KEY_RIGHT )
       rotateY += 15;
    else if ( key == GLUT_KEY_DOWN)
       rotateX += 15;
    else if ( key == GLUT_KEY_UP )
       rotateX -= 15;
    else if ( key == GLUT_KEY_HOME )
       rotateX = rotateY = 0;
    glutPostRedisplay();
}
//Funsion Reshape
  void reshape (int w, int h)
{
glViewport (0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode (GL_PROJECTION);
glLoadIdentity ();
glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 60.0);
glMatrixMode(GL_MODELVIEW);
}
void init()
{
glGenTextures (0, textura);
// textura 
glBindTexture (GL_TEXTURE_2D, textura[0]);
//filtrado
glTexParameteri (GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
//funcione que autogeneran las coordenadas esfericas
glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
}
// —------------------—  Funcion principal —----------------
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL Tetera con texxtura");
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(special);
    glEnable(GL_DEPTH_TEST);
    rotateX = rotateY = 0;
    // Activar iluminación 
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glutMainLoop();
    return 0;
}
