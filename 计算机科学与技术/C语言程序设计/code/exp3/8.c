#include<stdio.h>

int main()
{
	char c;
	enum state
	{
		copy, space,
	};
	enum state st;
	while ((c=getchar())!=EOF )
	{
		switch (c)
		{
		case '\x20':
			if (st==copy)
			{
				st = space;
				printf("%c", c);

			}
			else if (st==space)
			{

			}
			break;
		default:
			st = copy;
			printf("%c", c);
			break;
		}
	}
}