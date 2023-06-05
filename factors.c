#include <stdlib.h>
#include <stdio.h>

int main()
{
	int num = 32, i, factor;

	for(i = 2; i <= num; i++)
	{
		if (num % i == 0)
		{	
			factor = num / i;
			printf("%d=%d*%d\n", num, factor, i);
			break;
		}
	}
	return(0);
}
