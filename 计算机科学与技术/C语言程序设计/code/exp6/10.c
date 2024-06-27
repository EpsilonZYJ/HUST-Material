#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 50

int isenter(char c)
{
	if (c=='\n')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int CountEnter(char* str)
{
	int i = 0;
	int cnt = 0;
	while (isenter(*(str+i)))
	{
		cnt++;
		i++;
		if (*(str+i)=='\0')
		{
			cnt--;
		}
	}
	return cnt;
}


int delSubstr(char* str, char* substr)
{
	int len = strlen(substr);
	char* pos ;
	if (strstr(str,substr)==NULL)
	{
		return 0;
	}
	char* p;
	while ((pos=strstr(str,substr))!=NULL)
	{
		for (p=pos;p - pos < len; p++)
		{
			*p = '\n';
		}
	}
	for (int i = 0; *(str+i)!='\0'; i++)
	{
		if (isenter(*(str+i))&&isenter(*(str+i+1)))
		{
			int m = CountEnter(str + i);
			for ( p = str+i; p-str < strlen(str); p++)
			{
				*p = *(p + m);
			}
		}
	}
	return 1;
}

int main(void)
{
	char str[MAX];
	char substr[MAX];
	int ret = 0;

	fgets(str, 50, stdin);
	gets(substr);

	ret = delSubstr(str, substr);

	printf("%s", str);
	printf("%d", ret);

	return 0;
}