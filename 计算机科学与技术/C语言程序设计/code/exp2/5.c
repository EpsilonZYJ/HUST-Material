 #include<stdio.h>

int main(){
    unsigned short x,m,n;
    scanf("%x",&x);
    scanf("%hu",&m);
    scanf("%hu",&n);
    if(m>=0&&m<=15&&n>=1&&n<=16-m){
       x=((x>>m)<<(16-n));
       printf("%x",x);
    }
   return 0;
}