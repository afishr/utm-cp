#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{

	long int decimal = 0;
	int base, temp;
	char* init = malloc(100);

	scanf("%s", init);
	scanf("%d", &base);


	int len = (int)(strlen(init)) - 1;

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

		decimal += (temp) * pow(base, len--);
	}
	printf("%ld",decimal);

	free(init);
	return 0;
}