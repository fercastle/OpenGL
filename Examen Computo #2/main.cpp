//Creado Por Luis Fernando Hernandez Castillo Carnet: Hc-12012
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
double max_rotatey=90;
double min_rotatey=-90;
float x,y,z,y1;
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
float ymin =0.9;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;
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
void base(){
    
    
    }
    void display()
{
    //  Borrar pantalla y Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Resetear transformaciones
    glLoadIdentity();
     /* transformación modelo/vista */
    gluLookAt(0.0,0.2,0.2, //punto de vista en el eje X,Y,Z
              0.0,0.0,0.0, //Centro del Objeto en el eje X,Y,Z
              0.0,1.0,0.0); //Orientación de la cámara (vector UP el eje X,Y,Z)
    // Rotar en el eje X,Y y Z
   
    //glTranslatef(X, Y, Z); 	// Transladar en los 3 ejes
    // Otras transformaciones
    glScalef(scale, scale, scale);

    glColor3f(0,0,1);
    glTranslatef(0,0,0);
    Cubo(0.6,0.0,0.3,0.4);
    //glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    //glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    glColor3f(1,0,0);
    Cubo(0.2,0.4,0.2,2.4);
    glTranslatef(1.2,0.0,0.0);
    glColor3f(0,1,0);
    Cubo(1.4,2.4,0.2,2.7);
     glColor3f(0,0,1);
     glTranslatef(1.5,0.0,0.0);
    Cubo(0.1,1.2,0.1,2.7);
    
    glTranslatef(0.0,Y,0.0);

    Cubo(0.05,0.3,0.05,1.3);
    glColor3f(1,1,0);
    Cubo(0.1,0.0,0.1,0.3);
         glColor3f(1,0,1);
  
       glColor3f(1,0,1);
       void glPopMatrix(void);
       if((Y<=0.0 and rotate_y==-10 )){
           glColor3f(0,1,0);
           }
        else if(Y==0.0){
             glColor3f(1,0,1);
            }
       
     glLoadIdentity();
    glTranslatef(2.6,0.0,0.0);
glutSolidCube (0.6);
glFlush();

    glutSwapBuffers();

}

// Función para controlar teclas especiales
void specialKeys( int key, int x, int y )
{

    //  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT){
    if(rotate_y<max_rotatey){
        rotate_y += 10;
    }
}
    //  Flecha izquierda: rotación en eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT){
        if(rotate_y>min_rotatey){
        rotate_y -= 10;
    }
}
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
    //control de teclas que hacen referencia a Escalar y transladar el cubo en los ejes X,Y,Z.
    switch (key)
    {
    //case 's':
        //scale=0.5;
        //break;
    //case 'd':
  
        //scale=1.5;

        //break;
    case 'x' :
        X += 0.1f;
        break;
    case 'X' :
        X -= 0.1f;
        break;
    case 'y' :
      if(Y<=ymin){
        Y += 0.1f;
    }
        break;
    case 'Y' :
     if(Y>=0.0){
        Y -= 0.1f;
    }
        break;
    case 'z':
        Z -= 0.1f;
        break;
    case 'Z':
        Z += 0.1f;
        break;
    case 'q':
        exit(0);			// exit
    }
    glutPostRedisplay();
}
void reshape(int w, int h)
{
    glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
// Usamos proyeccion ortogonal
    glOrtho(-3, 5, -5, 5, -5, 5);
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
    glutCreateWindow("Cubo controlado por teclas");

    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);

    // Funciones de retrollamada
    glutDisplayFunc(display); 
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    // Pasar el control de eventos a GLUT
    glutMainLoop();

    // Regresar al sistema operativo
    return 0;

}
