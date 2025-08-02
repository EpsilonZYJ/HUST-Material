#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define MAX 100

typedef int ElemType;

typedef struct {
	ElemType a[MAX][MAX];
	int Length;
}Square;

void PrintSquare(Square* L) {
	int cnt = 0;
	for (int i = 0; i < L->Length; i++)
	{
		for (int j = 0; j < L->Length; j++)
		{
			printf("%d", L->a[i][j]);
			cnt++;
			if (cnt%L->Length!=0)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void MakeList(Square* L) {
	int n = L->Length;
	int num = 1;
	int left = 0;
	int right = (L->Length)-1;
	int top=0;
	int down = (L->Length)-1;
	while (num<=(L->Length)*(L->Length))
	{
		for (int i = left; i <= right; i++)
		{
			L->a[top][i] = num;
			num++;
		}
		for (int i = top+1; i <= down; i++)
		{
			L->a[i][right] = num;
			num++;
		}
		for (int i = right-1; i >= left; i--)
		{
			L->a[down][i] = num;
			num++;
		}
		for (int i = down-1; i >= top+1; i--)
		{
			L->a[i][left] = num;
			num++;
		}
		top++;
		down--;
		left++;
		right--;
	}
}

int main(void)
{
	Square L;
	scanf("%d", &L.Length);

	MakeList(&L);
	PrintSquare(&L);

	return 0;
}