#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
	int n, tab[1000];


	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &tab[i]);


	// Insertion sort
	for (int i = 0; i < n; i++)
	{
		int j = i;
		while (j > 0 && tab[j] < tab[j-1])
		{
			// Swap tab[j] and tab [j-1]
			int t = tab[j];
			tab[j] = tab[j-1];
			tab[j-1] = t;
			j--;
		}
	}

	int min = 99999, minin = 0;
	for (int k = 0; k < n; ++k)
	{
		if (min >= abs(tab[k] - tab[k+1]))
		{
			min = abs(tab[k] - tab[k+1]);
			minin = k;
		}
	}

	printf("%d %d", tab[minin+1], tab[minin]);

	_getch();
	return 0;
}