#include<stdio.h>

#define MAXLINE 500

typedef struct
{
	int before[MAXLINE][MAXLINE];
	int after[MAXLINE][MAXLINE];
	int hang;
	int lie;
}Matrix;

void CreateMatrix(Matrix* m,const char* filename)
{
	FILE* fp_in = fopen(filename, "r+");
	fscanf(fp_in, "%d %d", &(m->hang), &(m->lie));
	for (int i = 0; i < m->hang; i++)
	{
		for (int j = 0; j < m->lie; j++)
		{
			fscanf(fp_in,"%d", &(m->before[i][j]));
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
	FILE* fp_out = fopen("matrix.out", "w+");
	for (int i = 0; i < m->lie; i++)
	{
		for (int j = 0; j < m->hang; j++)
		{
			fprintf(fp_out, "%d", m->after[i][j]);
			if (j != m->hang - 1)
			{
				fprintf(fp_out, " ");
			}
		}
		fprintf(fp_out, "\n");
	}
}

int main(void)
{
	Matrix m;
    char file[100];
    scanf("%s",file);
	CreateMatrix(&m,file);
	TurnMatrix(&m);

	PrintAfMatrix(&m);

	return 0;
}