#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int X1, Y1, X2, Y2;
int gls=-320,gbs=-240;
int l=320, b=240;

void plot(int x, int y){

	glBegin(GL_POINTS);
	x*=20;
	y*=20;
	int i, j;
	glVertex2i(x+10,y+10);
	glEnd();
	glFlush();
}

void myInit(void){
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(20.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-320.0,320.0,-240.0,240.0);
}

void myDisplay(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);	
	int i, j;
	for(i=gls; i<=l; i+=20){
		for(j=gbs; j<=b; j=j+20){
			glVertex2i(gls,j);
			glVertex2i(l,j);
			glVertex2i(i,gbs);
			glVertex2i(i,b);
		}
	}
	plot(20*X1,20*Y1);
	int dx=X2-X1;
	int dy=Y2-Y1;
	int steps;
	if(abs(dx)>abs(dy)) steps=abs(dx);
	else steps=abs(dy);

	float Xinc=dx/(float)steps;
	float Yinc=dy/(float)steps;
	i=0;

	float x=(float)X1, y=(float)Y1;
	for(i; i<steps; i++){
		x+=Xinc;
		y+=Yinc;
		plot(round(x),round(y));
	}
	plot(X1*20,Y1*20);
	glEnd();
	glFlush();
}

void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0,0);
	printf("Enter the coordinates of the two points:\n");
	scanf("%d",&X1);
	
	scanf("%d",&Y1);
	
	scanf("%d",&X2);
	
	scanf("%d",&Y2);
	
	glutCreateWindow("Line Printing in Grid using DDA");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
