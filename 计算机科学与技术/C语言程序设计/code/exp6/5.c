#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void DeleteBackspace(char* s);

int main()
{
	char* s1 = (char*)malloc(sizeof(char) * 50);
	char* s2 = (char*)malloc(sizeof(char) * 50);
	char* s3;
	int function;

	char* (*functab[])(char*, char*) = { NULL,strcpy,strcat,strtok,NULL };

	while (scanf("%d", &function) && function != 4)
	{
		getchar();
		fgets(s1, 50, stdin);
		fgets(s2, 50, stdin);

		DeleteBackspace(s1);
		DeleteBackspace(s2);

		s3 = functab[function](s1, s2);
		puts(s3);
	}

	free(s1);
	free(s2);

	return 0;

}

void DeleteBackspace(char* s)
{
	int i = 0;
	while (*(s + i) != '\n')
	{
		i++;
	}
	*(s + i) = '\0';
}