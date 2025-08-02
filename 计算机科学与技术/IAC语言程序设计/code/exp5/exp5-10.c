#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define MAX 100

typedef int ElemType;

static int plot[2][200];
static int i0=0;

typedef struct {
	ElemType a[MAX][MAX];
	int hang;
	int lie;
}SqList;

void PrintList(SqList* L) {
	int cnt = 0;
	for (int i = 0; i < L->hang; i++)
	{
		for (int j = 0; j < L->lie; j++)
		{
			printf("%d", L->a[i][j]);
			cnt++;
			if (cnt%L->lie!=0)
			{
				printf(" ");
			}


		}
		printf("\n");
	}
}

void JudgeHang(SqList* L) {
	for (int i = 0; i < L->hang; i++)
	{
		for (int j = 0; j < L->lie; j++)
		{
			if (j+2<=L->lie&&L->a[i][j]==L->a[i][j+1]&&L->a[i][j]==L->a[i][j+2])
			{
				int flag = L->a[i][j];
				/*L->a[i][j] = 0;
				L->a[i][j + 1] = 0;*/
				plot[0][i0] = i;
				plot[1][i0] = j;
				i0++;
				plot[0][i0] = i;
				plot[1][i0] = j+1;
				i0++;
				j += 2;
				while (L->a[i][j] == flag)
				{
					//L->a[i][j] = 0;
					plot[0][i0] = i;
					plot[1][i0] = j;
					i0++;
					j++;
				}
			}
		}
	}
}

void JudgeLie(SqList* L) {
	for (int j = 0; j < L->lie; j++)
	{
		for (int i = 0; i < L->hang; i++)
		{
			if (i + 2 <= L->hang && L->a[i][j] == L->a[i + 1][j] && L->a[i][j] == L->a[i + 2][j])
			{
				int flag = L->a[i][j];
				/*L->a[i][j] = 0;
				L->a[i + 1][j] = 0;*/
				plot[0][i0] = i;
				plot[1][i0] = j;
				i0++;
				plot[0][i0] = i + 1;
				plot[1][i0] = j;
				i0++;
				i += 2;
				while (L->a[i][j] == flag)
				{
					//L->a[i][j] = 0;
					plot[0][i0] = i;
					plot[1][i0] = j;
					i0++;
					i++;
				}
			}
		}
	}
}

void ChangeList(SqList* L)
{
	for (int i = 0; i < i0; i++)
	{
		L->a[plot[0][i]][plot[1][i]] = 0;
	}
}


int main(void)
{
	SqList  L;
	scanf("%d%d", &L.hang, &L.lie);

	for (int i = 0; i < L.hang; i++)
	{
		for (int j = 0; j < L.lie; j++)
		{
			scanf("%d", &L.a[i][j]);
		}
	}

	JudgeHang(&L);
	JudgeLie(&L);
	ChangeList(&L);

	PrintList(&L);

}