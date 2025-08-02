#include<stdio.h>

void strnCpy(char t[],char s[],int n){
	/**********  Begin  **********/
    int i=0;
    for(i;i<n;i++)
    {
        t[i]=s[i];
    }
    t[i]='\0';
	/**********  End  **********/
}
