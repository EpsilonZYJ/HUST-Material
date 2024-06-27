#include<stdlib.h>
/*测试程序定义了如下结点类型
typedef struct c_node{
    char data;  struct c_node *next;
} C_NODE;
*******************************/
void createLinkList(C_NODE **headp, char s[]) 
{
    *headp = (C_NODE*)malloc(sizeof(C_NODE));
    C_NODE* p, * r;
    int i = 0;
    p = (*headp);
    p->data = s[i];
    i++;
    while (s[i] != '\0')
    {
        r = (C_NODE*)malloc(sizeof(C_NODE));
        r->data = s[i];
        p->next = r;
        p = r;
        i++;
    }
    p->next = NULL;
}

void judgePalindrome(C_NODE *head)
{
    typedef struct SqList
    {
        char s[100];
        int length;
    }SqList;
    SqList L;
    L.length = 0;
    int i = 0;
    int j = 0;
    //head = head->next;
    while (head != NULL)
    {
        L.s[i] = head->data;
        L.length++;
        i++;
        head = head->next;
    }
    i--;
    int flag = 1;
    while (j<=i)
    {
        if (L.s[j]==L.s[i])
        {
            ;
        }
        else
        {
            flag = 0;
            break;
        }
        j++;
        i--;
    }
    if (1 == flag)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
}
