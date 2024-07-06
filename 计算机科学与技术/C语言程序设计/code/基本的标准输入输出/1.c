#include <stdio.h>

int main() {
/**********Begin**********/
	char c;
    scanf("%c",&c);
    int i ;
    int j;
    switch(c){
        case '0': case '1': case '2':
        case '3': case '4': case '5':
        case '6': case '7': case '8':
        case '9': 
            i = c - '0';
            printf("%d",i);
            break ;
        case 'a':case 'A':
            printf("10");
            break ;
        case 'b':case 'B':
            printf("11");
            break ;
        case 'c':case'C':
            printf("12");
            break;
        case 'd':case'D':
            printf("13");
            break;
        case 'e':case'E':
            printf("14");
            break;
        case 'f':case'F':
            printf("15");
            break;
        default:
            j = c;
            printf("%d",j);
            break;

    }
/**********End**********/
	return 0;
}