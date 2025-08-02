#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100000

void _replace(char* buf,char* s1,char* s2);

int main(int argc, char* argv[])
{
    FILE* fp0 = fopen(argv[1],"r");
    FILE* fp = fopen("out.txt","w+");

    char buf[N];
    memset(buf,'\0',N);
    while((fgets(buf,sizeof(buf),fp0)) != NULL)
    {
        //printf("[q]%s\n",buf);
        _replace(buf,argv[2],argv[3]);
        //printf("[p]%s\n",buf);
        fputs(buf,fp);
        memset(buf,'\0',N);
    }
    fclose(fp0);
    fclose(fp);

    return 0;
}

void _replace(char* buf,char* s1,char* s2)
{
    int i = 0;
    int j = 0;
    char* p;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len = strlen(buf);
    p = buf;
    while((p = strstr(p, s1)) != NULL)
    {
        *p = '\t';
        if(len1 == len2)
        {
            for(i = 0; i < len1; i++)
            {
                *(p + i) = *(s2 + i);
            }
        }
        else if(len1 > len2)
        {
            for(i = 0; i < len2; i++)
            {
                *(p + i) = *(s2 + i);
            }
            for(j = len1; *(p+j) != '\0'; j++)
            {
                *(p + j - (len1 - len2)) = *(p + j);
            }
        }
        else
        {
            for(j = len; buf[j] != '\t'; j--)
            {
                buf[j + len2 - len1] = buf[j];
            }
            for(i = 0;i < len2; i++)
            {
                *(p + i) = *(s2 + i);
            }
        }
        p += len1;
    }
}