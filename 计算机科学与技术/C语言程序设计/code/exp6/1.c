#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

char* strcopy(char*, const char*);

int main(void) {
	char* s1;
	char* s2;
	char* s3;
	//printf("")
	s1 = (char*)malloc(sizeof(char) * 20);
	s2 = (char*)malloc(sizeof(char) * 20);
	s3 = (char*)malloc(sizeof(char) * 40);

	scanf("%s", s2);
	strcopy(s1, s2);
	printf("%s\n", s1);
	scanf("%s", s2);
	s3 = strcopy(s1, s2);
	printf("%s\n", s3);
	return 0;
}

char* strcopy(char* t, const char* s) {
	char* p = t;
	while (*p++=*s++)
	{
		;
	}
	return (t);
}