// Modificado Creado Por Luis Fernando Hernandez Castillo Carnet: Hc-12012
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
float x,y,z,y1;
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;
float amb1,amb2,amb3,dif1,dif2,dif3,spe1,spe2,spe3;
void Cubo(float x, float y, float z, float y1){
    //// Primera cara, se identica por multiples colores
    glBegin(GL_POLYGON);

    glVertex3f(  -x, y, z );      // V1 Blanco
    glVertex3f(  x,  y, z );      // V2 Amarillo
    glVertex3f(x, y1,  z );
    glVertex3f(-x, y1, z );
    glEnd();

    //// LADO TRASERO: lado blanco
    glBegin(GL_POLYGON);
    glVertex3f( -x, y, -z );
    glVertex3f( x,  y, -z );
    glVertex3f(x,  y1, -z );
    glVertex3f(-x, y1, -z );
    glEnd();

    //// LADO DERECHO: lado verde
    glBegin(GL_POLYGON);
    glVertex3f(x, y, z );
    glVertex3f(x,  y, -z );
    glVertex3f(x,  y1,  -z );
    glVertex3f(x, y1,  z );
    glEnd();

    //// LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    glVertex3f(-x, y,  -z );
    glVertex3f(-x,  y,  z );
    glVertex3f(-x,  y1, z );
    glVertex3f(-x, y1, -z );
    glEnd();

    //// LADO SUPERIOR: lado azul
    glBegin(GL_POLYGON);
    glVertex3f(-x,  y,  -z );
    glVertex3f(x,  y, -z );
    glVertex3f(x,  y, z );
    glVertex3f(-x,  y,  z );
    glEnd();

    // LADO INFERIOR: lado rojo
    glBegin(GL_POLYGON);
    glVertex3f(-x, y1, -z );
    glVertex3f(x, y1,-z );
    glVertex3f(x, y1,  z );
    glVertex3f(-x, y1, z );
    glEnd();
    }
 //declarando variables para los materiales 
float ambiente1, ambiente2, ambiente3, diffuse1, diffuse2, diffuse3, specular1, specular2, specular3, shine;
void material(float ambiente1, float ambiente2, float ambiente3, float diffuse1, float diffuse2, float diffuse3, float specular1, float specular2, float specular3, float shine){
 // Propiedades del material
 GLfloat mat_ambient_color[] = {ambiente1, ambiente2, ambiente3}; 
    GLfloat mat_diffuseColor[] = {diffuse1, diffuse2, diffuse3}; 
    
    GLfloat mat_specularColor[] = {specular1, specular2, specular3};
    GLfloat mat_shininess[] = {shine};
    
   // Establecer el material actual  
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuseColor);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specularColor);
     glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess); 
     
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    GLfloat light_position[] = { 0.1, -0.5, 0.1, 12.0 };  
    

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
     glShadeModel(GL_SMOOTH);
     
     
       // Activamos la fuente de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST); 
 
    }

void display()
{
    //  Borrar pantalla y Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    // Resetear transformaciones
    glLoadIdentity();
      gluLookAt(-0.2,-0.15,0.2, //punto de vista en el eje X,Y,Z
              0.0,0.0,0.0, //Centro del Objeto en el eje X,Y,Z
              0.0,1.0,0.0); //Orientació
    glOrtho(-15.0, 15.0, -5.0, 19.0, -15.0, 15.0);
    //glFrustum(-8,8,-8,8,0.0,-10);
    glPushMatrix();
    // Otras transformaciones
    glScalef(scale, scale, scale);
    //glShadeModel(GL_SMOOTH);
    glPushMatrix();
    //glNormal3f( 0.0f, 1.0f, 0.0f);
    glColor3f(0,0,1);
    material(0.19225, 0.19225, 0.19225, 0.50754, 0.50754, 0.50754, 0.508273, 0.508273, 0.508273,0.25);
    Cubo(6.0,-0.5,6.0,0.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-3,0,3);
    glColor3f(1,0,1);
    //Izquierda_from
    material(0.19225, 0.19225, 0.19225, 0.50754, 0.50754, 0.50754, 0.508273, 0.508273, 0.508273,0.25);
    Cubo(0.1,0.0,0.1,6.0);
    glPopMatrix();
     glPushMatrix();
     glTranslatef(3,0,3);
    glColor3f(1,0,1);
    //Derecha_from
    Cubo(0.1,0.0,0.1,6.0);
    glPopMatrix();
      glPushMatrix();
     glTranslatef(-3,0,-3);
    glColor3f(1,0,1);
    //Izquierda_Atr
    Cubo(0.1,0.0,0.1,6.0);
    glPopMatrix();
      glPushMatrix();
     glTranslatef(3,0,-3);
    glColor3f(1,0,1);
    //Derecha_Atr
    Cubo(0.1,0.0,0.1,6.0);
    glPopMatrix();
      glPushMatrix();
    glColor3f(1,0,1);
    //Mesa
    Cubo(4.0,6.0,4.0,6.3);
    glPopMatrix();
     glPushMatrix();
     glTranslatef(-6.3,-0.5,0);
    glColor3f(1,1,0);
    //Pared_Izq
    material(0.19225, 0.19225, 0.19225, 0.50754, 0.50754 ,0.50754 ,0.508273 ,0.508273, 0.508273,0.25 );
    Cubo(0.3,0.0,6.0,15.);
     glPopMatrix();
     glPushMatrix();
     glTranslatef(0,-0.5,-6.3);
    glColor3f(1,1,0);
    //Tetera
    material(0.19225, 0.19225, 0.19225, 0.50754, 0.50754 ,0.50754 ,0.508273 ,0.508273, 0.508273,0.25 );
    Cubo(6.0,0.0,0.3,15.);
    glPopMatrix();
     glPushMatrix();
     glTranslatef(2.5,6.5,2.5);
     material(0.0 ,0.0 ,0.0 ,0.5 ,0.5 ,0.0, 0.60 ,0.60 ,0.50 ,0.25);
    glutSolidTeapot(0.5);
    glPushMatrix();

    glFlush();
    glutSwapBuffers();

}


void reshape(int w, int h)
{
    glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
// Usamos proyeccion ortogonal
 //   glOrtho(-300, 300, -300, 300, -300, 300);
// Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
    glLoadIdentity();
}

int main(int argc, char* argv[])
{

    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);

    // Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (0, 0);
    // Crear ventana
    glutCreateWindow("Tablero");

    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);

    // Funciones de retrollamada
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);


    // Pasar el control de eventos a GLUT
    glutMainLoop();

    // Regresar al sistema operativo
    return 0;

}
