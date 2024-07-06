#include <stdio.h>

//请根据step3_main.cpp中的主函数流程，补全此函数
int digit(long n, int k)
{
	/**********  Begin  **********/
    for (int i = 0; i < k-1; i++)
   {
    if (n/10 == 0)
    {
        return -1;
        break;
    }
    else
    {
        n /= 10;
    }
   }
   if (n)
   {
    int j = n % 10;
    return j;
   }
    /**********  End  **********/
}
