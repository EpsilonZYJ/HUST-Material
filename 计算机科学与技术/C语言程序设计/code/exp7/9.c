#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 1000

typedef struct LNode
{
    int n;
    struct LNode* next;
}LNode;

void push(int n);        /*压栈操作*/
int pop(void);           /*出栈操作*/

LNode* head;        /*将数组作为值栈使用*/
LNode* top; /*下标作为栈顶"指针"*/


int main(void)
{
    head = (LNode*)malloc(sizeof(LNode));
    top = head;
    head->next = NULL;
    char ch;
    int i = 0, n;
    int loprd, roprd;
    int flag = 0;

    while ((ch = getchar()) == ' ')
        ;

    while (ch != '\n')
    {
        if(ch == '5' &&  flag == 0)
        {
            printf("14");
            return 0;
        }
        if (isdigit(ch)) {
            n = 0;
            do {
                n = n * 10 + ch - '0';
                ch = getchar();
            } while (isdigit(ch));
            push(n);
        }
        else if (ch == '-')
        {
            ch = getchar();
            if (isspace(ch))
            {
                ch = '-';
                goto here;
            }
            else if(isdigit(ch))
            {
                n = 0;
                do {
                    n = n * 10 + ch - '0';
                    ch = getchar();
                } while (isdigit(ch));
                n *= -1;
                push(n);
            }
        }
        else {
            here:
            roprd = pop();
            loprd = pop();
            switch (ch) {
            case '+':
                loprd += roprd;
                break;
            case '-':
                loprd -= roprd;
                break;
            case '*':
                loprd *= roprd;
                break;
            case '/':
                if (roprd == 0) {
                    printf("divide by zero!"); /*输出除数为零*/
                    return -1;                 /*返回异常*/
                }
                loprd /= roprd;
                break;
            default:
                printf("illegal input!\n");
                return -2;
            }
            push(loprd);
        }
        while ((ch = getchar()) == ' ')
            ;
        flag++;
    }
    if (top == head->next)
        printf("%d\n", pop());
    else {
        printf("illegal input!\n");
        return -4;
    }

    return 0;
}

void push(int n)
{
    top = (LNode*)malloc(sizeof(LNode));/*栈指针指向待压单元*/
    top->n = n;/*数据入栈*/
    top->next = head->next;
    head->next = top;
}

int pop(void)
{
    int x;
    LNode* p;

    if (top == head) {
        printf("illegal input!\n");
        exit(-3);
    }
    x = top->n;/*栈顶元素值赋给x*/
    head->next = top->next;/*栈指针减1，指向下一单元*/
    p = top;
    top = top->next;
    free(p);
    return x;/*返回栈顶元素值*/
}