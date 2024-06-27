#include<stdio.h>

struct student{
    int num;
    char name[12];
    double score;
};

/****在下面定义函数scan，对结构数组初始化******/
void scan(struct student *p,int n )
{
    /**********  Begin  **********/
    struct student *p1;
    p1 = p;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %s %lf", &(p1)->num, &(p1)->name, &(p1)->score);
        //scanf("%d %s %f", &a[i].num, &a[i].name, &a[i].score);
        p1++;
	}
	

   /**********  End  **********/
}

/****在下面定义函数print，依次输出结构数组的各成员值******/
void print(struct student *p,int n )
{
	/**********  Begin  **********/
	struct student* p2;
	p2 = p;
	for (int i = 0; i < n; i++)
	{
		printf("%d %s %.1f\n", p2->num, p2->name, p2->score);
        p2++;
	}

	
	/**********  End  **********/
}