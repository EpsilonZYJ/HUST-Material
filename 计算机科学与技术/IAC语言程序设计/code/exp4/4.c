#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

long long sum_fac(int n);

int main(void)
{
	int k;
	for (k = 1; k <= 20; k++)
		printf("k=%d the sum is %lld\n", k, sum_fac(k));
	return 0;
}
long long sum_fac(int n)
{
	long long fac = 1;
	if (n==1)
	{
		return 1;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			fac *= i;
		}
		return sum_fac(n - 1) + fac;
	}
}