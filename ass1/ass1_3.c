#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int max(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;
}

int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int GCD(int s,int b)
{
	if(s==b)
		return s;
	if(s==0)
		return b;
	if(b==0)
		return s;
	int ns=min(s,b);
	int nb=max(s,b);
	return GCD(ns,nb%ns);

}

int main()
{
	int n1,n2;
	printf("Enter 2 Numbers to find their GCD\n");
	scanf("%d %d",&n1,&n2);
	int ans=GCD(n1,n2);
	printf("%d\n",ans);
	
}