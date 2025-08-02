//判定不了中文字符换行后英文字符从而产生的字数
#include<stdio.h>
#include<ctype.h>

int main()
{
	int words = 0;
	int num = 0;
	int line = 0;
	int space = 0;
	int Ch = 0;

	char c1;
	char c2;
	char c3;

	while ((c1 = getchar()) != EOF)
	{
		if ((c1 & 0x80) == 0x80)
		{
			space = 0;
			c2 = getchar();
			c3 = getchar();
			words++;
			num++;
			Ch = 1;
		}
		else if (isspace(c1)&&c1!='\n'&&space==0&&Ch==0)
		{
			space++;
			words++;
		}
		else if (isspace(c1) && c1 != '\n' && space > 0)
		{  
			;
		}
		else if (c1 == '\n')
		{
			line++;
			if ((c2&0x80)!=0x80)
			{
				words++;
			}
			
		}
		else if ((c1 >= '\x41' && c1 <= '\x5a') || (c1 >= '\x61' && c1 <= '\x7A'))
		{
			num++;
			Ch = 0;
			space = 0;
		}
		c2=c1;
	}
	

	printf("字数 %d\n字符数 %d\n行数 %d", words, num, line);
}