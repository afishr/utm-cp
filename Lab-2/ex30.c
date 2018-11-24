#include <stdio.h>
#include <conio.h>
#include <memory.h>

int main()
{
	int tab[100], n;
	_Bool mask[100];

	memset(mask, 0, sizeof(mask)); // Filling array with zeroes

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", &tab[i]);


	int k = 0;
	while (1)
	{
		if (mask[k] == 1)
		{
			int sum = 0;
			for (int i = 0; i < n; ++i)
				sum += mask[i];

			if (k == 0 && sum == n)
				printf("circular");
			else
				printf("noncircular");

			break;
		}

		mask[k] = 1;
		k = (k + tab[k]) % n;
	}

	_getch();
	return 0;
}