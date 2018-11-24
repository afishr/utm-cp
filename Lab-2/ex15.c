#include <stdio.h>
#include <conio.h>

int main()
{
	int n, k, tab[100], first[100];

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &tab[i]);
		first[i] = tab[i];
	}

	for (int l = 0; l < n - k; ++l)
	{
		tab[l] = tab[l+k];
	}

	for (int m = 0; m < k; ++m)
	{
		tab[(n-k)+m] = first[m];
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", tab[i]);
	}

	_getch();
	return 0;
}