#include<stdio.h>
double mulx(double x, int n);
long fac(int n);

double sum(double x, int n)
{
	static double sum = 1;
	for (int i = 1; i <= n; i++)
	{
		sum += (double)mulx(x, i) / fac(i);
	}
	return sum;
}

double mulx(double x, int n)
{
	int i;
	double z = 1.0;
	for (i = 0; i < n; i++)
	{
		z = z * x;
	}
	return z;
}

long fac(int n)
{
	static long fa = 1;
	fa *= n;
	return fa;
}

int main()
{
	double x;
	int n;
	scanf("%lf%d", &x, &n);
	printf("The result is %lf", sum(x, n));
	return 0;
}