#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct node
{ ElemType data;
    struct node *next;
} NODE,*LinkList;

void TriLinkList(LinkList  A,LinkList  B,LinkList  C)
{
    /*
     *      Init
     */
    LinkList repeat = (LinkList) malloc(sizeof(NODE));
    LinkList rp_tail = repeat;
    LinkList pa = A;
    LinkList pb = B;
    LinkList pc = C;
    repeat->next = NULL;
    NODE* pa_prior = A;

    /*
     * Find the repeated elements.
     */
    pb = pb->next;
    pc = pc->next;
    while(pb && pc)
    {
        if (pb->data >  pc->data)   pc = pc->next;
        else if (pb->data < pc->data)   pb = pb->next;
        else{
            NODE* s = (NODE*) malloc(sizeof(NODE));
            s->data = pb->data;
            pb = pb->next;
            pc = pc->next;
            s->next = rp_tail->next;
            rp_tail->next = s;
            rp_tail = rp_tail->next;
        }
    }

    /*
     * Delete the repeated element.
     */
    if (rp_tail == repeat)
        return;
    pa = pa->next;
    rp_tail = repeat->next;
    while (pa && rp_tail)
    {
        if (rp_tail->data > pa->data){
            pa = pa->next;
            pa_prior = pa_prior->next;
        }
        else if (rp_tail->data < pa->data)  rp_tail = rp_tail->next;
        else{
            pa_prior->next = pa->next;
            free(pa);
            pa = pa_prior->next;
            rp_tail = rp_tail->next;
        }
    }

    /*
     * Free the repeated element.
     */
    rp_tail = repeat->next;
    while (rp_tail){
        free(repeat);
        repeat = rp_tail;
        rp_tail = rp_tail->next;
    }
    free(repeat);
    repeat = pa = pb = pc = pa_prior = NULL;

}

int main()
{
    LinkList L[3],p;
    ElemType x;
    int i;
    for(i=0;i<3;i++)
    {
        L[i]=p=(NODE *)malloc(sizeof(NODE));
        scanf("%d",&x);
        while (x)
        {
            p->next=(NODE *)malloc(sizeof(NODE));
            p=p->next;
            p->data=x;
            scanf("%d",&x);
        }
        p->next=NULL;
    }
    TriLinkList(L[0],L[1],L[2]);
    for(p=L[0]->next;p;p=p->next)
        printf(" %d",p->data);
    return 0;
}

