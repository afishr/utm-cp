#include <stdio.h>
#include <conio.h>
#include <memory.h>


int main()
{
	int x, max = 0;
	scanf("%d", &x);
	int tab[x][x], counter[x*x];
	memset(counter, 0, x * x * sizeof(int));

	for (int i = 0; i < x; ++i)
		for (int j = 0; j < x; ++j)
			scanf("%d", &tab[i][j]);

	int k = 0;
	for (int i = 1; i < x - 1; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			if (tab[i][j] < tab[i-1][j] && tab[i][j] < tab[i+1][j])
			{
				counter[k]++;
			}
			else
			{
				k++;
			}
		}
	}

	for (int l = 0; l < k; ++l)
	{
		if (max < counter[l])
			max = counter[l];
	}

	printf("%d", max);

	_getch();
	return 0;
}
