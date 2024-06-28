
#include<stdio.h>
#include<math.h>

int isPrime(int n);
int M(int n);

int main()
{
	int m;
	scanf("%d", &m);
	int i = 2;
	while (M(i) <= m)
	{
		if (isPrime(M(i)))
		{
			printf("M(%d)=%d\n",i, M(i));
		}
		i++;
	}
}

int M(int n)
{
	int m = pow(2, n) - 1;
	return m;
}

int isPrime(int n)
{
	int ret = 1;
	if (n == 1)
	{
		ret = -1;
	}
	else if (ret == 2)
	{
		ret = 1;
	}
	else if (ret == 3)
	{
		ret = 1;
	}
	else
	{
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (!(n % i))
			{
				ret = 0;
				break;
			}
		}
	}
	return ret;
}