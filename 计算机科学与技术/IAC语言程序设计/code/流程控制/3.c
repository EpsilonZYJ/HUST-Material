/********** Begin **********/
#include<stdio.h>

int main()
{
    int a,b = 0;
    char c[5];

    double result = 0;

    scanf("%d %d %s",&a,&b,c);
    if(c[0] == '+'){
        result = (double)(a+b);
    }
    else if(c[0] == '-')
    {
        result = (double)(a-b);
    }
    else if(c[0] == '*')
    {
        result = (double)(a*b);
    }
    else if(c[0] == '/')
    {
        result = (double)(a/b);
    }

    printf("%.1f",result);
}






/**********  End **********/
