#include<stdio.h>
#include<string.h>



struct web  /*  设计表示网址的结构  */
{
	/**********  Begin  **********/
	char suolue[10];
	char quan[50];
	char URL[50];

	/**********   End   **********/
};

void sort(struct web webs[], int n);

#define N  4      /*  网址表大小  */

int main()
{
	/**********  Begin  **********/
	struct web webs[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%s %s %s", &webs[i].suolue, &webs[i].quan, &webs[i].URL);
	}
	sort(webs, N);
	char find[50];
	scanf("%s", find);
	for (int i = 0; i < N; i++)
	{
		printf("%s %s %s\n", webs[i].suolue, webs[i].quan, webs[i].URL);
	}
	for (int j = 0; j < N; j++)
	{
		if (strcmp(find,webs[j].suolue)==0)
		{
			printf("%s", webs[j].URL);
			break;
		}
		else if(j==N-1 && strcmp(find, webs[j].suolue) != 0)
		{
			printf("未找到搜寻的网址");
		}
	}


	
	/**********   End   **********/
	return 0;
}

void sort(struct web webs[], int n)
{
	/**********  Begin  **********/
	struct web tmp;
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (strcmp(webs[i].suolue, webs[i + 1].suolue) > 0)
			{
				tmp = webs[i + 1];
				webs[i + 1] = webs[i];
				webs[i] = tmp;
			}
		}
	}


	/**********   End   **********/
}