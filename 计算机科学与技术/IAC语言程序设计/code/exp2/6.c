#include<stdio.h>

int main(){
    unsigned long x;
    int n1,n2,n3,n4;
        while(scanf("%lu",&x)!=EOF){
        n1=x%256;
        x/=256;
        n2=x%256;
        x/=256;
        n3=x%256;
        x/=256;
        n4=x%256;
        printf("%d.%d.%d.%d\n",n4,n3,n2,n1);
        }
}