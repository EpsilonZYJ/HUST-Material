#include "stdio.h"
#include "stdlib.h"

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define YES 1
#define NO 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;
typedef int KeyType;
typedef struct {
    KeyType  key;
    char others[20];
} TElemType; //二叉树结点类型定义


typedef struct BiTNode{  //二叉链表结点的定义
    TElemType  data;
    struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;

void Merge(int a[], int *vec, int low, int mid, int high)
{
    int i, j, k;
    for(k=low; k<=high; k ++)
        vec[k] = a[k];
    for(i=low, j=mid+1, k=i; i<=mid && j <=high; k++){
        if(vec[i] <= vec[j])
            a[k] = vec[i++];
        else
            a[k] = vec[j++];
    }
    while(i<=mid) a[k++] = vec[i++];
    while(j<=high) a[k++] = vec[j++];
}

void MSort(int a[], int *vec, int low, int high)
{
    if(low<high){
        int mid = (low + high)/2;
        MSort(a, vec, low, mid);
        MSort(a, vec, mid+1, high);
        Merge(a, vec, low, mid, high);
    }
    return;
}

void sort(int a[],int n,int k)
//将a中元素递增排序
{
    int *vec = (int*) malloc(n * sizeof(int));
    MSort(a, vec, 0, n-1);
}

int main()
{
    int a[100], n, k,i;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,n,k);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

}