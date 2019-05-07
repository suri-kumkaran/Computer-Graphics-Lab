#include <GL/glut.h>
#include<stdio.h>
#include<math.h>
int x,y,xx,yy;
void myInit(void)
{ glClearColor(1.0,1.0,1.0,0.0);
glColor3f(0.0f,0.0f,0.0f);
glPointSize(4.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-320.0,320.0,-240.0,240.0); }
void myDisplay(void)
{ glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS);
int i,j,k,p1,p0;
double dx,dy,x1,y1,m;
dx=(xx-x);
dy=(yy-y);
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
x1=x,y1=y;
p1=p0;
int yu=y,xu=x;
while(i<no)
{
 glVertex2i((int)x1,(int)y1);
 if(m<1)
 {
   if(xx>0)
   x1++;
   if(xx<=0)
   x1--;
   if(p1>0&&yy>0)
   yu++;
   if(p1>0&&yy<=0)
   yu--;
   p1=p1+2*dy-2*dx*(yu-y1);
   y1=yu;
 }
 else
 {
   if(yy>0)
   y1++;
   if(yy<=0)
   y1--;
   if(p1>0&&xx>0)
   xu++;
   if(p1>0&&xx<0)
   xu--;
   p1=p1+2*dx-2*dy*(xu-x1);
   x1=xu;
 }

 i++;

}
//glVertex2i(100, 130);
//glVertex2i(150, 130);
glEnd();
glFlush();
}
void main(int argc, char** argv)
{
printf("Enter the first point:");
scanf("%d%d",&x,&y);
printf("Enter the second point:");
scanf("%d%d",&xx,&yy);
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); glutInitWindowSize(640,
480);
glutInitWindowPosition(100, 150);
glutCreateWindow("My first program");
glutDisplayFunc(myDisplay);
myInit(); glutMainLoop();
}