#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
	int i,m;
	char n;
	i = 0;
	printf("   ");
	while (i < 100)
	{
		if (i < 8)
		{
			n = 'a' + i;
			printf("%c  ", n);
		}
		else if (i%10==0 && i>=10)
		{
			if (i%9!=0)
				printf("\n%d  ",i%9);
			else
				printf("\n   ");
		}
		else if (i%10==9 && i>=10)
		{
			if (i%9!=0)
				printf("%d", i%9);
		}
		else if (i > 10 && i < 91)
			printf("*  ");
		else if (i >= 91)
		{
			n = 'a' + i - 91;
			printf("%c  ", n);
		}
		i++;
	}
	printf("\n");
	return 0;
}
