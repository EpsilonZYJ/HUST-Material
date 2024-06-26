#include<stdio.h>

int main(void)
{
	char a[30];
	char b[60];
	char c;

	scanf("%s", a);
	scanf("%s\n", b);
	c = getchar();

	int i = 0;
	int j = 0;
	while (a[i++]);
	i--;
	while ((a[i++] = b[j++]) != '\0')
	{
		;
	}
	printf("%s\n", a);

	i = 0;
	j = 0;
	while (a[i] != '\0')
	{
		if (a[i] != c)
		{
			a[j++] = a[i];
		}
		i++;
	}
	a[i] = '\0';
	puts(a);


}