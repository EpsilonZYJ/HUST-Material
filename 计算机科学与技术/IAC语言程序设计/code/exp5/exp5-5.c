#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define N 10
#define M 4
#define MAX 1000005

#undef M
#undef N

typedef long long Elemtype;

typedef struct {
	Elemtype circle[MAX];
	Elemtype length;
}SqList;

SqList L;


void josephus(long long n, long long m, long long pos, long long N)
{
	int cnt;
	while (L.length > 1)
	{
		for (cnt = 1; cnt <= m; pos++)
		{
			pos = pos % N;
			if (L.circle[pos] == 0)
			{
				cnt++;
			}
		}
		L.circle[pos - 1] = 1;
		L.length--;
	}
}

int main(void)
{
	long long i;
	long long N;
	long long M;
	scanf("%lld%lld", &N, &M);
	L.length = N;
	josephus(N, M, 0, N);
	for ( i = 0; L.circle[i]; i++)
	{
		;
	}
	printf("%lld", i + 1);
	return 0;
}