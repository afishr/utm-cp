#include <stdio.h>
#include <conio.h>

int main()
{
	int tab[100], temp, n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tab[i]);
	}
	printf("\n");

	temp = tab[0];

	for (int j = 1; j < n; ++j)
	{
		tab[j-1] = tab[j];
	}
	tab[n-1] = temp;

	for (int i = 0; i < n; i++)
	{
		printf("%d ", tab[i]);
	}

	_getch();
	return 0;
}