/********** Begin **********/
#include<stdio.h>
int f(int n);
int main()
{
    int n = 0;
    scanf("%d",&n);
    int j = 0;
    int k = 0;
    int i = 0;
    j = n/8;
    k = n%8;

    for(i = 0;i < j; ++i){
        printf("%10d%10d%10d%10d%10d%10d%10d%10d\n",f(i*8+1),f(i*8+2),f(i*8+3),f(i*8+4),f(i*8+5),f(i*8+6),f(i*8+7),f(i*8+8));
    }

    for(i = n - k + 1;i <= n;++i){
        printf("%10d",f(i));
    }

}

int f(int n)
{
    int a = 1;
    int b = 1;
    int c;
    int i = 0;
    int ret = 0;

    if(n == 1 || n == 2){
        ret = 1;
    }
    else {
        for(i = 0;i < n - 2;++i){
            c = a + b;
            a = b;
            b = c;
            ret = c;
        }
    }
    return ret;
}




/**********  End **********/
