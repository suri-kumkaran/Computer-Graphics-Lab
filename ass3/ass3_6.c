#include <GL/glut.h>

#include <GL/glut.h>


void myInit(void)
{ glClearColor(1.0,1.0,1.0,0.0);
glColor3f(0,0,0);
glPointSize(5);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,640.0,0.0,480.0); }



void myDisplay(void)
{ glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS);
glEnd();
glFlush();
}

float xx,yy,xxx,yyy;

void suri_mouse(int button, int state,int x, int y)
{

	glBegin(GL_LINES); 
	if(state==GLUT_DOWN)
	{
	if(button==GLUT_LEFT_BUTTON)
	{
		xx=x;
		yy=y;
	}
	else if(button==GLUT_RIGHT_BUTTON)
	{
		xxx=x;
		yyy=y;
		glVertex2i(xx,480-yy);
		glVertex2i(x,480-y);
	}
	else
	{
		xx=xxx;
		yy=yyy;
	}
	}
	glEnd();
glFlush();
}


void main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); glutInitWindowSize(640,
480);
glutInitWindowPosition(0,0);

glutCreateWindow("First Programme");
glutDisplayFunc(myDisplay);
glutMouseFunc(suri_mouse);
myInit(); glutMainLoop(); 
}
