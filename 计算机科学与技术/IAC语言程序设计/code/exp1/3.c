#include<stdio.h>
int main()
{
      int day,month,year,sum,leap,i;
	   int mdays[12]={0,31,28,31,30,31,30,31,31,30,31,30};
		//printf("please input year month day:\n");
		scanf("%d%d%d",&year,&month,&day);
		sum=0;
		for(i=0;i<month;i++)
		{
			sum+=mdays[i];
		}
		sum=sum+day;
		if(year%400==0||(year%4==0&&year%100!=0))
			leap=1;
		else
			leap=0;
		if(leap==1&&month>2)
			sum++;
		printf("It is the %dth day.",sum);
		return 0;
	}