#include<stdio.h>
#include<math.h>
int main()
{
    int max;
    int n;
    int i1,i2;
    scanf("%d",&n);
    scanf("%d",&i1);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&i2);
        max=(max>abs(i1-i2)?max:abs(i1-i2));
        i1=i2;
    }
    printf("%d",max);


}