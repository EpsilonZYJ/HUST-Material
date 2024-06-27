#include<stdio.h>
/**********  Begin  **********/
struct date {
    int year;
    int month;
    int day;
};
int main()
{
    struct date today;
    int sum = 0;
    scanf("%d%d%d", &today.year, &today.month, &today.day);
    int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (today.year % 4 != 0 || (today.year % 100 == 0 && today.year % 400 != 0)) {
        if (today.day > mon[today.month - 1]||today.month>12) {
            printf("不存在这样的日期");
        }
        else {
            for (int i = 0; i < today.month - 1; i++) {
                sum += mon[i];
            }
            sum += today.day;
            printf("%d", sum);
        }
    }
    else {
        mon[1] = 29;
        if (today.day > mon[today.month - 1]||today.month>12) {
            printf("不存在这样的日期");
        }
        else {
            for (int i = 0; i < today.month - 1; i++) {
                sum += mon[i];
            }
            sum += today.day;
            printf("%d", sum);
        }
    }
 



    /**********   End   **********/
    return 0;
}