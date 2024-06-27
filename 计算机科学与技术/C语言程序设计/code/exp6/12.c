#include<stdio.h>
#include<string.h>

#define MAX 20

void task0(void)
{
	printf("task0 is called!\n");
	return;
}

void task1(void)
{
	printf("task1 is called!\n");
	return;
}

void task2(void)
{
	printf("task2 is called!\n");
	return;
}

void task3(void)
{
	printf("task3 is called!\n");
	return;
}

void task4(void)
{
	printf("task4 is called!\n");
	return;
}

void task5(void)
{
	printf("task5 is called!\n");
	return;
}

void task6(void)
{
	printf("task6 is called!\n");
	return;
}

void task7(void)
{
	printf("task7 is called!\n");
	return;
}

void execute(char* task, int length)
{
	char* p = task;
	while (*p!='\0')
	{
		switch (*p)
		{
		case '0':
			task0();
			break;
		case '1':
			task1();
			break;
		case '2':
			task2();
			break;
		case '3':
			task3();
			break;
		case '4':
			task4();
			break;
		case '5':
			task5();
			break;
		case '6':
			task6();
			break;
		case '7':
			task7();
			break;
		default:
			break;
		}
		p++;
	}
	return;
}

void scheduler(void)
{
	char task[MAX];
	scanf("%s", task);
	int length = strlen(task);
	execute(task, length);
	return;
}


int main(void)
{
	scheduler();

	return 0;
}