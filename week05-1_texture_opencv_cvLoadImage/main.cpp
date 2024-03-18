#include <GL/glut.h>
#include <opencv/highgui.h>
void display()
{
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    IplImage*img=cvLoadImage("c:/micky.jpg");
    cvShowImage("opencv",img);
    glutInit(&argc, argc);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreatWindow("week05-1_texture_opencv_cvLoadImage");
    glutDisplayFunc(displat);
    glutMainLoop();

}
