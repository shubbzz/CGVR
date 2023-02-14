#include<math.h>
#include<GL/glut.h>

GLfloat x,y;
static GLfloat spin= 0.0;
void myInit(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1,1,1,1);
    gluOrtho2D(-250,250,-250,250);
}

void spind(){
    spin+=0.0025;
    if(spin>=360)spin-=360;
    x=cos(spin*3.14/180);
    y=sin(spin*3.14/180);

    glutPostRedisplay();
}

void myReshape(int w,int h){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.5,2.5,-2.5,2.5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void square(){
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex2f(x,y);
    glColor3f(0,1,0);
    glVertex2f(y,-x);
    glColor3f(0,0,1);
    glVertex2f(-x,-y);
    glColor3f(1,0,1);
    glVertex2f(-y,x);
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    square();
    glFlush();
}
void displayd(){
    glClear(GL_COLOR_BUFFER_BIT);
    square();
    glutSwapBuffers();
}
int main(int argc,char**argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("single");
    myInit();
    glutDisplayFunc(display);
    glutReshapeFunc(myReshape);

    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowPosition(600,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("double");
    myInit();
    glutDisplayFunc(displayd);
    glutReshapeFunc(myReshape);
    glutIdleFunc(spind);

    glutMainLoop();
}
