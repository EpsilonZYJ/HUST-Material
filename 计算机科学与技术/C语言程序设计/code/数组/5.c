#include<stdio.h>

void conversion(char str[]){
	/**********  Begin  **********/
    int i=0;
    int sum=0;
    int m;
    while(str[i]!='\0'){
        switch(str[i]){
            case '0':
                m=0;
                break;
            case '1':
                m=1;
                break;
            case '2':
                m=2;
                break;
            case '3':
                m=3;
                break;
            case '4':
                m=4;
                break;
            case '5':
                m=5;
                break;
            case '6':
                m=6;
                break;
            case '7':
                m=7;
                break;
            case '8':
                m=8;
                break;
            case '9':
                m=9;
                break;
            case 'a':case 'A':
                m=10;
                break;
            case 'b':case'B':
                m=11;
                break;
            case 'c':case 'C':
                m=12;
                break;
            case 'd':case'D':
                m=13;
                break;
            case 'e':case 'E':
                m=14;
                break;
            case 'f':case'F':
                m=15;
                break;
            default:
                goto here;
        }
        sum = sum*16+m;
        i++;
    }
    here:
    printf("%d",sum);
	/**********  End  **********/
}
