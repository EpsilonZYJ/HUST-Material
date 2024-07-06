#include<stdio.h>

/**
  请使用递归定义此函数，将输入的一行字符逆序输出。
  字符的输入和输出用getchar和putchar函数
 **/
void myrever(void)
{
	/**********  Begin  **********/
       int i = 0;
    int j = 0;
    char c;
    char s[10050];
    char q[10050];
    for (i = 0;(c= getchar()) != '\n';i++){
      s[i] = c;
    }
    int m = i;
    for(j = 0;i >= 0;j++,i--){
      q[i-1] = s[j];
    }
    q[m] = '\0';
    printf("%s",q);
    
    /**********  End  **********/
}