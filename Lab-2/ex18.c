#include <stdio.h>
#include <conio.h>
#include <memory.h>

int main()
{

	int tab[10][10], n, sums[4];
	//int mask[10][10];

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &tab[i][j]);
		}
	}

//	memset(mask, 0, sizeof(mask));
	memset(sums, 0, sizeof(sums));

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = i + 1; j < n - i - 1; ++j)
		{
			//mask[i][j] = 1;
			sums[0] += tab[i][j];
		}
	}

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = i + 1; j < n - i - 1; ++j)
		{
			//mask[j][i] = 2;
			sums[1] += tab[j][i];
		}
	}

	for (int i = n - 1; i > n / 2; i--)
	{
		for (int j = n - i; j < i; ++j)
		{
			//mask[i][j] = 3;
			sums[2] += tab[i][j];
		}
	}

	for (int i = n - 1; i > n / 2; i--)
	{
		for (int j = n - i; j < i; ++j)
		{
			//mask[j][i] = 4;
			sums[3] += tab[j][i];
		}
	}

	/*for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d ", mask[i][j]);
		}
		printf("\n");
	}*/

	/*for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (mask[i][j] == 0)
				continue;
			sums[ mask[i][j] - 1 ] += tab[i][j];
		}
	}*/

	for (int k = 0; k < 4; ++k)
	{
		printf("%d = %d\n", k + 1, sums[k]);
	}


	_getch();
	return 0;
}