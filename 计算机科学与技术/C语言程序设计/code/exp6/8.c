#include<stdio.h>

#define MAXLINE 50

typedef struct
{
	int before[MAXLINE][MAXLINE];
	int after[MAXLINE][MAXLINE];
	int hang;
	int lie;
}Matrix;

void CreateMatrix(Matrix* m)
{
	for (int i = 0; i < m->hang; i++)
	{
		for (int j = 0; j < m->lie; j++)
		{
			scanf("%d", &(m->before[i][j]));
		}
	}
	return;
}

void TurnMatrix(Matrix* m)
{
	for (int i = 0; i < m->hang; i++)
	{
		for (int j = 0; j < m->lie; j++)
		{
			m->after[m->lie - j - 1][i] = m->before[i][j];
		}
	}
}

void PrintAfMatrix(Matrix* m)
{
	for (int i = 0; i < m->lie; i++)
	{
		for (int j = 0; j < m->hang; j++)
		{
			printf("%d", m->after[i][j]);
			if (j!=m->hang-1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main(void)
{
	Matrix m;
	scanf("%d%d", &m.hang, &m.lie);
	CreateMatrix(&m);
	TurnMatrix(&m);

	PrintAfMatrix(&m);

	return 0;
}