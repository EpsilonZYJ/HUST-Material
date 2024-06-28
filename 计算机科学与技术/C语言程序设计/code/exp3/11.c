#include <stdio.h>
#include <math.h>

#define MAX 100000

int main()
{
    int i, j, a[MAX];
    int m;
    scanf("%d", &m);

    for (a[0] = a[1] = 0, i = 2; i < MAX; i++)  /* 数组初始化，先假定2~99都是素数 */
    {    
        a[i] = 1;     /* 数组下标值是被测数，用1标记素数 */
    }
    for (i = 2; i*i <= MAX; i++)  /* 从2开始，“筛掉”每个素数的倍数 */
    {    if (a[i]) {    /* 如果a[i]值为1，则i为素数 */
            for (j = i * i; j < MAX; j += i)  /* 从i倍的i开始“筛”,因为之前的倍数已被“筛掉” */
                a[j] = 0;   /* 元素值为0表示该元素下标值不是素数 */
        }
    }
    for (i = 2; i <= m; i++)
    {
        if (a[i] == 1 && a[i + 2] == 1)
        {
            printf("(%d,%d) ", i, i + 2);
        }
    }
    return 0;
}