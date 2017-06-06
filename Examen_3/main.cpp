//Luis Fernando Hernandez Castillo
//Librerias de OpenGL
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static void init(void)
{
   //Posicion de la Luz
   GLfloat position[] = { 0.0, 1.0, 0.0, 10.0 };
   //Activando la Iluminacion
   glEnable(GL_DEPTH_TEST);
   glLightfv(GL_LIGHT0, GL_POSITION, position);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
}
//Funcion para establecer la sombra
void sombra (){
   glEnable (GL_BLEND);
   glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glShadeModel (GL_FLAT);
  glClearColor (1.0, 1.0, 1.0, 1.0);
    glColor4f(0.0,0.0,0.0,1.0);
   }
void display(void)
{
	//Definiendo los Materiales
	GLfloat mat_ambient[] = { 0.19225, 0.19225, 0.19225 };
	GLfloat mat_diffuse[] = { 0.50754, 0.50754, 0.50754  };
	GLfloat mat_specular[] = { 0.508273, 0.508273, 0.508273};
	GLfloat shine[] = {29.8974f};
   //  Borrar pantalla y Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     glLoadIdentity();
   //Posicion y vista de la camara
    gluLookAt (0, 7,8.0 , 0, 0, 0, 0.0, 1.0, 0.0);
    //Colocando los Materiales
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, shine);
   //Dibujando La Base Donde Estaran las Figuras Solidas
   glPushMatrix();
   glTranslatef (0, -1, 0);
   glScalef(12.0,0.5,10.0);
   glNormal3f(0,1,0);
   glutSolidCube(1);
   glPopMatrix();
   //Dibujando Cubo
   glPushMatrix();
   glTranslatef (-3, 1.50, -3);
   glutSolidCube (1.75);
   glPopMatrix();
    //Dibujando Tetera
   glPushMatrix();
   glTranslatef (0, 1.50, 3);
   glRotatef(-45,0,1,0);
   glutSolidTeapot (1);
   glPopMatrix();
   //Dibujando Torus
   glPushMatrix();
   glTranslatef (-3, 1.50, 3);
   glutSolidTorus (0.5,0.65,20,20);
   glPopMatrix();
   //Dibujando Esfera
   glPushMatrix();
   glTranslatef (3, 1.50, 3);
   glutSolidSphere (1,20,20);
   glPopMatrix();
   //Dibujando Icosahedro
   glPushMatrix();
   glTranslatef (0, 1.50, 0);
   glutSolidIcosahedron ();
   glPopMatrix();
   //Dibujando Octahedro
   glPushMatrix();
   glTranslatef (-3, 1.50, -0);
   glutSolidOctahedron ();
   glPopMatrix();
   //Dibujando Tetrahedro
   glPushMatrix();
   glTranslatef (3, 1.50, -3);
   glScalef(1.5,1.5,1.5);
   glRotatef(-20,0,0,1);
   glutSolidTetrahedron ();
   glPopMatrix();
   //Dibujando Dodecahedro
   glPushMatrix();
   glTranslatef (0, 1.50, -3);
   glRotatef(-90,0,1,0);
   glRotatef(-180,1,0,0);
   glRotatef(45,1,0,0);
   glScalef(0.9,0.9,0.9);
   glutSolidDodecahedron ();
   glPopMatrix();
   //Dibujando Cono
   glPushMatrix();
   glTranslatef (3, 1.50, 0);
   glRotatef(-90,1,0,0);
   glutSolidCone (1, 1.5,20,20);
   glPopMatrix();
   //Desactivando materiales
     glDisable(GL_LIGHTING);
   glDisable(GL_LIGHT0);
   //Colocando las sombras
   sombra();
   //sombra de el cubo
    glPushMatrix();
   glTranslatef (-3, 0.0, -3);
   glScalef(0.875,0.1,0.875);
   glutSolidCube (1.75);
   glPopMatrix();
   //sombra de la tetera
   glPushMatrix();
   glTranslatef (0, 0, 3);
   glRotatef(-45,0,1,0);
   glScalef(1,0.1,1);
   glutSolidTeapot (1);
   glPopMatrix();
    //Sombra de Torus
   glPushMatrix();
   glTranslatef (-3, 0.0, 3);
   glScalef(1.0,0.1,0.5);
   glutSolidTorus (0.5,0.65,20,20);
   glPopMatrix();
      //Sombra de Esfera
   glPushMatrix();
   glTranslatef (3, 0.0, 3);
   glScalef(1.0,0.1,1);
   glutSolidSphere (1,20,20);
   glPopMatrix();
   //Sombras Icosahedro
   glPushMatrix();
   glTranslatef (0, 0, 0);
    glScalef(1.0,0.1,1);
   glutSolidIcosahedron ();
   glPopMatrix();
    //Sombra de Octahedro
   glPushMatrix();
   glTranslatef (-3, 0.0, -0);
   glScalef(1.0,0.1,1);
   glutSolidOctahedron ();
   glPopMatrix();
   //Sombra de Tetrahedro
   glPushMatrix();
   glTranslatef (3, 0.0, -3);
   glScalef(1.5,0.1,1.5);
   glRotatef(-20,0,0,1);
   glutSolidTetrahedron ();
   glPopMatrix();
   //Sombra de Dodecahedro
   glPushMatrix();
   glTranslatef (0, 0.0, -3);
   glRotatef(-90,0,1,0);
   glRotatef(-180,1,0,0);
   glRotatef(45,1,0,0);
   glScalef(0.9,0.1,0.9);
   glutSolidDodecahedron ();
   glPopMatrix();
     //Sombra de Cono
   glPushMatrix();
   glTranslatef (3, 0.0, 0);
      glScalef(1,0.1,1);
   glRotatef(-90,1,0,0);
   glutSolidCone (1, 1.5,20,20);
   glPopMatrix();
   glFlush();
   glutSwapBuffers();
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
//Funcion main
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(500, 500);
   glutCreateWindow("Figuras Solidas");
   glEnable(GL_DEPTH_TEST);
   init();
   glutReshapeFunc (reshape);
   glutDisplayFunc (display);
   glutMainLoop();
   return 0;
}
