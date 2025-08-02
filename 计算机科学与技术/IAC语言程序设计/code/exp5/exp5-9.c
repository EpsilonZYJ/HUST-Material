#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void strnins(char* t, char* s, int n);

int main(void)
{
	char s[20];
	char t[20];
	int n;

	scanf("%s", t);
	scanf("%s", s);
	scanf("%d", &n);


	strnins(t, s, n);


	return 0;
}

void strnins(char* t, char* s, int n)
{ 
	char p[60];
	//p = (char*)malloc(sizeof(char) * (strlen(t) - 1 + strlen(s)));
	for (int i = 0; i < n; i++)
	{
		p[i] = t[i];
	}
	for (int i = strlen(t); i >= n; i--)
	{
		p[i + strlen(s)] = t[i];
	}
	for (int i = n; i < strlen(s)+n; i++)
	{
		p[i] = s[i - n];
	}

	printf("%s", p);
}