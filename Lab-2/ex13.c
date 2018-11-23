#include <stdio.h>
#include <conio.h>

int main()
{
	int tab[24], last_streak = 1, current_streak = 1, n;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &tab[i]);
	}

	for (int j = 1; j < n; ++j)
	{
		if (tab[j-1] == tab[j])
		{
			current_streak++;
		}
		else
		{
			if (last_streak >= current_streak)
			{
				current_streak = 1;
			}
			else
			{
				last_streak = current_streak;
				current_streak = 1;
			}
		}
	}

	printf("%d", last_streak >= current_streak ? last_streak : current_streak);

	_getch();
	return 0;
}