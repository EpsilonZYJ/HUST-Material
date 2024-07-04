#include<stdio.h>

#define SIZE 100

int isPalindrome(char arr[], int len);

int main()
{
    /**** 输入字符串,调用函数isPalindrome判断是否为回文串，然后输出结果 *******/
    /**********  Begin ***********/
    char c;
    int i = 0;
    char s[SIZE];
    while ((c = getchar()) != EOF) {
        s[i] = c;
        i++;
    }
    if (isPalindrome(s, i) == 1) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }


    /**********  End  **********/
    return 0;
}

/**** 在下面编写满足任务要求的递归函数isPalindrome，是回文返回1，不是返回0 *******/
/**********  Begin ***********/
int isPalindrome(char arr[], int len) {
    int i = 0;
    int judge = 1;
    for (i = 0; i < len / 2; i++) {
        if (arr[i] == arr[len -1- i]) {
            ;
        }
        else {
            judge = 0;
            break;
        }
    }
    return judge;
}



/**********  End  **********/
