#include <stdio.h>
#include <conio.h>
#include <memory.h>
#include <math.h>

int main()
{
	int tab[1000], val[1000][3], n, mini = 0, min = 999999999, sum1 = 0, sum2 = 0;

	FILE *fi, *fo;

	fi = fopen("pang_x.in", "r");

	fscanf(fi, "%d", &n);

	for (int i = 0; i < n; ++i)
		fscanf(fi, "%d", &tab[i]);

	fclose(fi);

	for (int i = 1; i < n; ++i)
	{
		sum1 = 0;
		sum2 = 0;
		for (int j = 0; j < i; ++j)
		{
			sum1 += tab[j];
		}

		for (int j = i; j < n; ++j)
		{
			sum2 += tab[j];
		}

		val[i][1] = sum1;
		val[i][2] = sum2;
		val[i][0] = i;

//		printf("%d = %d - %d\n", i, sum1, sum2);
	}

	for (int i = 1; i < n; ++i)
	{

		if ( min > abs(val[i][1] - val[i][2]))
		{
			min = abs(val[i][1] - val[i][2]);
			mini = i;
		}
	}

	fo = fopen("pang_x.out", "w");

	fprintf(fo, "%d\n%d %d", mini, val[mini][1], val[mini][2]);

	fclose(fo);

	_getch();
	return 0;
}