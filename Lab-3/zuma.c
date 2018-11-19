#include <stdio.h>
#include <stdlib.h>

int strlength (char* str)
{
	int k = 0;
	while (str[k] != '\0')
	{
		k++;
	}
	return k;
}

int isStreak(char const *line, int len)
{
	int i = 0, streak = 0, flag = 0;
	while (line[i] != '0')
		i++;

	char c = line[i-1];

	for (int j = 0; j <= len; ++j)
	{
		if (line[j] == '0')
			flag = 1;

		if (line[j] == c || line[j] == '0')
		{
			if (line[j] == c)
				streak++;
		}
		else
		{
			if (line[j-1] == '0' && line[j] != c)
				break;

			if (flag && streak > 2)
				return 1;

			streak = 0;
			flag = 0;
		}
	}

	return 0;
}

int main()
{
	FILE *fin, *fout;

	fin = fopen("zuma.in", "r");

	int n;
	fscanf(fin, "%d", &n);
	char *str = malloc(201);
	n--;

	fscanf(fin, "%s", str);

	fclose(fin);

	int len = strlength(str);
	char tmp = str[n];
	int l = n, r = n + 1;

	if (str[n+1] == tmp && str[n-1] == tmp)
	{
		while (str[l] == tmp)
		{
			str[l] = '0';
			l--;
		}

		while (str[r] == tmp)
		{
			str[r] = '0';
			r++;
		}
	}


	while (isStreak(str, len))
	{
		int i = 0;
		while (str[i] != '0')
			i++;


		l = i-1, r = i+3;
		char c = str[l];

		while (str[l] == c || str[l] == '0')
		{
			str[l] = '0';
			l--;
		}

		while (str[r] == c || str[r] == '0')
		{
			str[r] = '0';
			r++;
		}
	}


	fout = fopen("zuma.out", "w");

	for(int i = 0; i < len; i++)
		if (str[i] != '0')
			fprintf(fout, "%c", str[i]);

	fclose(fout);

	free(str);

	return 0;
}