#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	
			
		
    int num = atoi(argv[1]);
    int* p;
	p = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", p + i);
	}
	if (argc>=3 && strcmp(argv[2], "-d") == 0)
	{
		for (int i = 0; i < num - 1; i++)
        {			
			for (int j = 0; j < num - i - 1; j++)
			{
				if (*(p + j) < *(p + j + 1))
				{
    				int t = *(p + j);
					*(p + j) = *(p + j + 1);
					*(p + j + 1) = t;
				}
    		}
		}
	}
	else
	{
    	for (int i = 0; i < num - 1; i++)
		{
			for (int j = 0; j < num - i - 1; j++)
			{
				if (*(p + j) > *(p + j + 1))
				{
					int t = *(p + j);
					*(p + j) = *(p + j + 1);
					*(p + j + 1) = t;
				}
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		printf("%d", *(p + i));
		if (i != num - 1)
		{
			printf(" ");
		}
	}

	return 0;
}