#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef char ElemType;

typedef struct LNode
{
	char ch;
	struct LNode* next;
}LNode;

void CreateList(LNode** L)
{
	char x;
	(*L) = (LNode*)malloc(sizeof(LNode));
	(*L)->next = NULL;
	LNode* s, * r = *L;
	scanf("%c", &x);
	while (x != '\n')
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->ch = x;
		r->next = s;
		r = s;
		scanf("%c", &x);
	}
	r->next = NULL;
	return;
}

//LNode* LocateElem(LNode** L, char ch)
//{
//	LNode* p = (*L)->next;
//	while (p && p->ch != ch)
//	{
//		p = p->next;
//	}
//	return p;
//}

int LenList(LNode** L)
{
	int cnt = 0;
	LNode* p = (*L)->next;
	while (p != NULL)
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}

void PrintList(LNode** L)
{
	LNode* p = (*L)->next;
	while (p != NULL)
	{
		if (p->next==NULL)
		{
			printf("%c", p->ch);
            printf(" ");
		}
		else
		{
			printf("%c", p->ch);
			printf(" ");
		}
		p = p->next;
	}
	printf("\n");
}

void Link_to_SqList(LNode** L, char* s)
{
	int cnt = 0;
	LNode* p = (*L)->next;
	while (p!=NULL)
	{
		*(s + cnt) = p->ch;
		cnt++;
		p = p->next;
	}
	*(s + cnt) = '\0';
	return;
}

int delete(LNode** L,char *s, char c)
{
	LNode* p = *L;
	int ret = 0;
	if (NULL == p->next)
	{
		Link_to_SqList(L, s);
		return 0;
	}
	else
	{
		while (p && p->next != NULL)
		{
			LNode* s0 = p->next;
			if (s0->ch == c)
			{
				p->next = s0->next;
				free(s0);
				ret = 1;
			}
			p = p->next;
		}
		Link_to_SqList(L, s);
		return ret;
	}
}

int LocateElem(LNode** L, char c)
{
	LNode* p = (*L)->next;
	int abs_pos = (int)fabs(p->ch - c);
	int i = 1;
	int pos = i;
	while (p != NULL)
	{
		if (abs_pos > (int)fabs(p->ch - c))
		{
			abs_pos = (int)fabs(p->ch - c);
			pos = i;
		}
		i++;
		p = p->next;
	}
	return pos;
}

void change(LNode** L, char* s, char c)
{
	int i = LocateElem(L, c);
	LNode* p = (*L)->next;
	int j = 1;
	while (j < i && p)
	{
		p = p->next;
		j++;
	}
	LNode* p0 = (LNode*)malloc(sizeof(LNode));
	p0->ch = c;
	p0->next = p->next;
	p->next = p0;
	Link_to_SqList(L, s);
}

int main(void)
{
	LNode* L;
	CreateList(&L);
	PrintList(&L);
	
	int len = LenList(&L);
	char* s = (char*)malloc(sizeof(char) * (len + 1));
	Link_to_SqList(&L, s);
	printf("%s", s);
	printf("\n");

	char c;
	scanf("%c", &c);

	int success = 0;
	success = delete(&L, s, c);
	if (0 == success)
	{
		change(&L, s, c);
	}

	printf("%s", s);
	//printf("\n");

	return 0;
}