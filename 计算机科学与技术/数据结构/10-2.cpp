#include "stdio.h"
#include "stdlib.h"

void HeapAjust(int a[], int k, int len)
{
    a[0] = a[k];
    for (int i = 2*k; i <= len; i *= 2) {
        if(i < len && a[i] < a[i+1])
            i ++;
        if(a[0] >= a[i]) break;
        else{
            a[k] = a[i];
            k = i;
        }
    }
    a[k] = a[0];
}

void BuildHeap(int a[], int len)
{
    for(int i = len/2; i > 0; i --)
        HeapAjust(a, i, len);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int MidValue(int a[],int n)
//求a的中位数
{
    int *b = (int*) malloc((n + 1) * sizeof(int));
    for(int i = 0; i < n; i ++){
        *(b + i + 1) = a[i];
    }
    BuildHeap(b, n);
    int ans;
    if(n%2){
        for(int i = n; i >= n/2 + 2; i --){
            swap(b+i, b+1);
            HeapAjust(b, 1, i - 1);
        }
        ans = b[1];
        free(b);
    }
    else{
        int i;
        for(i = n; i >= n/2 + 2; i --){
            swap(b+i, b+1);
            HeapAjust(b, 1, i-1);
        }
        ans = b[1];
        swap(b+i, b+1);
        HeapAjust(b, 1, i-1);
        ans += b[1];
        ans /= 2;
        free(b);
    }
    return ans;
}

int main()
{
    int ans,*a,n,i;
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("%d",MidValue(a,n));
    free(a);
    return 1;
}