#include <stdio.h>
#include <conio.h>
#include <memory.h>

int main()
{
	int tab[10][10], mask[10][10], max, min, rmax, rmin, cmax, n;

	memset(mask, 0, sizeof(mask));

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &tab[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		min = tab[0][i];
		max = tab[i][0];
		rmax = 0;
		rmin = 0;
		cmax = 0;

		for (int j = 0; j < n; j++)
		{
			if (max < tab[i][j])
			{
				max = tab[i][j];
				rmax = i;
				cmax = j;
			}
		}

		for (int j = 0; j < n; j++)
		{
			if (min > tab[j][cmax])
			{
				min = tab[j][cmax];
				rmin = j;
			}
		}

		if (rmax == rmin)
			mask[rmax][cmax] = 1;
	}

	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			if (mask[k][i] == 1)
				printf("[%d][%d] = %d", k, i, tab[k][i]);
		}
	}


	_getch();
	return 0;
}