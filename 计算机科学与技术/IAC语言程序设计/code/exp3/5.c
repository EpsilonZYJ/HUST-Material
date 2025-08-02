#include<stdio.h>
int main()
{
    int x;
	scanf("%d",&x);
    int n=x/1000;
    int sum;
    switch(n){
        case 0:printf("0");break;
        case 1:sum=(x-1000)/20;
                printf("%d",sum);
                break;
        case 2: sum=50+(x-2000)/10;
                printf("%d",sum);
                break;
        case 3:sum =150+15*(x-3000)/100;
                printf("%d",sum);
                break;
        case 4:sum=300+(x-4000)/5;
                printf("%d",sum);
                break;
        default:sum=500+(x-5000)/4;
                printf("%d",sum);
                break;

    }
}