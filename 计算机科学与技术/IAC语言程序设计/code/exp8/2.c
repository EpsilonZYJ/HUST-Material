#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	FILE * fp;
	if(argc!=3){
		printf("Arguments error!\n");
		exit(-1);
	}
	if((fp=fopen(argv[1],"r"))==NULL){      /* fp指向filename */
		printf("Can't open %s file!\n", argv[1]);
		exit(-1);
	}
	char buf[1024];
    int num=1;
    char c;
    while(fgets(buf,sizeof(buf),fp)!=NULL)
    {
        printf("%d %s",num,buf);
        num++;
        if((num-1)%5==0)
        {
            if((c=getchar()) == EOF)
            {
                break;
            }
        }
    }
    
                /* 向显示器中写从filename中读取的字符 */ 
	fclose(fp);                        /* 关闭filename */ 
	return 0;
}
