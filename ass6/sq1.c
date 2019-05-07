#include<GL/glut.h>
#include<stdio.h>
#include<string.h>
int first = 0;
int xi, yi, xf, yf;
FILE *fp;
char name[20];

void myDisplay(int x, int y, int w, int z)
{
	glBegin(GL_LINES);
	glVertex2i(x,y);
	glVertex2i(w,z);
	glEnd();
	glFlush();
}

void filefunction(int x, int y)
{
	fprintf(fp,"%d,%d\n",x,y);
}

void myMouse(int btn, int state, int x, int y)
{
    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
        switch(first)
        {
			case 0:
			{
				xi =x;
				yi =y;
				first = 1;
				filefunction(xi,yi);
				break;
			}
			case 1:
			{
				xf = x;
				yf = y;
				myDisplay ( xi, yi, xf, yf);
				filefunction(xf,yf);
				xi=x;
				yi=y;
				break;
			}
        }
    }
	else if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        first=0;
        fclose(fp);
        fp=fopen(name,"w");
		fclose(fp);
		fp=fopen(name,"a");
		glClearColor(1.0,1.0,1.0,0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_POINTS);
		glEnd();
		glFlush();
    }
}

void fuc(void)
{
	glutMouseFunc(myMouse);
}

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0f,0.5f,0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,800.0,600.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

int main(int argc, char** argv)
{
	puts("press 1 for Horse drawing\npress 2 for letter drawing");
	int input;
	scanf("%d",&input);
	if(input==1)
		strcpy(name,"horse.txt");
	else
		strcpy(name,"letter.txt");
    fp=fopen(name,"w");
    fclose(fp);
    fp=fopen(name,"a");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(150,150);
	glutCreateWindow("Polygon Drawing");
	myInit();
	glutDisplayFunc(fuc);
	glutMainLoop();
	fclose(fp);
}