#include <stdio.h>
#include <math.h>

int main()
{

	long int init, decimal = 0;
	int i = 0, base;

	scanf("%ld %d", &init, &base);
	while (init != 0)
	{
		decimal += (init % 10) * pow(base, i++);
		init /= 10;
	}
	printf("%ld",decimal);
	return 0;
}