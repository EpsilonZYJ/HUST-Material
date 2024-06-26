#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int _input;
	scanf("%d", &_input);

	char bio[40];
	
	bio[39] = '\0';
	bio[0] = (_input > 0) ? 0+'0' : 1+'0';

	_input = (_input > 0) ? _input : -_input;

	int j;

	for (int i = 38,j=0; i > 0; i--)
	{
		if (j!=4)
		{
			bio[i] = _input % 2 + '0';
			_input /= 2;
			j++;
		}
		else
		{
			bio[i] = ' ';
			j = 0;
		}

	}
	if (bio[0]-'0')
	{
		for (int i = 38; i >= 1 ; i--)
		{
			if ((i%5!=4))
			{
				bio[i] = (bio[i] == '0') ? '1' : '0';
			}

	
		}
		for (int i = 38; i >= 1; i--)
		{
			if (i % 5 == 4)
			{
				;
			}
			else
			{
				bio[i] += 1;
				if (bio[i] == '2')
				{
					bio[i] = '0';
				}
				else if (bio[i] == '1')
				{
					break;
				}
			}
		}
	}
	printf("%s", bio);

	return 0;
}