#include <GL/glut.h>

int main(int argc, char** argv) {
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500,500);
    glutInitWindoPosition (500,500);
    glutCreateWindow ("Cuadrado Multicolor");
    

	return 0;
}
