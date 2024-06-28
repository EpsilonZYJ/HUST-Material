#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	if (n==1)
	{
		printf("1");
	}
	else if (n==2)
	{
		printf("  1\n");
		printf("1   1");
	}
	else if (n==3)
	{
		printf("    1\n");
		printf("  1   1\n");
		printf("1   2   1");
	}
	else
	{
		for (int i = 0; i <= n; i++)
		{
			for (int h = 0; h < 2*(n-i); h++)
			{
				printf(" ");
			}
			for (int j = 0; j <= i; j++)
			{
				printf("%-4d", C(i, j));
			}
			printf("\n");
		}
	}
}

int C(int i,int j)
{
	if (j==0)
	{
		return	1;
	}
	else
	{
		return (C(i, j-1) * (i - j + 1) / j);
	}
}