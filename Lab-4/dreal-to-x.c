#include <stdio.h>
#include <math.h>

int main()
{
	float real;
	long int quotient;
	int converted[100], i = 1;
	int base, point;

	scanf("%f %d", &real, &base);

	long int decpart = (int)(real);
	float realpart = real - decpart;


	quotient = decpart;
	while (quotient != 0)
	{
		converted[i++] = quotient % base;
		quotient = quotient / base;
	}

	point = i++;
	while (realpart != 0.0)
	{
		realpart *= base;
		int temp = (int)(realpart);
		converted[i++] = temp;
		realpart = realpart - temp;
	}

	for (int j = 1; j < i; j++)
	{
		if (j != point)
			printf("%X", converted[j]);
		else
			printf(".");
	}




	return 0;
}