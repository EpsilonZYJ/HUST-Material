#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLINE 1000

void strsort(char** p, int n)
{
	char* p0;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			//printf("%s", *p);
			if (strcmp(*(p+j),*(p+j+1))>0)
			{
				p0 = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = p0;
			}

		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	getchar();
	int i;
	char* s[MAXLINE], t[50];
	for (i = 0; i < N; i++)
	{
		gets(t);
		s[i] = (char*)malloc(2000);
		strcpy(s[i], t);
	}
	strsort(s, N);
	for (i = 0; i < N; i++)  puts(s[i]);

	return 0;
}