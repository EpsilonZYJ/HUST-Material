/********** Begin **********/
#include<stdio.h>
#include<math.h>

int main()
{
    int i, j,  b;
    int n = 0;
    int m = 0;
    scanf("%d",&n);

    for ( i = 1; i < sqrt(n) ; i++)
    {
        b = 1000;
        for ( j = 1; j < sqrt(i*i*10); j++)
        {
            for ( m = 1; m < i; m++)
            {
                if (i*i == j*j*10+m*m && b > j)
                {
                    
                    printf("%d=%d*%d=%d*%d*10+%d*%d\n",i*i,i,i,j,j,m,m);
                    b = j;
                }
               
            }
           
        }
        
    }
    return 0;
}
/**********  End **********/
