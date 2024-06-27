#include<stdio.h>
#define PI 3.14159
int main() {
	int f;
	int p, k;
	double c,  s;
	float r;
	int newint;

	/*任务1*/
	printf("Input Fahrenheit:");
	scanf("%d", &f);
	c = (double)5.0 / 9 * (f - 32);
	printf("\n %d(F)=%.2f(C)\n\n", f, c);
	/*任务2*/
	printf("input the radius r:");
	scanf("%f", &r);
	s = PI * r * r;
	printf("\nThe acreage is %.2f\n\n", s);
	/*任务3*/
	k = 0xa1b2;
	p = 0x8423;
	newint = p & 0xff00 | k >> 8;
	printf("new int = %x\n\n", newint);
}	