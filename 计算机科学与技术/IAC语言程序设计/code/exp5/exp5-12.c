#include<stdio.h>
#define SIZE 100
void maze(int a[][SIZE], int b[][SIZE], int m, int n, int k, int l);
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);//输入迷宫的行和列
	int a[SIZE][SIZE];
	int i, j;
	for (i = 0; i < m; i++)//手动输入迷宫
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	int b[SIZE][SIZE] = { 0 };
	maze(a, b, m, n, 0, 0);
	return 0;
}
void maze(int a[][SIZE], int b[][SIZE], int m, int n,int k,int l)
{
	b[0][0] = 1;
	if (k == m - 1 && l == n - 1)
	{
		int i, j;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				printf("%d", b[i][j]);
				if (j == n - 1)
				{
					printf("\n");
				}
				else
				{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	else
	{
		if (a[k + 1][l] == 1&&b[k+1][l]==0)
		{
			k++;
			b[k][l] = 1;
			maze(a, b, m, n, k, l);
			b[k--][l] = 0;
		}
		if (a[k - 1][l] == 1 && b[k - 1][l] == 0)
		{
			k--;
			b[k][l] = 1;
			maze(a, b, m, n, k, l);
			b[k++][l] = 0;
		}
		if (a[k][l+1] == 1 && b[k][l+1] == 0)
		{
			l++;
			b[k][l] = 1;
			maze(a, b, m, n, k, l);
			b[k][l--] = 0;
		}
		if (a[k][l - 1] == 1 && b[k][l - 1] == 0)
		{
			l--;
			b[k][l] = 1;
			maze(a, b, m, n, k, l);
			b[k][l++] = 0;
		}
	}
}