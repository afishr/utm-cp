#include <stdio.h>
#include <conio.h>

int main()
{
	int n, tab[10][10], sum = 0;

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
		for (int j = i + 1; j < n; j++)
		{
			sum += tab[j][i];
		}
	}

	printf("\n%d", sum);

	_getch();
	return 0;
}