#include<stdio.h>

int main(void)
{
	int i = 0;
	char* p;
	
	scanf("%d", &i);
	p = (char *)&i;

	for (int j = 3; j >= 0; j--)
	{
		printf("%x %x", *(p+j)>> 4 & 0xf, *(p+j) & 0xf);
		if (j!=0)
		{
			printf(" ");
		}
	}

	return 0;
}