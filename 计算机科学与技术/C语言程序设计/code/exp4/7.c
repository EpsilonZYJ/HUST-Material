#include<stdio.h>
void isPerfect(int n)
//请完成isPerfect函数，判断整数n是否为完全数
{
/**********   Begin   **********/
	int sum = 1;
char a[30];
int n0 = n;

//a[0] = '0' + n;
//a[1] = '=';
//a[2] = '1';

int point=0;

a[point++] = '=';
a[point++] = '1';

for (int i = 2; i < n; i++)
{
	/*if (isPrime(i))
	{*/
		if (n%i==0)
		{
			sum += i;
			a[point++] = '+';
			int i0 = i;
			char b[10];
			int m = 0;
			while (i0)
			{
				b[m++] = '0' + i0 % 10;
				i0 /= 10;
			}
			m--;
			while (m>=0)
			{
				a[point++] = b[m--];

			}

		}
	/*}*/
}
a[point] = '\0';
if (sum==n)
{	
	printf("%d", n);
	printf("%s", a);
}
else
{
	printf("%d is not a perfect number", n);
}


/**********    End    **********/
}

