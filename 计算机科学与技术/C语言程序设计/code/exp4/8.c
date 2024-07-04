/***定义两个带参数的宏,用于计算三角形面积***/
#include<stdio.h>
#include<math.h>

#define s(a,b,c) ((a)+(b)+(c))/2
#define area(s,a,b,c) sqrt((s)*((s)-(a))*((s)-(b))*((s)-(c)))


int main(void)
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	double _area = area(s(a, b, c), a, b, c);
	printf("%.2lf",_area);
	return 0;
}