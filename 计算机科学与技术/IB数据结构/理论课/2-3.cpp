#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 5000
#define LISTINCREMENT 10
typedef int ElemType;
typedef struct
{ ElemType *elem;
    int length;
    int listsize;
} SqList;

void  TriSqList(SqList  &A,SqList  B,SqList  C)
{
    ElemType *pa, *pb, *pc, *p, *p0;
    p0 = (ElemType*) malloc(sizeof(ElemType)*(B.length > C.length ? B.length : C.length));
    p = p0;
    int length = 0;
    pa = A.elem;
    pb = B.elem;
    pc = C.elem;
    while(pb <= B.elem + B.length - 1 && pc <= C.elem + C.length - 1)
    {
        if(*pb < *pc)   pb ++;
        else if(*pb > *pc)  pc ++;
        else{
            *(p0 + length) = *pb;
            length ++;
            pb ++;
            pc ++;
        }
    }
    B.length = 0;
    while(p <= p0 + length - 1 && pa <= A.elem + A.length - 1)
    {
        if(*p > *pa)
        {
            B.elem[B.length ++] = *pa;
            pa ++;
        }
        else if(*p < *pa)
        {
            p ++;
        }
        else
        {
            pa ++;
            p ++;
        }
    }
    while(pa <= A.elem + A.length - 1)
    {
        B.elem[B.length ++] = *pa;
        pa ++;
    }
    A.length = 0;
    while(A.length < B.length)
    {
        A.elem[A.length] = B.elem[A.length];
        A.length ++;
    }
}

int main()
{
    SqList L[3];
    ElemType x;
    int i;
    for(i=0;i<3;i++)
    {
        L[i].elem=(ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
        L[i].length=0;
        L[i].listsize=LIST_INIT_SIZE;
        scanf("%d",&x);
        while (x)
        {
            L[i].elem[L[i].length++]=x;
            scanf("%d",&x);
        }
    }
    TriSqList(L[0],L[1],L[2]);
    for(i=0;i<L[0].length;i++)
        printf(" %d",L[0].elem[i]);
    return 0;
}

