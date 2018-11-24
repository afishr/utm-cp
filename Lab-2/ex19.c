#include <stdio.h>
#include <conio.h>
#include <memory.h>

int main()
{

	int tab[10][10], n, sums[4], max = 0;
	int mask[10][10];


	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &tab[i][j]);
		}
	}

	memset(sums, 0, sizeof(sums));
	memset(mask, 0, sizeof(mask));

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = i + 1; j < n - i - 1 ; ++j)
		{
			mask[i][j] = 1;
			sums[0] += tab[i][j];
		}
	}

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = i + 1; j < n - i - 1 ; ++j)
		{
			mask[j][i] = 2;
			sums[1] += tab[j][i];
		}
	}

	for (int i = n - 1; i > n / 2 ; i--)
	{
		for (int j = n - i; j < i; ++j)
		{
			mask[i][j] = 3;
			sums[2] += tab[i][j];
		}
	}

	for (int i = n - 1; i > n / 2 ; i--)
	{
		for (int j = n - i; j < i; ++j)
		{
			mask[j][i] = 4;
			sums[3] += tab[j][i];
		}
	}

	for (int k = 0; k < 4; ++k)
	{
		if (sums[max] < sums[k])
			max = k;
	}

	printf("\n");

	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mask[i][j] == max + 1)
				printf("%d ", tab[i][j]);
			else
				printf("0 ");
		}
		printf("\n");
	}



	_getch();
	return 0;
}