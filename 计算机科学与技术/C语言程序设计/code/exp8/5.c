#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct LNode
{
	char stu_num[11];
	char stu_name[10];
	int English;
	int Maths;
	int Physcis;
	int C;
	float average;
	int sum;
	struct LNode* next;
}LNode;

void Open_file(LNode** L, const char* filename);
void Store(LNode* L);
void Print_Average(LNode** L);
void Insert(LNode** L,int* number);
void Print_SumAve(LNode** L);
void Average(LNode** L);
void Sum(LNode** L);
void ChangeElem(LNode** L);
void PrintListInitial(LNode* p);
void CreateList(LNode** L,int n);

int main(void)
{
	int menu;
	int number;
	scanf("%d", &menu);
	LNode* L;
	L = (LNode*)malloc(sizeof(LNode));
	int flag = 0;
	while (menu != 0)
	{
		if (1 == menu && 0 == flag)
		{
			scanf("%d", &number);
			CreateList(&L, number);
			flag = 1;
		}
		else if (2 == menu)
		{
			PrintListInitial(L);
		}
		else if (3 == menu)
		{
			ChangeElem(&L);
		}
		else if (4 == menu)
		{
			Print_Average(&L);
		}
		else if(5 == menu)
		{
			Print_SumAve(&L);
		}
		else if (1 == menu && 1 == flag)
		{
			Insert(&L, &number);
		}
        else if (6 == menu)
        {
        	Store(L);
        }
        else if (7 == menu)
        {
	        Open_file(&L,"stu.dat");
        }
		scanf("%d", &menu);
	}
}

void CreateList(LNode** L,int n)
{
	int i = 0;
	//*L = (LNode*)malloc(sizeof(LNode));
	LNode* r, * s;
	r = *L;
	while (i < n)
	{
		s = (LNode*)malloc(sizeof(LNode));
		scanf("%s %s %d%d%d%d", s->stu_num, s->stu_name, &s->English, &s->Maths, &s->Physcis, &s->C);
		r->next = s;
		r = s;
		i++;
	}
	r->next = NULL;
}

void PrintListInitial(LNode* p)
{
	p = p->next;
	while (p != NULL)
	{
		printf("%s %s %d %d %d %d\n", p->stu_num, p->stu_name, p->English, p->Maths, p->Physcis, p->C);
		p = p->next;
	}
	return;
}

LNode* LocateElem(LNode* p,char* s)
{
	p = p->next;
	while (0 != strcmp(p->stu_num,s))
	{
		p = p->next;
	}
	return p;
}

void ChangeElem(LNode** L)
{
	char s[11];
	int subject;
	int change;
	scanf("%s %d %d", s, &subject, &change);
	LNode* p = LocateElem(*L, s);
	if (1 == subject)
	{
		p->English = change;
	}
	else if (2 == subject)
	{
		p->Maths = change;
	}
	else if (3 == subject)
	{
		p->Physcis = change;
	}
	else if (4 == subject)
	{
		p->C = change;
	}
	return;
}

void Sum(LNode** L)
{
	LNode* p = (*L)->next;
	while (p != NULL)
	{
		p->sum = p->C + p->English + p->Maths + p->Physcis;
		p = p->next;
	}
	return;
}

void Average(LNode** L)
{
	Sum(L);
	LNode* p = (*L)->next;
	while (p != NULL)
	{
		p->average = (float)p->sum / 4;
		p = p->next;
	}
	return;
}

void Print_SumAve(LNode** L)
{
	Average(L);
	LNode* p = (*L)->next;
	while (p != NULL)
	{
		printf("%s %s %d %.2f\n", p->stu_num, p->stu_name, p->sum, p->average);
		p = p->next;
	}
	return;
}

void Insert(LNode** L,int* number)
{
	int appendnum = 0;
	int cnt = 0;
	scanf("%d", &appendnum);
	*number += appendnum;

	LNode* r, * s;
	r = (*L)->next;
	while (r->next != NULL)
	{
		r = r->next;
	}
	while (cnt < appendnum)
	{
		s = (LNode*)malloc(sizeof(LNode));
		scanf("%s %s %d%d%d%d", s->stu_num, s->stu_name, &s->English, &s->Maths, &s->Physcis, &s->C);
		r->next = s;
		r = s;
		cnt++;
	}
	r->next = NULL;
}

void Print_Average(LNode** L)
{
	Average(L);
	LNode* p = (*L)->next;
	while (p != NULL)
	{
		printf("%s %s %.2f\n", p->stu_num, p->stu_name, p->average);
		p = p->next;
	}
	return;
}

void Store(LNode* L)
{
	L = L->next;
	FILE* fp = fopen("stu.dat", "w+");
	while (L != NULL)
	{
		fprintf(fp, "%s %s %d %d %d %d\n", L->stu_num, L->stu_name, L->English, L->Maths, L->Physcis, L->C);
		L = L->next;
	}
	fclose(fp);
	return;
}

void Open_file(LNode** L, const char* filename)
{
	FILE* fp = fopen(filename, "r+");
	LNode* r, * s;
	r = *L;
	r->next = NULL;
	s = (LNode*)malloc(sizeof(LNode));
	while (fscanf(fp,"%s %s %d%d%d%d", s->stu_num, s->stu_name, &s->English, &s->Maths, &s->Physcis, &s->C) != EOF)
	{
		r->next = s;
        r = s;
		s = (LNode*)malloc(sizeof(LNode));
	}
	free(s);
	r->next = NULL;
	fclose(fp);
}
