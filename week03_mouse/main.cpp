///請貼上10行GLUT程式
#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN)|
        printf("glVertex2f(3d-150)/150.0-(3d-150)/150.0);")
}
int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03_mouse");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
