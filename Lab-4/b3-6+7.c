#include <stdio.h>

int main()
{
	float norm;
	int base;

	scanf("%f %d", &norm, &base);

	int i = 0;

	if ( (int)norm == 0 )
	{
		while ( (int)norm == 0 )
		{
			norm *= 10;
			i--;
		}
	}
	else
	{
		while ( (int)(norm / 10) != 0 )
		{
			norm /= 10;
			i++;
		}
	}

	printf("%f", norm);
	printf("x%d^%d", base, i);


	return 0;
}