/********** Begin **********/
#include<stdio.h>

void swap(int *a,int *b);

int main(){
    int i, j, k;
    int m, n;
    scanf("%d %d",&i,&j);
    n = i * j;
    if( j > i){
        swap(&i, &j);
    }
    do{
        k = i % j; 
        i = j;
        j = k;
    }while(k != 0);

    m = i;
    n = n/i;
    printf("%d %d",m,n);

}

void swap(int *a,int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}



/**********  End **********/
