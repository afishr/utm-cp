#include <stdio.h>
#include <conio.h>

int main()
{
	int n, arr[100], max = 0, counter = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);

		if (arr[i] > max)
		{
			max = arr[i];
			counter = 0;
		}

		if (arr[i] == max)
			counter++;
	}


	printf("\n%d %d", max, counter);

	_getch();
	return 0;
}