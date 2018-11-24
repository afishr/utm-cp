#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int declen(const char* str)
{
	int k = 0;
	while (str[k] != '\0')
		k++;

	return k;
}

char *rev(const char *x, int l)
{
	char *b = calloc(200, sizeof(int));

	/*
	 * Copying elements into array b starting from end of array a
	 */

	for (int i = l - 1, j = 0; i >= 0; i--, j++)
		b[j] = x[i];

	return b;
}

int main()
{

	FILE *fin = fopen("operations.in", "r");

	long long int dec1 = 0, dec2 = 0;
	int temp;
	char *init1 = calloc(201, sizeof(char)), *init2 = calloc(201, sizeof(char));
	char *res = calloc(201, sizeof(char));

	fscanf(fin, "%s", init1);
	fscanf(fin, "%s", init2);

	fclose(fin);

	int len1 = declen(init1), len2 = declen(init2);
	/*
	for (int i = 0; init1[i] != '\0'; i++)
	{
		temp = init1[i] - 48;

		dec1 += (temp) * pow(2, len1--);
	}

	for (int i = 0; init2[i] != '\0'; i++)
	{
		temp = init2[i] - 48;

		dec2 += (temp) * pow(2, len2--);
	}

	long long int quotient, res = dec1 + dec2;
	int i = 1;
	long long int *converted = malloc(200 * sizeof(int));

	quotient = res;
	do
	{
		converted[i++] = quotient % 2;
		quotient = quotient / 2;
	} while (quotient != 0);

	for (int j = i - 1; j > 0; j--)
		printf("%lld", converted[j]);*/

	init1 = rev(init1, len1);
	init2 = rev(init2, len2);



	char *big;
	int lon;

	if (len1 >= len2)
	{
		big = init1;
		lon = len1;
	}
	else
	{
		big = init2;
		lon = len2;
	}

	big[lon-1] = '0';
	big[lon] = '\0';

	int i;
	int rem = 0;
	for (i = 0; big[i] != '\0'; i++)
	{
		int temp1 = init1[i], temp2 =init2[i];

		if (temp1)
			temp1 -= 48;

		if (temp2)
			temp2 -= 48;

		res[i] = (char)((abs(temp1 - temp2 + rem) % 2) + 48);


		/*if ((temp1 && temp2) || (temp1 && rem) || (temp2 && rem))*/

		if ((!temp1 && temp2) || (!(temp1 - temp2) && rem != 0))
			rem = 1;
		else
			rem = 0;
	}

	printf("%s", rev(res, declen(res)));


	free(init1);
	free(init2);
//	free(converted);
	return 0;
}