/********** Begin **********/
#include<stdio.h>

int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);

    if(a > b){
        if(b>c || b == c ){
            printf("B %d",b);
        }
        else if(b<c && c<a){
            printf("C %d",c);
        }
        else if((b<c &&c>a)||a==c){
            printf("A %d",a);
        }
    }else if(a<b){
        if(b<=c){
            printf("B %d",b);
        }
        else if(b>c && c>a){
             printf("C %d",c);
        }
        else if((b>c && c < a)||c==a){
             printf("A %d",a);
        }
    }
    else if (a == b == c){
        printf("A %d",a);
    }
    else if(a == b){
        printf("A %d",a);
    }
    
    
}





/**********  End **********/
