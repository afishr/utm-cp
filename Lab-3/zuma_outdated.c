#include <stdio.h>
#include <stdlib.h>

int strlength (char* const str)
{
	int k = 0;
	while (str[k] != '\0')
	{
		k++;
	}
	return k;
}

_Bool thereIsStrike(char const *line, int len)
{
	_Bool flag = 0;
	int streak = 1, z_streak = 0;

	for (int i = 1; i < len; i++)
	{
		if (line[i] == '0')
		{
			flag = 1;
			z_streak++;
		}

		if (line[i-1] == line[i] || line[i] == '0')
		{
			streak++;
		}
		else
		{
			if (line[i] == line[i-z_streak-1])
				z_streak--;

			if (flag && streak - z_streak > 2)
			{
				return 1;
			}
			flag = 0;
			streak = 1;
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


	while (thereIsStrike(str, len))
	{
		_Bool flag = 0;
		int start = 0, end = 0, streak = 1, z_streak = 0;

		for (int i = 1; i < len; i++)
		{
			if (str[i] == '0')
			{
				flag = 1;
				z_streak++;
			}

			if (str[i-1] == str[i] || str[i] == '0')
			{
				streak++;
			}
			else
			{
				if (str[i] == str[i-z_streak-1])
					z_streak--;

				if (flag && streak - z_streak > 2)
				{
					end = i;
					start = end - streak;

					if (str[i-1] == '0')
						end++;

					for (int j = start; j < end; j++)
					{
						str[j] = '0';
					}
					break;
				}
				flag = 0;
				streak = 1;
			}

		}
	}



	/*fout = fopen("zuma.out", "w");

	for(int i = 0; i < len; i++)
		if (str[i] != '0')
			fprintf(fout, "%c", str[i]);*/

	for(int i = 0; i < len; i++)
//		if (str[i] != '0')
			printf("%c", str[i]);

	free(str);

	return 0;
}