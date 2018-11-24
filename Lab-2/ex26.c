#include <stdio.h>

int N;
int M;
int max_count = 0;

int countArr(int arr[N][M], int r, int c)
{
	int count = 0;
	if (r < N && arr[r][c])
	{
		for (int i = c; i >= 0 && arr[r][i]; --i)
		{
			arr[r][i] = 0;
			count += countArr(arr, r + 1, i) + 1;
		}
		for (int i = c + 1; i < M && arr[r][i]; ++i)
		{
			arr[r][i] = 0;
			count += countArr(arr, r + 1, i) + 1;
		}
	}
	if(max_count < count)
		max_count = count;
	return count;
}


int main()
{
	scanf("%d %d", &N, &M);
	int arr[N][M];

	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			scanf("%d", &arr[i][j]);

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(arr[i][j] != 2)
				arr[i][j] = 0;
		}
	}

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if (arr[i][j])
			{
				int temp = countArr(arr, i, j);
				if (temp > max_count)
					max_count = temp;
			}
		}
	}

	printf("%d", max_count);

	return 0;
}