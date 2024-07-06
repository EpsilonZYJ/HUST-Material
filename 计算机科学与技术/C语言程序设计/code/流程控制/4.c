/********** Begin **********/
#include<stdio.h>

int main()
{
    int a,b = 0;
    char c[5];
    double result = 0;

    scanf("%d %d %s",&a,&b,c);

    switch(c[0]){
        case '+':result = (double)a + b;break;
        case '-':result = (double)a - b;break;
        case '*':result = (double)a * b;break;
        case '/':result = (double)a / b;break;
    }

    printf("%.1f",result);
}





/**********  End **********/
