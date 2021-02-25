#if defined(__WIN32__)
#include <windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#else
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <glew.h>
#include <GLUT/glut.h>
#endif

void Init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0.0, (GLdouble)200.0, 0.0, (GLdouble)150.0, -1, 1);
}

void lineSegment(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.4, 0.2);
    glBegin(GL_LINES);
        glVertex2i(180, 15);
        glVertex2i(10, 145);
    glEnd();

    glFlush();
}

int run_2_test_glut(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(400, 300);
    glutCreateWindow("An Example OpenGL Program");

    Init();
    glutDisplayFunc(lineSegment);
    glutMainLoop();
    return 0;
}

int main(int argc, char** argv){
    return run_2_test_glut(argc, argv);
}
