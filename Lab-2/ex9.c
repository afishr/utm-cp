#include <stdio.h>
#include <conio.h>

int main()
{
	int tab[10][10], temp, x, k, q;

	scanf("%d", &x);
	scanf("%d %d", &k, &q);

	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			scanf("%d", &tab[i][j]);
		}
	}

	for (int i = 0; i < x; ++i)
	{
		temp = tab[k][i];
		tab[k][i] = tab[i][q];
		tab[i][q] = temp;
	}

	printf("\n");

	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			printf("%d ", tab[i][j]);
		}
		printf("\n");
	}

	_getch();
	return 0;
}