#include <stdlib.h>
#include <GL/glut.h>
#include<gl\GL.h>
#include<gl\GLU.h>
#include <time.h>
#include<unistd.h>

GLfloat vertices[] = {
1.0,1.0,1.0,//0
1.0,1.0,-1.0,//1
1.0,-1.0,1.0,//2
1.0,-1.0,-1.0,//3
-1.0,1.0,1.0,//4
-1.0,1.0,-1.0,//5
-1.0,-1.0,1.0,//6
-1.0,-1.0,-1.0 };//7

GLfloat colors[] = {
0.0,0.0,0.0,
0.0,0.0,1.0,
0.0,1.0,0.0,
0.0,1.0,1.0,
1.0,0.0,0.0,
1.0,0.0,1.0,
1.0,1.0,0.0,
1.0,1.0,1.0 };

GLubyte cubeIndices[] = {
7,5,4,6,
7,5,1,3,
1,3,2,0,
2,0,4,6,
0,1,5,4,
7,6,2,3,
 };

static GLfloat theta[] = { 0.0,0.0,0.0 };
static GLint axis = 2;


void displaySingle(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);

	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndices);

	glFlush();
}

void spinCube()
{
	/* Idle callback, spin cube 2 degrees about selected axis */
	usleep(7001);
	theta[axis] += 2.0;
	if (theta[axis] > 360.0) theta[axis] -= 360.0;
	glutPostRedisplay();
}


void mouse(int btn, int state, int x, int y)
{
	/* mouse callback, selects an axis about which to rotate */
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
}

void myReshape(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    glOrtho(-2.0 ,2.0, -2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("colorcube");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(displaySingle);
	glutIdleFunc(spinCube);
	glutMouseFunc(mouse);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glColorPointer(3, GL_FLOAT, 0, colors);
	glNormalPointer(GL_FLOAT, 0, vertices);
	glColor3f(1.0, 1.0, 1.0);
	glutMainLoop();
}
