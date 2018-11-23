#include <stdio.h>

int main()
{
	long decimalnum, quotient;
	int converted[100], i = 1, j;
	int base;



	scanf("%ld %d", &decimalnum, &base);
	quotient = decimalnum;
	while (quotient != 0)
	{
		converted[i++] = quotient % base;
		quotient = quotient / base;
	}

	for (j = i - 1; j > 0; j--)
		printf("%X", converted[j]);

	return 0;
}