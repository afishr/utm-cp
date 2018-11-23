#include <stdio.h>

int main()
{
	long int binaryval, converted = 0, i = 1, remainder;
	int base;

	scanf("%ld %d", &binaryval, &base);
	while (binaryval != 0)
	{
		remainder = binaryval % 10;
		converted += remainder * i;
		i = i * 2;
		binaryval = binaryval / 10;
	}

	if (base == 8)
		printf("%lo", converted);
	else if (base == 16)
		printf("%lX", converted);
	else
		printf("You've entered wrong base");

	return 0;
}