#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{

	long int decimal;

	scanf("%ld", &decimal);

	long int quotient = decimal;
	int *converted = calloc(16, sizeof(int));
	int i = 0;

	do
	{
		converted[i++] = quotient % 2;
		quotient = quotient / 2;
	} while (quotient != 0);

	for (int j = 15; j >= 0; j--)
	{
		if (j == 8)
			printf(" ");
		printf("%d", converted[j]);
	}

	free(converted);
	return 0;
}