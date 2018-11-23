#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int declen(char* str)
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

	scanf("%s", init);
	scanf("%d", &base);

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

		decimal += (temp) * pow(base, len--);
	}
	printf("%f",decimal);

	free(init);
	return 0;
}