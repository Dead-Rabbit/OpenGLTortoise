#include <GL/glew.h>
#include <GL/freeglut.h>

void ChangeSize(GLsizei w,GLsizei h){
    if(w<1) w=1;
    if(h<1) h=1;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
        glOrtho(-30.0,30.0,-30.0*(GLfloat)h/(GLfloat)w,30.0*(GLfloat)h/(GLfloat)w,-50.0,50.0);
    else
        glOrtho(-30.0*(GLfloat)w/(GLfloat)h,30.0*(GLfloat)w/(GLfloat)h,-30.0,30.0,-50.0,50.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void DrawMyObjects() {
    //画四边形
    glBegin(GL_QUADS);
    glColor3f(0.7,0.5,0.2);
    glVertex2f(-7,-3);
    glVertex2f(-5.5,-1);
    glVertex2f(-1,-0.5);
    glVertex2f(-1,-4);
    glColor3f(0.5,0.7,0.2);
    glVertex2f(2,-6.25);
    glVertex2f(2.5,-1);
    glVertex2f(6.5,1);
    glVertex2f(4.5,-6.25);
    glEnd();
}
void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);
    DrawMyObjects();
    glFlush();
}
int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);

    glutCreateWindow("My first");

    glClearColor(0.51,0.51,0.51,0.5);

    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(RenderScene);

    glutMainLoop();
    return 0;
}