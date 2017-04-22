//Actividad De Algoritmos Piramide
//Luis Fernando Hernandez Castillo
//Carnet: Hc-12012
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
//Guarda Los Casos 
int casos=0;
//Definira Los Colores De La Piramide
double r=0;
double g=0;
double  b=0;
void init(void)
{
    switch(casos){
        case 0:
// Activamos la fuente de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
//glLightfv(GL_LIGHT0,GL_POSITION,light_position);
// Queremos que se dibujen las caras frontales
// y con un color solido de relleno.
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
}
//Caras Del Triangulo Pasando Como Parametros Colores r,g,b
void Trian_Infe(double r,double g, double b){
    // Ubicamos la fuente de luz en el punto
    GLfloat mat_ambient[] = { 0.329412f, 0.223529f, 0.027451f,1.0f };
    GLfloat mat_diffuse[] = { 0.780392f, 0.568627f, 0.113725f, 1.0f };
    GLfloat mat_specular[] = { 0.992157f, 0.941176f, 0.807843f, 1.0f };
    //setMaterial
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex3f(0.3, -0.3, -0.3 );
    glVertex3f(0.3, -0.3,  0.3 );
    glVertex3f(-0.3, -0.3,  0.3 );
    glVertex3f(-0.3, -0.3, -0.3 );
    glEnd();
}
void Trian_Front(double r, double g, double b){
    	// Propiedades del material
 GLfloat mat_ambient[] = { 0.329412 ,0.223529, 0.027451};
 GLfloat mat_diffuse[] = { 0.780392 ,0.568627 ,0.113725};
 GLfloat mat_specular[] = {0.992157, 0.941176, 0.807843 };
    //setMaterial
 glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glBegin(GL_POLYGON);
    glColor3f(r,g,b);
	glVertex3f( -0.3, -0.3, -0.3 );
	glVertex3f(0.3, -0.3, -0.3 );
	glVertex3f( 0.0,  0.3, 0.0 );
	glEnd();
}
void Trian_Atra(double r,double g, double b){
    // Propiedades del material
 GLfloat mat_ambient[] = { 0.19225, 0.19225, 0.19225 };
 GLfloat mat_diffuse[] = { 0.50754, 0.50754, 0.50754};
 GLfloat mat_specular[] = {0.508273, 0.508273, 0.508273 };
    //setMaterial
 glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glBegin(GL_POLYGON);
    glColor3f(r,g,b);
    glVertex3f(  -0.3, -0.3, 0.3 );      
    glVertex3f(  0.3,  -0.3, 0.3 );      
    glVertex3f( 0.0,  0.3, 0.0 );      
    glEnd();
}
void Trian_Der(double r,double g, double b){
    // Propiedades del material
 GLfloat mat_ambient[] = { 0.135, 0.2225, 0.1575  };
 GLfloat mat_diffuse[] = { 0.54, 0.89, 0.63 };
 GLfloat mat_specular[] = {0.316228, 0.316228, 0.316228   };
    //setMaterial
 glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex3f(0.3, -0.3, -0.3 );
    glVertex3f(0.3, -0.3,  0.3 );
    glVertex3f(0.0,  0.3, 0.0 );
    glEnd();
}
void Trian_Izq(double r,double g, double b){
     // Propiedades del material
 GLfloat mat_ambient[] = { 0.0, 0.05, 0.05  };
 GLfloat mat_diffuse[] = { 0.4, 0.5, 0.5};
 GLfloat mat_specular[] = {0.04 ,0.7 ,0.7   };
    //setMaterial
 glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glBegin(GL_TRIANGLES);
    glColor3f(r,g,b);
    glVertex3f(-0.3, -0.3, -0.3 );
    glVertex3f(-0.3, -0.3,  0.3 );
    glVertex3f(0.0,  0.3,  0.0 );
    glEnd();
}
//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
void display()
{
    //  Borrar pantalla y Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    // Resetear transformaciones
    glLoadIdentity();
    // Rotar en el eje X,Y y Z
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    //Hubicacion de la luz
    GLfloat light_position[] = { 0.5, 1.0, -0.6, 3.0 };
    GLfloat shine[] = {25.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_SHININESS, shine);
    glShadeModel(GL_SMOOTH);
    //Desactivando Las Texturas
    if (casos>0){
glDisable(GL_LIGHTING);
 glDisable(GL_LIGHT0); 
 glDisable(GL_DEPTH_TEST);
 //Pintando La Piramide De Un Color
//Rojo
    if (casos==1){
        r=1;
        g=0;
        b=0;
    }
//Verde
    else if(casos==2){
        r=0;
        g=1;
        b=0;
        }
//Azul
    else if(casos==3){
        r=0;
        g=0;
        b=1;
        }
//Amarillo
    else if(casos==4){
        r=1;
        g=1;
        b=0;
        }
//Rosado
    else {
        r=1;
        g=0;
        b=1;
        }
    }
    //Dibujando Piramide:
    glNormal3f( 0.0f, -1.0f, 0.0f);
     // Cara Inferior Del Triangulo
    Trian_Infe(r,g,b);
    glNormal3f( 0.0f, 0.0f, 1.0f);
    //Cara Frontal Del Triangulo
    Trian_Front(r,g,b);
    glNormal3f( 0.0f, 0.0f,-1.0f);
    //Cara Trasera Del Triangulo
    Trian_Atra(r,g,b);
    glNormal3f( -1.0f,0.0f, 0.0f );
    //Cara Trasera Del Triangulo
    Trian_Der(r,g,b);
     glNormal3f(1.0f, 0.0f, 0.0);
    //Cara Izquierda Del Triangulo
    Trian_Izq(r,g,b);
    glFlush();
    glutSwapBuffers();
}
// Función para controlar teclas especiales
void specialKeys( int key, int x, int y )
{
    //  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 7;
    //  Flecha izquierda: rotación en eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 7;
    //  Flecha arriba: rotación en eje X positivo 7 grados
    else if (key == GLUT_KEY_UP)
        rotate_x += 7;
    //  Flecha abajo: rotación en eje X negativo 7 grados
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 7;
    //  Tecla especial F2 : rotación en eje Z positivo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z += 7;
    //  Tecla especial F2 : rotación en eje Z negativo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z -= 7;
    //  Solicitar actualización de visualización
    glutPostRedisplay();
}
// Función para controlar teclas normales del teclado.
void keyboard(unsigned char key, int x, int y)
{
    //control de teclas Que Cambian Los Colores y Texturas De La Piramide
    switch (key)
    {
    case '0':
    //Activando Las Texturas
       glEnable(GL_LIGHTING);
       glEnable(GL_LIGHT0);
       glDepthFunc(GL_LESS);
       glEnable(GL_DEPTH_TEST);
        casos=0;
        break;
    case '1':
        casos=1;
        break;
    case '2' :
        casos=2;
        break;
    case '3' :
        casos=3;
        break;
    case '4' :
        casos=4;
        break;
    case '5' :
        casos=5;
        break;
    case 'q':
        exit(0);			// exit
    }
    glutPostRedisplay();
}
int main(int argc, char* argv[])
{
    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);
    // Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (70,0);
    // Crear ventana
    glutCreateWindow("Piramide Con Texturas");
    init();
    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);
    // Funciones de retrollamada
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    // Pasar el control de eventos a GLUT
    glutMainLoop();
    // Regresar al sistema operativo
    return 0;
}
