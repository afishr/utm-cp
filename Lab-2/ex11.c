#include <stdio.h>
#include <conio.h>

int main()
{
	int tab[100], x, count[100], l = 0, max = 0;

	scanf("%d", &x);

	for (int k = 0; k < x; ++k)
	{
		scanf("%d", &tab[k]);
		count[k] = 1;
	}

	for (int i = 1; i < x; ++i)
	{

		if (tab[i-1] < tab[i])
		{
			count[l]++;
		}
		else
		{
			l++;
		}
	}

	for (int j = 0; j < x; ++j)
	{
		if (max < count[j])
			max = count[j];
	}

	printf("%d", max);



	_getch();
	return 0;
}