/* 实验6程序完善与修改替换第（1）题源程序：字符串升序排序 */
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h> 
#include<string.h>


#define N 4
#undef N
#define MAXLINE 100
/* 对指针数组s指向的size个字符串进行升序排序 */
void strsort(char* s[], int size)
{
    char* temp;
    int i, j;
    //for (i = 0; i < size; i++)  puts(s[i]);
    //puts("\n------before-----\n");
    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (strcmp(s[j],s[j+1])>0)
            {
                temp = s[j];
                s[j] = s[j+1];
                s[j + 1] = temp;
            }
}

int main()
{
    int N;
    scanf("%d", &N);
    getchar();
    int i;
    char* s[MAXLINE], t[50];
    for (i = 0; i < N; i++)
    {
        gets(t);
        s[i] = (char*)malloc(2000);
        strcpy(s[i],t);
    }
    strsort(s,N);
    for (i = 0; i < N; i++)  puts(s[i]);
    return 0;
}