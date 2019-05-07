#include <GL/glut.h>
#include <math.h>
#include <stdio.h>


int main()
{
	char s1[50],s2[50];
	printf("Enter String 1\n");
	scanf("%s",s1);
	printf("Enter String 2\n");
	scanf("%s",s2);
	int size1,size2,i;
	i=0;
	while(s1[i])
	{
		i++;
	}
	size1=i;
	i=0;
	while(s2[i])
	{
		i++;
	}
	size2=i;
	if(size1!=size1)
		printf("1\n");
	else
	{
		i=0;
		while(i<size1)
		{
			if(s1[i]!=s2[i])
			{
				printf("1\n");
				return 0;
			}
			i++;
		}
		printf("0\n");

	}
		

} 