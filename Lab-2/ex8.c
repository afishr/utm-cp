#include <stdio.h>
#include <conio.h>

int main()
{
	int tab[10][10], nill[10], x;

	scanf("%d", &x);

	for (int i = 0; i < x; ++i)
	{
		nill[i] = 1;
		for (int j = 0; j < x; ++j)
		{
			scanf("%d", &tab[i][j]);

			if (tab[i][j] == 0)
				nill[i] = 0;
 		}
	}

	for (int i = 0; i < x; ++i)
	{
		if (nill[i])
		{
			printf("\n");
			for (int j = 0; j < x; ++j)
			{
				printf("%d ", tab[i][j]);
			}
		}
	}

	_getch();
	return 0;
}