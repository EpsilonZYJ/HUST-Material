#define _CRT_SECURE_NO_WARNINGS

# include<stdio.h>
# define M 5
# define N 3

#undef M
#undef N

int main(void)
{
    int M;
    int N;
    scanf("%d%d", &M, &N);
    int a[30], b[30];
    int i, j, k;
    for (i = 0; i < M; i++)
        a[i] = i + 1;
    for (i = M, j = 0; i > 1; i--)
    {
        for (k = 1; k <= N; k++)
            if (++j > i - 1) j = 0;
        b[M - i] = j ? a[j-1]: a[i-1];
        if (j)
            for (k = --j; k < i; k++)
                a[k]=a[k+1];
    }
    for (i = 0; i < M - 1; i++)
        printf("%6d", b[i]);
    printf("\n");
    printf("%6d\n", a[0]);
    return 0;
}