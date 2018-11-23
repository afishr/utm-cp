#include <stdio.h>
#include <conio.h>

int main()
{
	FILE *fin, *fout;

	fin = fopen("Input\\1-kalah.in", "r");
	int n, m;
	fscanf(fin,"%d %d", &n, &m);

	int a[n], b[m], sb = 0; // sb - the sum of balls

	for (int i = 0; i < n; ++i) // reading the balls' amount in each box
	{
		fscanf(fin, "%d", &a[i]);
		sb += a[i];
	}

	for (int i = 0; i < m; ++i) // reading the number of moves
	{
		fscanf(fin, "%d", &b[i]);
	}
	fclose(fin);
	for (int i = 0; i < m; i++) // go through all moves
	{
		int j = b[i] - 1; // j is the last box on each move
		while (a[0] != sb) // while we don't collect all balls in first box
		{
			a[j]--; // take one ball from the j-th box and put it in the first one
			a[0]++;

			j--; // going through boxes counterclockwise

			if (j == -1) // if we got to the first box
				j = n - 1; // we go to the last box (In this way I simulate circular moving through boxes)
		}
	}
	fout = fopen("Output\\1-custom-kalah.out", "w");
	for (int k = 0; k < n; ++k) // displaying the content of all boxes
	{
		fprintf(fout, "%d\n", a[k]);
	}
	fclose(fout);


	_getch();
	return 0;
}