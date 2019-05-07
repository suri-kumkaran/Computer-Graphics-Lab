#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int gls=-320,gbs=-240;
int l=320, b=240;

void plot(int x, int y){
	glBegin(GL_POINTS);
	x*=2;
	y*=2;
	int i, j;
	glVertex2i(x+1,y+1);
	glEnd();
	glFlush();
}

void myInit(void){
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-320.0,320.0,-240.0,240.0);
}

void myDisplay(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);	
	int i, j;
	for(i=gls; i<=l; i+=2){
		for(j=gbs; j<=b; j=j+2){
			glVertex2i(gls,j);
			glVertex2i(l,j);
			glVertex2i(i,gbs);
			glVertex2i(i,b);
		}
	}
	int x,y,p;
	x=0,y=100;
	p=1/2;
	plot(x,y);
	plot(-x,y);
	while(2*x<1)
	{
		x++;
		if(p<0)
		{
		p=p+2*x+1;
	}
	else
	{
		p=p+2*x;
		y--;
	}
	plot(x,y);
	plot(-x,y);
	}
	p=(y-1)-100+(x+0.5)*(x+0.5);
	while(x<=10)
	{
		y--;
		if(p<0)
		{
		x++;
		p=p+2*x-1;
		}
		else
		{
		p=p-1;
		}
		plot(x,y);
		plot(-x,y);
	}
	glEnd();
	glFlush();
}

void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Parabola (Y=100-R^2) Drawing in Grid");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
