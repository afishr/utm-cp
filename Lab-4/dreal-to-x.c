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
	do
	{
		converted[i++] = quotient % base;
		quotient = quotient / base;
	} while (quotient != 0);

	point = i++;
	while (realpart != 0.0 && ((i - point) <= 8))
	{
		realpart *= base;
		int temp = (int)(realpart);
		converted[i++] = temp;
		realpart = realpart - temp;
	}

	for (int j = point - 1; j > 0; j--)
	{
		if (j != point)
			printf("%X", converted[j]);
	}
	printf(".");

	for (int j = i - 1; j > point; j--)
	{
		if (j != point)
			printf("%X", converted[j]);
	}

	return 0;
}