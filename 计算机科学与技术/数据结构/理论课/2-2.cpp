#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef  struct  Dnode
{
    ElemType     data;
    struct  Dnode *prior,*next;
} *DuLinkList;

void  adjust(DuLinkList L)
{
    if (L->prior == L && L->next == L)
        return;
    DuLinkList L0 = (DuLinkList) malloc(sizeof(struct Dnode));
    DuLinkList p, q;
    L0->next = L0;
    L0->prior = L0;
    q = L0;
    p = L->next;
    while(p->next != L && p->next->next != L)
    {
        DuLinkList s = (DuLinkList) malloc(sizeof(struct Dnode));
        s->data = p->data;
        s->next = q->next;
        s->prior = q;
        q->next = s;
        q = q->next;
        p = p->next->next;
    }
    if (p->next == L)
    {
        /* n%2 == 1 */
        DuLinkList s = (DuLinkList) malloc(sizeof(struct Dnode));
        s->data = p->data;
        s->next = q->next;
        s->prior = q;
        q->next = s;
        q = q->next;

        p = p->prior;
        while (p != L)
        {
            s = (DuLinkList) malloc(sizeof(struct Dnode));
            s->data = p->data;
            s->next = q->next;
            s->prior = q;
            q->next = s;
            q = q->next;
            p = p->prior->prior;
        }
        L0->prior = s;
    }
    else if(p->next->next == L)
    {
        /* n%2 == 0*/
        DuLinkList s = (DuLinkList) malloc(sizeof(struct Dnode));
        s->data = p->data;
        s->next = q->next;
        s->prior = q;
        q->next = s;
        q = q->next;

        p = p->next;
        while (p != L)
        {
            s = (DuLinkList) malloc(sizeof(struct Dnode));
            s->data = p->data;
            s->next = q->next;
            s->prior = q;
            q->next = s;
            q = q->next;
            p = p->prior->prior;
        }
        L0->prior = s;
    }
    while (L->next != L)
    {
        DuLinkList pfree = L->next;
        L->next = pfree->next;
        free(pfree);
    }
    L0->prior->next = L;
    L->prior = L0->prior;
    L0->next->prior = L;
    L->next = L0->next;
    free(L0);
}


int main()
{
    DuLinkList L,p,tail;
    int n,i;
    L=tail=(DuLinkList)malloc(sizeof(struct Dnode));
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        p=(DuLinkList)malloc(sizeof(struct Dnode));
        scanf("%d",&p->data);
        tail->next=p;
        p->prior=tail;
        tail=p;
    }
    L->prior=tail;
    tail->next=L;
    adjust(L);
    p=L->next;
    while(p!=L)
    {
        printf(" %d",p->data);
        p=p->next;
    }
}
