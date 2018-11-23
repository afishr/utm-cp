#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#include <conio.h>

int main()
{
	int x;
	scanf("%d", &x);
	int size = ((int)sqrt(x) + 1);

	_Bool *mask = calloc((size_t)size, sizeof(_Bool));;

	mask[0] = 1;
	mask[1] = 1;

	for (int i = 2; i < size; ++i)
	{
		for (int j = i * 2; j <  size; j += i)
		{
			mask[j] = 1;
		}
	}

	int tab[size], k = 0;

	for (int i = 0; i < size; ++i)
	{
		if (mask[i] == 0)
		{
			tab[k] = i;
			k++;
		}
	}

	int counting[size], max = 0, maxin = 0;
	memset(counting, 0, (size_t)size * sizeof(int));

	free(mask);

	int i = 0;
	while (x != 1)
	{
		if (x % tab[i] != 0)
		{
			i++;
			continue;
		}
		x /= tab[i];
		counting[tab[i]]++;
	}

	for (int l = 0; l < size; ++l)
	{
		if (max <= counting[l])
		{
			max = counting[l];
			maxin = l;
		}
	}

	printf("%d", maxin);




	_getch();
	return 0;
}