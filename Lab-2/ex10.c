#include <stdio.h>
#include <conio.h>

int main()
{
	int tab[10][10], temp, x;

	scanf("%d", &x);

	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			scanf("%d", &tab[i][j]);
		}
	}

	for (int i = 0; i < x; ++i)
	{
		temp = tab[i][i];
		tab[i][i] = tab[i][x-i-1];
		tab[i][x-i-1] = temp;
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