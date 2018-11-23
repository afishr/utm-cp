#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int declen(const char* str)
{
	int k = 0;
	while (str[k] != '.')
		k++;

	return k;
}

int main()
{

	float decimal = 0;
	int base, temp;
	char* init = malloc(100);

	scanf("%s %d", init, &base);

	int len = declen(init) - 1;


	for (int i = 0; init[i] != '\0'; i++)
	{
		if(init[i] >= '0' && init[i] <= '9')
		{
			temp = init[i] - 48;
		}

		else if(init[i] >= 'A' && init[i] <= 'F')
		{
			temp = init[i] - 55;
		}
		else if (init[i] == '.')
		{
			continue;
		}

		decimal += (temp) * pow(2, len--);
	}

	float real = decimal;
	long int quotient;
	int converted[100], i = 1;
	int point;

	long int decpart = (int)(real);
	float realpart = real - decpart;


	quotient = decpart;
	do
	{
		converted[i++] = quotient % base;
		quotient = quotient / base;
	} while (quotient != 0);

	point = i++;
	while (realpart != 0.0)
	{
		realpart *= base;
		temp = (int)(realpart);
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

	free(init);
	return 0;
}