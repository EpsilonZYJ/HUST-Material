#include<stdio.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d", &n);
	int m = pow(10, n);

	long square = 0;
	for (int i = pow(10,n-1); i < m; i++)
	{
		square = pow(i, 2);
		square = square % m;
		if (square==i)
		{
			printf("%d ", i);
		}
	}

	return 0;
}