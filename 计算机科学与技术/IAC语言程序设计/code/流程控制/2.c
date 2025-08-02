/********** Begin **********/
#include<stdio.h>
int m(int year);
int main(){
    int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int i = 0;
    int year,month,day;
    int sum = 0;
    scanf("%d %d %d",&year,&month,&day);
    if(m(year) == 1){
        a[1] = 29;
        
    }else{
        ;
    }
    for(i = 0; i < month-1;i++){
                sum += a[i];
    }
    sum += day;
    printf("%d",sum);

    return 0 ;
}
int m(int year){
    int ret;
    if ((year%100 == 0 && year%400 == 0)||(year % 100 != 0 && year % 4 ==0)){
        ret = 1;
    }else{
        ret = 0;
    }
    return ret;
}





/**********  End **********/
