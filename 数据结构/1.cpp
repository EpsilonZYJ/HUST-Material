#include "stdio.h"
#include "stdlib.h"

int suanfa(int a[],int n, int arrsize)
{
    if (n > arrsize) return 0;
    a[0] = 2;
    for (int i = 2; i <= n; ++i) {
        a[i - 1] = i * a[i - 2] * 2;
        if (a[i - 1] <= 0)
            return 0;
    }
    return 1;
}

int main()
{
    int k,*a,arrsize;
    scanf("%d%d",&k,&arrsize);
    a=(int *)malloc(arrsize*sizeof(int));
    if (suanfa(a,k,arrsize))
        for(int i=0;i<k;i++)
            printf(" %d",a[i]);
    else printf("ERROR");
    return 1;
}
