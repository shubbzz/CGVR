#include<GL/glut.h>

void myInit(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1,1,1,1);
    gluOrtho2D(0,400,0,400);
}

void drawp(){
    int x1=100,x2=300,y1=100,y2=250,i,n=50;
    for(i=0;i<n;i+=2){
        glBegin(GL_LINE_LOOP);
        glVertex2f(x1+i,y1+i);
        glVertex2f(x1+i,y2+i);
        glVertex2f(x2+i,y2+i);
        glVertex2f(x2+i,y1+i);
        glEnd();
    }
}

void putpixel(int x,int y,int xc,int yc){
    glBegin(GL_POINTS);
    glVertex2f(xc+x,yc+y);
    glVertex2f(xc+x,yc-y);
    glVertex2f(xc-x,yc+y);
    glVertex2f(xc-x,yc-y);
    glVertex2f(xc+y,yc+x);
    glVertex2f(xc+y,yc-x);
    glVertex2f(xc-y,yc+x);
    glVertex2f(xc-y,yc-x);
    glEnd();
}

void drawcircle(int xc,int yc,int r){
    int x=0;
    int y=r;
    int d = 1 - r;
    while(x<=y){
        putpixel(x,y,xc,yc);
        if(d<0){
            d+=2*x+3;
        }
        else{
            d+=2*(x-y)+5;
            y--;
        }
        x++;
    }
}

void drawc(){
    int xc=175,yc=175,r=100,n=50;
    for(int i=0;i<n;i+=2){
        drawcircle(xc+i,yc+i,r);
    }
}

void displayc(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    drawc();
    glFlush();
}

void displayp(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,1);
    drawp();
    glFlush();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(400,400);
    glutCreateWindow("cylinder");
    glutDisplayFunc(displayc);
    myInit();
    glutInitWindowPosition(500,100);
    glutInitWindowSize(400,400);
    glutCreateWindow("parallelopiped");
    glutDisplayFunc(displayp);
    myInit();
    glutMainLoop();

}
