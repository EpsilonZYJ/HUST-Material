/******************  begin *********************/

#include<stdio.h>
#include<assert.h>

#define NDEBUG
#define R

int integer_fraction(float x);

int main()
{
	float r, s;
	int s_integer = 0;
	scanf("%f", &r);
#ifdef R
	s = 3.14159 * r * r;
	//printf("%f", s);
	s_integer = integer_fraction(s);
	assert((s - s_integer) < 0.5);
	printf("The integer fraction of area is %d", s_integer);
#endif
	return 0;
}

int integer_fraction(float x)
{
	int i = x;
	if ((float)x-i>0.5)
	{
		i += 1;
	}
	return i;
}



/******************   end  *********************/
