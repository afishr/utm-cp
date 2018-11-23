#include <stdio.h>
#include <conio.h>

int main()
{
	int n, arr[100], counter = 0, min = 2147483647; // Initial value of min is the upper bound of the int var type

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);

		if (arr[i] < min)
		{
			min = arr[i];
			counter = 0;
		}

		if (arr[i] == min)
			counter++;
	}


	printf("\n%d %d", min, counter);

	_getch();
	return 0;
}