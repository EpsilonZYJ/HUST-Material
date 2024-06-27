#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

struct bits
{
	unsigned char bit0 : 1;
	unsigned char bit1 : 1;
	unsigned char bit2 : 1;
	unsigned char bit3 : 1;
	unsigned char bit4 : 1;
	unsigned char bit5 : 1;
	unsigned char bit6 : 1;
	unsigned char bit7 : 1;
};

void f0(int b)
{
	printf("the function %d is called!\n", b);
}

void f1(int b)
{
	printf("the function %d is called!\n", b);
}

void f2(int b)
{
	printf("the function %d is called!\n", b);
}

void f3(int b)
{
	printf("the function %d is called!\n", b);
}

void f4(int b)
{
	printf("the function %d is called!\n", b);
}

void f5(int b)
{
	printf("the function %d is called!\n", b);
}

void f6(int b)
{
	printf("the function %d is called!\n", b);
}

void f7(int b)
{
	printf("the function %d is called!\n", b);
}

int main(void)
{
	struct bits biti;
	scanf("%d", &biti);

	void* (*p_fun[8])(int b) = { f0,f1,f2,f3,f4,f5,f6,f7 };

	if (1==biti.bit0)
	{
		p_fun[0](0);
	}
	if (1==biti.bit1)
	{
		p_fun[1](1);
	}
	if (1 == biti.bit2)
	{
		p_fun[2](2);
	}
	if (1 == biti.bit3)
	{
		p_fun[3](3);
	}
	if (1 == biti.bit4)
	{
		p_fun[4](4);
	}
	if (1 == biti.bit5)
	{
		p_fun[5](5);
	}
	if (1 == biti.bit6)
	{
		p_fun[6](6);
	}
	if (1 == biti.bit7)
	{
		p_fun[7](7);
	}

	return 0;
}