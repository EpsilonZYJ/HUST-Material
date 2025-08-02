#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main(void)
{
	int x;
	scanf("%d", &x);
	int n = 0;
	int m = 0;
	int a[11];
	//int b[6];

	enum state
	{
		dif, same
	};
	enum state st;
	st = dif;
	for (int n0 = 1234; n0 <= 98765; n0++)
	{
		st = dif;
		n = n0;
		m = n / x;
		if (m * x == n)
		{
			for (int i = 4; i >= 0; i--)
			{
				a[i] = n % 10;
				n /= 10;
			}
			for (int i = 0; i <= 4; i++)
			{
				for (int j = i+1; j <= 4; j++)
				{
					if (a[i] == a[j])
					{
						st = same;
						break;
					}
				}
				if (st == same)
				{
					break;
				}
			}
			if (st == same)
			{
				continue;
			}
			else
			{
				for (int j = 9; j >= 5; j--)
				{
					a[j] = m % 10;
					m /= 10;
				}
				for (int i = 0; i <= 9; i++)
				{
					for (int j = i+1; j <= 9; j++)
					{
						if (a[i] == a[j])
						{
							st = same;
							break;
						}
					}
					if (st == same)
					{
						break;
					}
				}	
				if (st == dif)
				{
					printf("%d%d%d%d%d/%d%d%d%d%d=%d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7],a[8], a[9], x);
				}
				if (st == same)
				{
					continue;
				}
				
			}
		}
		
	}



	return 0;
}