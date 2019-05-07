#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int X1, Y1, R;
int gls=-320,gbs=-240;
int l=320, b=240;

void plot(int x, int y){

	x+=X1;
	y+=Y1;
	glBegin(GL_POINTS);
	x*=4;
	y*=4;
	int i, j;
	glVertex2i(x+2,y+2);
	glEnd();
	glFlush();
}

void plotcircle(int x,int y)
{
	plot(+x, +y);
    plot(-x, +y);
    plot(+x, -y);
    plot(-x, -y);
    plot(+y, x);
    plot(-y, x);
    plot(+y, -x);
    plot(-y, -x); 
}

void myInit(void){
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-320.0,320.0,-240.0,240.0);
}

void myDisplay(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);	
	int i, j;
	for(i=gls; i<=l; i+=4){
		for(j=gbs; j<=b; j=j+4){
			glVertex2i(gls,j);
			glVertex2i(l,j);
			glVertex2i(i,gbs);
			glVertex2i(i,b);
		}
	}

	int y=R;
    int x=0;
    int p=1-R;
    plotcircle(x,y);
    while(y>x)
    {
    	x++;
        if(p<0)
        {
            p=p+2*x+1;
        }
        else
        {
            y--;
            p=p+2*x-2*y+1;
        }
        if(x>=y)
        break;
    	plotcircle(x,y);
	}
	plotcircle(x,y);
	glEnd();
	glFlush();
}

void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0,0);
	printf("Enter the coordinates of centre of Circle:\n");
	scanf("%d",&X1);
	scanf("%d",&Y1);
	printf("Enter the radius of Circle:\n");
	scanf("%d",&R);
	glutCreateWindow("Circle Drawing in Grid");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
