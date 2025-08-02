#include<stdio.h>

int main() {
	long long i=0;
	long long n = 0;
	long long cnt = 0;
	long long n1 = 0;
	scanf("%d", & n);
	n1 = n;
	while (n)
	{
		i += n % 10;
		n /= 10;
		cnt++;
	}
	printf("%d是%d位数，且各位数字之和为%d。",n1, cnt, i);
	return 0;

}