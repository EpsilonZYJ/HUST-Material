/********** Begin **********/
#include<stdio.h>
#define max 10
int main()
{
    int sum = 0;
    double average = 0;
    int numbers = 0;
    int i = 0;
    int a = 0;

    for(i = 0; i < max; i++){
        scanf("%d",&a);
        if(a <= 0){
            continue;
        }
        sum += a;
        numbers++;
    }
    if(numbers != 0){
    average = (double)sum/numbers;
    printf("numbers=%d, average=%.6f",numbers,average);
    }
    else{
        printf("numbers=0, average=0.000000");
    }
}





/**********  End **********/
