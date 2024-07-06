#include<stdio.h>
#include<math.h>

int Pow(int x,int y);
double con(int n);

int main(){
    int i = 1;
    double n = 0;
    float e;
    scanf("%f",&e);
    do{
        if(i % 2){
        n += con(i);
        }
        else{
            n -= con(i);
        }
    }while(fabs(con(i++)) >= e);

    printf("%.6f",4.0*n);


    return 0;
}

double con(int n){
    double ret;
    int s = 0;
    s =2*n - 1;
    ret = (double)1.0 / s;
    return ret;
}

