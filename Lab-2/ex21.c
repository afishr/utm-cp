#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

/*
 * movestr - moves elements of array by one to left or to right
 * parameters - char* x: the string
 *              int direction: 0 - left, 1 - right
 *              int length: the length of string
 */
void moveStr(char *x, int direction, int length)
{
	char temp;

	if (direction == 0)
	{
		temp = x[0];

		for (int j = 1; j < length; ++j)
		{
			x[j-1] = x[j];
		}
		x[length-1] = temp;
	}
	else if (direction == 1)
	{
		temp = x[length-1];

		for (int j = length - 1; j >= 0; j--)
		{
			x[j] = x[j-1];
		}
		x[0] = temp;
	}
}


/*
 * isPalindrome - moves elements of array by one to left or to right
 * parameters - char* x: the string
 *              int length: the length of string
 */
_Bool isPalindrome(char* x, int length)
{
	for (int i = 0, j = length - 1; i < j; i++, j--)
	{
		if (x[i] != x[j])
			return 0;
	}
	return 1;
}

int main()
{
	FILE* fin;
	fin = fopen("00-kpal.in", "r");

	char *str;
	int countl = 0, countr = 0;
	str = malloc(200);
	fscanf(fin, "%s", str);
	int n = (int)strlen(str);
	fclose(fin);

	char *temp = malloc(200);
	memcpy(temp, str, 200);

	// Move string to left
	for (int i = 0; i < n; ++i)
	{
		if (isPalindrome(temp, n))
			break;

		moveStr(temp, 0, n);
		countl++;
	}

	// Move string to right
	for (int i = 0; i < n; ++i)
	{
		if (isPalindrome(str, n))
			break;

		moveStr(str, 1, n);
		countr++;
	}

	if (countl == n && countr == n)
		printf("-1");
	else
	{
		printf("%d\n", countl > countr ? countr : countl);
//		printf("%s", countl > countr ? str : temp);
	}
	free(str);
	_getch();
	return 0;
}