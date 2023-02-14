#include<GL/glut.h>
#include<iostream>
int n;
struct line_seg{
    int x2;
    int x1;
    int y2;
    int y1;
};

struct line_seg ls[10];
double xmin=50,ymin=50,xmax=350,ymax=350;
double xvmin=100,yvmin=100,xvmax=300,yvmax=300;

void myInit(){
    glClearColor(1,1,1,1);
    glColor3f(0,0,1);
    glLineWidth(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
}
int CT(double p,double q,double *u1,double *u2){
    double r;
    if(p) r=q/p;
    if(p<0.0){
            if(r>*u1) *u1=r;
            if(r>*u2){return (false);}
    }
    else
    if(p>0.0){
        if(r<*u2) *u2=r;
        if(r<*u1){return (false);}
    }
    else
    if(p==0.0){
        if(q<0.0){return (false);}
    }
    return(true);
}

void LB(double x0,double y0,double x1,double y1){
    double dx=x1-x0,dy=y1-y0,u1=0.0,u2=1.0;
    if(CT(-dx,x0-xmin,&u1,&u2))
        if(CT(dx,xmax-x0,&u1,&u2))
            if(CT(-dy,y0-ymin,&u1,&u2))
                if(CT(dy,xmax-y0,&u1,&u2)){
                    if(u2<1.0){
                        x1=x0+dx*u2;
                        y1=y0+dy*u2;
                    }
                    if(u1>0.0){
                        x0=x0+dx*u1;
                        y0=y0+dy*u1;
                    }
                }
    double sx=(xvmax-xvmin)/(xmax-xmin);
    double sy=(yvmax-yvmin)/(ymax-ymin);
    double vx0=xvmin+(x0-xmin)*sx;
    double vy0=yvmin+(y0-ymin)*sy;
    double vx1=xvmin+(x1-xmin)*sx;
    double vy1=yvmin+(y1-ymin)*sy;

    glColor3f(0,0,1);
    glBegin(GL_LINES);
    glVertex2d(vx0,vy0);
    glVertex2d(vx1,vy1);
    glEnd();

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    for(int i=0;i<n;i++){
        glBegin(GL_LINES);
        glVertex2d(ls[i].x1,ls[i].y1);
        glVertex2d(ls[i].x2,ls[i].y2);
        glEnd();
    }

    glColor3f(0,0,1);
    glBegin(GL_LINE_LOOP);
    glVertex2d(xmin,ymin);
    glVertex2d(xmax,ymin);
    glVertex2d(xmax,ymax);
    glVertex2d(xmin,ymax);
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(xvmin,yvmin);
    glVertex2d(xvmax,yvmin);
    glVertex2d(xvmax,yvmax);
    glVertex2d(xvmin,yvmax);
    glEnd();

    for(int i=0;i<n;i++){
        LB(ls[i].x1,ls[i].y1,ls[i].x2,ls[i].y2);
    }

    glFlush();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    std::cout<<"number of lines";
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cout<<("x1,y1,x2,y2:");
        std::cin>>ls[i].x1>>ls[i].y1>>ls[i].x2>>ls[i].y2;
    }

    glutCreateWindow("LB");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
}

