#include<math.h>
#include<GL/glut.h>

void myInit(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(1,1,1,1);
    gluOrtho2D(-1,1,-1,1);
    glColor3f(1,0,0);
}

void sphere(){
    double c=3.14/180,phir10,c80,phi,phir,theta,thetar,x,y,z;
    glBegin(GL_QUAD_STRIP);
    glColor3f(1,0,0);
    for(phi=-80;phi<=80;phi+=10){
        phir=phi*c;
        phir10=(phi+10)*c;
        for(theta=-180;theta<=180;theta+=10){
            thetar=theta*c;
            x=sin(thetar)*cos(phir);
            y=cos(thetar)*cos(phir);
            z=sin(phir);
            glVertex3d(x,y,z);

            x=sin(thetar)*cos(phir10);
            y=cos(thetar)*cos(phir10);
            z=sin(phir10);
            glVertex3d(x,y,z);
        }
    }
    glEnd();

    c80=c*80;
    z=sin(c80);
    glColor3f(0,0,1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3d(0,0,1);
    for(theta=-180;theta<=180;theta+=10){
        thetar=c*theta;
        x=sin(thetar)*cos(c80);
        y=cos(thetar)*cos(c80);
        glVertex3d(x,y,z);
    }
    glEnd();

    z=-sin(c80);
    glColor3f(0,0,1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3d(0,0,-1);
    for(theta=-180;theta<=180;theta+=10){
        thetar=c*theta;
        x=sin(thetar)*cos(c80);
        y=cos(thetar)*cos(c80);
        glVertex3d(x,y,z);
    }
    glEnd();
}

void display(){
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0,0,1);
    glRotatef(-10,-1,-1,0);
    sphere();
    glFlush();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("six");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
}
