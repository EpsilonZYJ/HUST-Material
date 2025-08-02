#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define MAX 500

typedef struct
{
	int num[MAX];
	int length;
}number;

void CreateNum(number* num);
void shift(number* num);
void Initialize(number* result);
void PrintResult(number* result);
void multiply(number* num1, number* num2, number* result);
int judge(int* n, int b);

int main(void)
{
	number num1;
	number num2;
	number result;

	CreateNum(&num1);
	CreateNum(&num2);

	shift(&num1);
	shift(&num2);

	Initialize(&result);

	multiply(&num1, &num2, &result);

	PrintResult(&result);
	

	return 0;
}

void CreateNum(number *num)
{
	char c[MAX];
	num->length = 0;
	int i = 0;
	gets(c);
	while (c[i]!='\0')
	{
		num->num[i] = (int)(c[i] - '0');
		i++;
		num->length++;
	}
	return;
}

void shift(number* num)
{
	int sft = MAX - num->length;
	for (int i = num->length-1; i >= 0; i--)
	{
		num->num[i + sft] = num->num[i];
	}
	for (int j = 0; j < MAX-num->length; j++)
	{
		num->num[j] = 0;
	}
	return;
}

void Initialize(number* result)
{
	for (int i = 0; i < MAX; i++)
	{
		result->num[i] = 0;
	}
}

void multiply(number* num1, number* num2, number* result)
{
	result->length = 0;
	int weishu = 0;
	for (int i = MAX-1; i >= MAX-num2->length; i--)
	{
		for (int j = MAX-1; j >= MAX-num1->length; j--)
		{
			result->num[MAX-((MAX - j) + (MAX - i) - 1)] += num2->num[i] * num1->num[j];
			if (judge(&weishu, (MAX - j) + (MAX - i) - 1))
			{
				result->length++;
			}
		}
	}
	int j = MAX - 1;
	while (j>MAX-result->length)
	{
		int tens = result->num[j] / 10;
		int z = result->num[j] % 10;
		result->num[j] = z;
		result->num[j - 1] += tens;
		j--;
	}
	if (result->num[MAX-result->length]>=10)
	{
		result->num[MAX - result->length - 1] = result->num[MAX - result->length] / 10;
		result->num[MAX - result->length] %= 10;
		result->length++;
	}
	return;
}

void PrintResult(number* result)
{
	for (int i = MAX - result->length; i <= MAX-1; i++)
	{
		printf("%d", result->num[i]);
	}
}

int judge(int* n, int b)
{
	if (b<=*n)
	{
		return 0;
	}
	if (b>*n)
	{
		*n = b;
		return 1;
	}
}