#include <stdio.h>

int main() {
	/**********Begin**********/
    int year;
    scanf("%d",&year);

    if (year%100 == 0 &&year % 400 != 0){
    printf("Jan: 31\nFeb: 28\nMar: 31\nApr: 30\nMay: 31\nJun: 30\nJul: 31\nAug: 31\nSep: 30\nOct: 31\nNov: 30\nDec: 31");
    }
    else if (year%100 == 0 && year%400 == 0){
    printf("Jan: 31\nFeb: 29\nMar: 31\nApr: 30\nMay: 31\nJun: 30\nJul: 31\nAug: 31\nSep: 30\nOct: 31\nNov: 30\nDec: 31");
    }
    else if(year % 100 != 0 && year % 4 ==0){
        printf("Jan: 31\nFeb: 29\nMar: 31\nApr: 30\nMay: 31\nJun: 30\nJul: 31\nAug: 31\nSep: 30\nOct: 31\nNov: 30\nDec: 31");
    }else{
        printf("Jan: 31\nFeb: 28\nMar: 31\nApr: 30\nMay: 31\nJun: 30\nJul: 31\nAug: 31\nSep: 30\nOct: 31\nNov: 30\nDec: 31");
    }


	/**********End**********/
	return 0;
}