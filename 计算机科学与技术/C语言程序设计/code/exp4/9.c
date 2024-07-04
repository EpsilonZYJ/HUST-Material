#include<stdio.h>

#define CHANGE 1

int main(void)
{
	char c;
#if CHANGE==0
	while ((c=getchar())!='\n')
	{
		putchar(c);
	}
#elif CHANGE==1
	while ((c=getchar())!='\n')
	{
		if (c>='A'&&c<='Z')
		{
			c += 'a' - 'A';
		}
		else if (c>='a'&&c<='z')
		{
			c += 'A' - 'a';
		}
		else
		{
			;
		}
		putchar(c);
	}
#endif // CHANGE==1

}