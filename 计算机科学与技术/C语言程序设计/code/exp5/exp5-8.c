#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

void _input(char stu_name[][20], int stu_score[][2], int n);
void sort(char* pstu_name[2], int stu_score[][2], int length);
void swap(int* a, int* b);
//void swap_name(char* s1, char* s2);
void print(char* pstu_name[5], int stu_score[][2], int n);
void find(char* pstu_name[5], int stu_score[][2], int n, int need_score);


char stu_name[5][20];
int stu_score[5][2];

int main(void)
{
	int function;
	int n;
	char* pstu_name[5];

	while (scanf("%d", &function) && function != 0)
	{
		if (function == 1)
		{
			//输入n个学生的姓名和C语言课程的成绩
			scanf("%d", &n);
			_input(stu_name, stu_score, n);

			for (int i = 0; i < n; i++)
			{
				//printf("--3131\n");
				pstu_name[i] = stu_name[i];
				//printf("----%s\n", pstu_name[i]);
			}
		}
		else if (function == 2)
		{
			//将成绩按从高到低的次序排序，姓名同时进行相应调整
			sort(pstu_name, stu_score, n);
		}
		else if (function == 3)
		{
			//输出所有学生的姓名和C语言课程的成绩
			print(pstu_name, stu_score, n);
		}
		else if (function==4)
		{
			//输入一个C语言课程成绩值，用二分查找进行搜索
			int need_score;
			scanf("%d", &need_score);
			find(pstu_name, stu_score, n, need_score);
		}
	}


	return 0;
}

void _input(char stu_name[][20], int stu_score[][2], int n)
{
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d", &stu_name[i][0], &stu_score[i][0]);
	}
}

void sort(char* pstu_name[5], int stu_score[][2], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (stu_score[j][0] > stu_score[j + 1][0])
			{
				;
			}
			else if (stu_score[j][0] < stu_score[j + 1][0])
			{
				swap(&stu_score[j][0], &stu_score[j + 1][0]);
				char* p0;
				p0 = pstu_name[j];
				pstu_name[j] = pstu_name[j + 1];
				pstu_name[j + 1] = p0;
			}
			else
			{
				if (strcmp(pstu_name[j], pstu_name[j + 1]) < 0)
				{
					;
				}
				else if (strcmp(pstu_name[j], pstu_name[j + 1]) > 0)
				{
					swap(&stu_score[j], &stu_score[j + 1]);
					char* p0;
					p0 = pstu_name[j];
					pstu_name[j] = pstu_name[j + 1];
					pstu_name[j + 1] = p0;
				}
			}
		}
	}
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;

}

//void swap_name(char* s1, char* s2)
//{
//	char a[30];
//	a[0] = *s1;
//	*s1 = *s2;
//	*s2 = a[30];
//
//}

void print(char* pstu_name[5], int stu_score[][2], int n)
{
	for (int i = 0; i < n; i++)
	{
		//printf("%d %d\n", i, stu_score[i][0]);
		printf("%s %d\n", pstu_name[i], stu_score[i][0]);
	}
}

void find(char* pstu_name[5], int stu_score[][2], int n, int need_score)
{
	int left = 0;
	int right = n - 1;
	int mid;
	int flag = 0;
	while (left<right)
	{
		mid = (left + right) / 2;
		if (stu_score[mid][0]==need_score)
		{
			flag = 1;
   left = mid;
   right = mid;
    while (stu_score[left][0]==need_score)
   {
   left--;
   }
   left += 1;
   while (stu_score[right][0]==need_score)
			{
  right++;
   }
   right -= 1;
   for (int i = left; i < right+1; i++)
			{
  printf("%s %d\n", pstu_name[i], stu_score[i][0]);
   }
   break;
		}
		else if (stu_score[mid][0]>need_score)
		{
    right = mid - 1;
		}
		else
		{
    left = mid + 1;
		}
	}
	if (flag==0)
	{
   printf("not found");
	}
}