#include <stdio.h>

int main(){
	/**********Begin**********/
	unsigned short int k;
    scanf("%hu",&k);
    int j;
    int i;

    i = k >>12;
    j = k<<12;

    k = ((k & 0xFF0)|i)|j;
    printf("%d",k);
	/**********End**********/
	return 0;
}