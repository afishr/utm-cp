#include <stdio.h>
#include <conio.h>

int gcd (int a, int b)
{
	int a1 = a, b1 = b, temp;

	while (b1 != 0)
	{
		a1 %= b1;

		temp = a1;
		a1 = b1;
		b1 = temp;
	}

	return a1;
}

int main()
{
	int n, cd, tab[100];

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &tab[i]);
	}

	cd = tab[0];

	for (int j = 1; j < n; ++j)
	{
		cd = gcd( (cd < tab[j] ? cd : tab[j]), (cd < tab[j]) ? tab[j] : cd);
	}

	printf("%d", cd);

	_getch();
	return 0;
}