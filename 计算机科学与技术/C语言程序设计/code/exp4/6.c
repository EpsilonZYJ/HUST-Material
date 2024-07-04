#include<stdio.h>
void goldbach(int n)
//请完成goldbach函数，将大于等于4的偶数n表示成两个素数的和。
{
/**********   Begin   **********/
enum state
{
	unfind,find
};
enum state st = unfind;

for (int i = 2; i <= n/2; i++)
{
	if (isPrime(i))
	{
		if (isPrime(n-i))
		{
			printf("%d=%d+%d", n, i, n - i);
			st = find;
		}
	}
	if (st==find)
	{
		break;
	}
}


/**********    End    **********/

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