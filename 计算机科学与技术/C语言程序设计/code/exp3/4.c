#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int isPrime(int n);

int main()
{
	int n;
	int m;
	scanf("%d", &n);
	m = pow(10, n );
	enum state
	{
		Prime,notPrime
	};
	enum state num;
	for (int i = pow(10,n-1); i < m; i++)
	{
		num = notPrime;
		int n = i;
		while (n)
		{
			if (isPrime(n))
			{
				num = Prime;
				break;
			}
			else
			{
				n /= 10;
			}
		}
		if (num == notPrime) 
		{
			printf("%d ", i);
		}
	}
}

int isPrime(int n)
{
	int ret = 1;
	if (n==1)
	{
		ret = -1;
	}
	else if (ret==2)
	{
		ret = 1;
	}
	else if (ret==3)
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