#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 20
#define LISTINCREMENT 10
typedef int ElemType;
typedef struct
{ ElemType *elem;
    int length;
    int listsize;
} SqList;

int insert(SqList &L,ElemType x)
{
    if (L.listsize == 0)
    {
        L.elem = (ElemType *) malloc(sizeof(ElemType) * LIST_INIT_SIZE);
        L.listsize = LIST_INIT_SIZE;
        if (L.elem == NULL)
        {
            return 0;
        }
    }
    else if (L.length == L.listsize)
    {
        L.elem = (ElemType *) realloc(L.elem, sizeof(ElemType ) * (L.listsize + LISTINCREMENT));
        L.listsize += LISTINCREMENT;
        if (L.elem == NULL)
        {
            return 0;
        }
    }
    int i;
    for (i = 0; i < L.length; ++i)
    {
        if(L.elem[i] > x)
            break;
    }
    for (int j = L.length - 1; j >= i; --j)
    {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i] = x;
    L.length += 1;
    return 1;
}


int main()
{
    SqList L;
    ElemType x;
    int i;
    L.elem=(ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    scanf("%d",&x);
    while (x)
    {
        L.elem[L.length++]=x;
        scanf("%d",&x);
    }
    scanf("%d",&x);
    insert(L,x);
    for(i=0;i<L.length;i++)
        printf("%8d",L.elem[i]);
    if (L.length>L.listsize) printf("\n程序未处理溢出");

    return 0;
}

