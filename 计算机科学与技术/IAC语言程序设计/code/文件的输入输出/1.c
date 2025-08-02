#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    /**********  Begin  **********/
    char order1[20],order2[20];
    int num=1;//行号
    scanf("%s%s",order1,order2);
    if(strcmp(order1,"type_c")!=0)
   {
        printf("指令错误");
    }
    else
    {
        if(strcmp(order2,"/p")!=0)
        {
            FILE *file1=fopen("src/step1_1/test1.c","r");
            char buf1[1024];
            while(fgets(buf1,sizeof(buf1),file1)!=NULL)
            {
                printf("%d  %s",num,buf1);
                num++;
            }
        }
        else
        {
            num=1;
            FILE *file2=fopen("src/step1_1/test1.c","r");
            char buf2[1024];
            while(fgets(buf2,sizeof(buf2),file2)!=NULL)
            {
                printf("%d  %s",num,buf2);
                num++;
                if(num==11)
                {
                    while(getchar()!='q');
                    num=1;
                }
            }
        }
    }
    /**********   End   **********/
    return 0; 
}