#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define N 30

struct s_list {
    int data;
    struct s_list* next;
};

void create_list(struct s_list** headp, int* p);

int main(void) {
    struct s_list* head = NULL, * p;
    int s[N];
    int* sp = s;
    int i = 0;
    while (scanf("%d",sp+i)&&*(sp+i)!=0)
    {
        i++;
    }
    create_list(&head, s);
    p = head;
    while (p) {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
    return 0;
}

void create_list(struct s_list** headp, int* p) {
    struct s_list* loc_head = NULL, * tail;
    if (p[0] == 0);
    else {
        loc_head = (struct s_list*)malloc(sizeof(struct s_list));
        loc_head->data = *p++;
        tail = loc_head;
        while (*p)
        {
            tail->next = (struct s_list*)malloc(sizeof(struct s_list));
            tail = tail->next;
            tail->data = *p++;
        }
        tail->next = NULL;

    }
    *headp = loc_head;
}
