#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printb(int *x)
{
	for (int j = 15; j >= 0; j--)
	{
		if (j == 8)
			printf(" ");
		printf("%d", x[j]);
	}
}

void next_sequence(int *arr, int length)
{
	int j;

	j = 0;
	while (arr[j] == 1)
	{
		arr[j] = 0;
		j++;
	}
	arr[j] = 1;
}

int main()
{

	long int decimal;

	scanf("%ld", &decimal);

	long int quotient = abs(decimal);
	int *converted = calloc(16, sizeof(int));


	int i = 0;

	do
	{
		converted[i++] = quotient % 2;
		quotient = quotient / 2;
	} while (quotient != 0);

	if (decimal < 0)
		converted[15] = 1;
	else
		converted[15] = 0;

	if (decimal < 0)
	{

		printb(converted);
		printf(" :Direct code\n");

		for (int j = 0; j < 15; ++j)
			converted[j] = !converted[j];

		printb(converted);
		printf(" :Ones complement\n");

		next_sequence(converted, 15);
		printb(converted);
		printf(" :Twos complement\n");


	}
	else
	{
		printb(converted);
		printf(" :Direct code\n");
		printb(converted);
		printf(" :Ones complement\n");
		printb(converted);
		printf(" :Twos complement\n");
	}


	free(converted);
	return 0;
}