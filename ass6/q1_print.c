#include <GL/glut.h>

#include<stdio.h>

void myInit(void)
{ glClearColor(1.0,1.0,1.0,0.0);
glColor3f(0,0,0);
glPointSize(4.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,640.0,0.0,480.0); }



void myDisplay(void)
{
int a,b,c,d;
char x;
FILE *fp=fopen("q1points.txt","r");
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINES);
while(fscanf(fp,"%c",&x)!=EOF)
{
    fscanf(fp,"%d %d %d %d",&a,&b,&c,&d);
    glVertex2i(a,b);
    glVertex2i(c,d);
}
glEnd();
glFlush();
}


void main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); glutInitWindowSize(640,
480);
glutInitWindowPosition(500,50);
glutCreateWindow("Drawing Horse");
glutDisplayFunc(myDisplay);
myInit(); glutMainLoop(); 
}
