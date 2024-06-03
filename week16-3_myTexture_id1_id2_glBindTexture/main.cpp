#include <opencv/highgui.h> ///使用 OpenCV 2.1 比�?簡單, ?��???High GUI ?�可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀??
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色�?(?�要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. ?��?貼�??�能
    GLuint id; ///準�?一??unsigned int ?�數, ??貼�?ID
    glGenTextures(1, &id); /// ?��?Generate 貼�?ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁�?bind 貼�?ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼�??�數, 超�??��??��??�T, 就�?覆貼??
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼�??�數, 超�??��??��??�S, 就�?覆貼??
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼�??�數, ?�大?��??��?, ?��?近�?
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼�??�數, 縮�??��??��?, ?��?近�?
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
int id1, id2;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBindTexture(GL_TEXTURE_2D, id1);
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex2f(-1, +1);
        glTexCoord2f(0, 1); glVertex2f(-1, -1);
        glTexCoord2f(1, 1); glVertex2f(+1, -1);
        glTexCoord2f(1, 0); glVertex2f(+1, +1);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, id2);
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week16-3 �h�ӶK��");

    glutDisplayFunc(display);
    id1 = myTexture("c:/background.jpg");
    id2 = myTexture("c:/earth.jpg");
    glutMainLoop();
}
