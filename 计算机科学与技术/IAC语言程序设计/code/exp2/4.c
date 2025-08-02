#include<stdio.h>

int main() {
	int	i=0;
	char s[50];
	while ((s[i]=getchar())!=EOF)
	{
		i++;
	}
    if(i!=11){
        printf("长度不合法");
        }
    else {
        for( i=0;i<11;i++){
            if(s[i]<'0'||s[i]>'9')
            {
                printf("字符串中存在非数字字符");
                i=-1;
                break;
            }
            }
            if(s[0]!='1' && i!=-1){
            printf("第1位不合法");
            }else if((s[1]<'3'||s[1]>'9')&& i != -1){
                printf("第2位不合法");
            }
    }
}