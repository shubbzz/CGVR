#include<iostream>
#include<GL/glut.h>
typedef GLfloat point[3];

point tetra[4]={{0,250,-250},{0,0,250},{-250,-250,-250},{250,-250,-250}};

int iter;

void myInit(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glOrtho(-300,300,-300,300,-300,300);
    glClearColor(1,1,1,1);
}

void drawtriangle(point p1,point p2,point p3){
    glVertex3fv(p1);
    glVertex3fv(p2);
    glVertex3fv(p3);
}

void drawtetra(point p1,point p2,point p3,point p4){
    glColor3f(1,0,0);
    drawtriangle(p1,p2,p3);
    glColor3f(0,0,1);
    drawtriangle(p1,p2,p4);
    glColor3f(0,1,0);
    drawtriangle(p4,p2,p3);
    glColor3f(1,1,0);
    drawtriangle(p1,p4,p3);
}

void dividetetra(point p1,point p2,point p3,point p4,int iter){
    point mid[6];
    int j;
    if(iter>0){
        for(j=0;j<3;j++) mid[0][j]=(p1[j]+p2[j])/2;
        for(j=0;j<3;j++) mid[1][j]=(p1[j]+p3[j])/2;
        for(j=0;j<3;j++) mid[2][j]=(p1[j]+p4[j])/2;
        for(j=0;j<3;j++) mid[3][j]=(p2[j]+p3[j])/2;
        for(j=0;j<3;j++) mid[4][j]=(p2[j]+p4[j])/2;
        for(j=0;j<3;j++) mid[5][j]=(p3[j]+p4[j])/2;

        dividetetra(p1,mid[0],mid[1],mid[2],iter-1);
        dividetetra(p2,mid[0],mid[3],mid[4],iter-1);
        dividetetra(p3,mid[1],mid[3],mid[5],iter-1);
        dividetetra(p4,mid[2],mid[4],mid[5],iter-1);
    }
    else{
        drawtetra(p1,p2,p3,p4);
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(1,1,1,1);
    glBegin(GL_TRIANGLES);
    dividetetra(tetra[0],tetra[1],tetra[2],tetra[3],iter);
    glEnd();
    glFlush();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    std::cout<<"enter the number of iterations:";
    std::cin>>iter;
    glutCreateWindow("fifth");
    glutDisplayFunc(display);
    myInit();
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
