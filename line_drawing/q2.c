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
	int i,j,k,p1,p0;
	for(i=gls; i<=l; i+=20){
		for(j=gbs; j<=b; j=j+20){
			glVertex2i(gls,j);
			glVertex2i(l,j);
			glVertex2i(i,gbs);
			glVertex2i(i,b);
		}
	}
	double dx,dy,x1,y1,m;
	dx=(X2-X1);
	dy=(Y2-Y1);
	if(dx<0)
	dx=-1*dx;
	if(dy<0)
	dy=-1*dy;
	m=dy/dx;
	p0=2*dy-dx;
	int no;
	if(dx>dy)
	no=dx;
	else
	no=dy;
	i=0;
	x1=X1,y1=Y1;
	p1=p0;
	int yu=Y1,xu=X1;
	while(i<no)
	{
	 plot((int)x1,(int)y1);
	 if(m<1)
	 {
	   if(X2>0)
	   x1++;
	   if(X2<=0)
	   x1--;
	   if(p1>0&&Y2>0)
	   yu++;
	   if(p1>0&&Y2<=0)
	   yu--;
	   p1=p1+2*dy-2*dx*(yu-y1);
	   y1=yu;
	 }
	 else
	 {
	   if(Y2>0)
	   y1++;
	   if(Y2<=0)
	   y1--;
	   if(p1>0&&X2>0)
	   xu++;
	   if(p1>0&&X2<0)
	   xu--;
	   p1=p1+2*dx-2*dy*(xu-x1);
	   x1=xu;
	 }

	 i++;

	}
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
	
	glutCreateWindow("Line Printing in Grid using Bresenham’s Line Generation Algorithm");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
