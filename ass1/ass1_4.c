#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

int main()
{
	int *i;
	char *c;
	float *f;
	void *v;
	printf("Size of VOID Pointer is %d\n",(int)sizeof(v));
	printf("Size of INTEGER Pointer is %d\n",(int)sizeof(i));
	printf("Size of CHAR Pointer is %d\n",(int)sizeof(c));
	printf("Size of FLOAT Pointer is %d\n",(int)sizeof(f));

}