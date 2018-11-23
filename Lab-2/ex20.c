#include <stdio.h>
#include <conio.h>
#include <memory.h>

int bn(int x)
{
	int numbers[10], temp = x, counter = 0, k = 0;
	_Bool flag;

	memset(numbers, -1, sizeof(numbers));

	while (temp != 0)
	{
		int t = temp % 10;
		flag = 0;

		for (int i = 0; i < 10; ++i)
		{
			if (t == numbers[i])
				flag = 1;
		}

		if (flag == 0)
		{
			numbers[k] = t;
			counter++;
		}
		k++;
		temp /= 10;
	}
	return counter;
}

int main()
{
	int num;

	scanf("%d", &num);

//	printf("%d", bn(num));

	if ( bn(num) <= 2 )
	{
		printf("%d", num);
	}
	else
	{
		int ns = num, s = bn(num);

		while (s > 2)
		{
			ns--;
			s = bn(ns);
		}

		int nd = num, d = bn(num);
		while (d > 2)
		{
			nd++;
			d = bn(nd);
		}

		if (num - ns <= nd - num)
			printf("%d", ns);
		else
			printf("%d", nd);
	}

	_getch();
	return 0;
}