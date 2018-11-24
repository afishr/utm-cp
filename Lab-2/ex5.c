#include <stdio.h>
#include <conio.h>

int main()
{
	int n, tab[100], counter = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &tab[i]);
	}

	for (int j = 0; j < n; ++j)
	{
		if (j == 0)
			continue;

		if ((tab[j] > 0 && tab[j-1] < 0) || (tab[j] < 0 && tab[j-1] > 0))
			counter++;
	}

	printf("\n%d", counter);

	_getch();
	return 0;
}