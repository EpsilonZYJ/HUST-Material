#include "stdio.h"
typedef char ElemType;
#define MAXLENGTH 100
#define N 100
typedef struct TWSTACK {
    ElemType elem[N];
    int top1,top2;
} TWSTACK;
typedef struct QUEUE {
    ElemType elem[MAXLENGTH];
    int front,length;
} QUEUE;

void inistack(TWSTACK &S)
//该函数实现初始化S，得到2个空栈。根据双向栈的示意图，理解初始化要求。
{
    S.top1 = 0;
    S.top2 = N - 1;
    return;
}
int push(TWSTACK &S,int i,ElemType e)
//i取值1或2，分别对应左或右栈，将元素e压入S的对应栈。成功入栈返回1，否则返回0
{
    if(S.top1 == S.top2+1)
        return 0;
    if(i == 1){
        S.elem[S.top1 ++] = e;
        return 1;
    }
    else if(i == 2){
        S.elem[S.top2 --] = e;
        return 1;
    }
    else{
        return 0;
    }
}
int pop(TWSTACK &S,int i, ElemType &e)
//i取值1或2，分别对应左或右栈，将S对应栈的栈顶元素出栈，赋值给e。成功出栈返回1，否则返回0
{
    if(i == 1){
        if(S.top1 == 0)
            return 0;
        e = S.elem[-- S.top1];
        return 1;
    }
    else if(i == 2){
        if(S.top2 == N-1)
            return 0;
        e = S.elem[++ S.top2];
        return 1;
    }
}


void iniQueue(QUEUE &Q)
//该函数实现初始化Q
{
    Q.front = 0;
    Q.length = 0;
    return;
}
int enQueue(QUEUE &Q,ElemType e)
//将元素e入队Q。成功入栈返回1，否则返回0
{
    if(Q.length == MAXLENGTH)
        return 0;
    Q.elem[(Q.front + Q.length) % MAXLENGTH] = e;
    Q.length ++;
    return 1;
}
int deQueue(QUEUE &Q, ElemType &e)
//将Q队首元素出队，赋值给e。成功出队返回1，否则返回0
{
    if(Q.length == 0)
        return 0;
    e = Q.elem[Q.front];
    Q.front = (Q.front + 1) % MAXLENGTH;
    Q.length --;
    return 1;
}


int isPalindrome(char *str)
//判断字符串str是否回文，是则返回1，否则返回0
{
    QUEUE q;
    TWSTACK s;
    iniQueue(q);
    inistack(s);
    while(*str != '@'){
        enQueue(q, *str);
        push(s, 1, *str);
        str ++;
    }
    char q_c, s_c;
    while(deQueue(q, q_c) && pop(s, 1, s_c)){
        if(q_c != s_c)
            return 0;
    }
    return 1;
}

int main()
{
    char str[100];
    scanf("%s",str);
    printf("%s",isPalindrome(str)?"YES":"NO");
    return 0;
}