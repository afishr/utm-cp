#include <stdio.h>
#include <conio.h>

int main()
{
	int n, tab[100], index = 99, sum = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &tab[i]);

		if (tab[i] < 0 && index == 99)
			index = i;

		if (i > index)
			sum += tab[i];
	}

	printf("\n%d", sum);

	_getch();
	return 0;
}