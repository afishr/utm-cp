#include <stdio.h>
#include <conio.h>

int main()
{
	int tab[10][10], x, sum;

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
		sum = 0;
		for (int j = 0; j < x; ++j)
		{
			sum += tab[j][i];
		}
		printf("%d\n", sum);
	}

	_getch();
	return 0;
}