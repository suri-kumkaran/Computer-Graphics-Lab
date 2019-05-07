#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

void prime(int n)
{
	if(n<=1)
	return;
	int i=2;
	while(n>1)
	{
		if(n%i==0)
		{
			printf("%d ",i);
			while(n%i==0)
			{
				n/=i;
			}
		}
		i++;
	}
	printf("\n");
}

int main()
{
	int n;
	printf("Enter Number to find its Prime Factors\n");
	scanf("%d",&n);
	prime(n);
}