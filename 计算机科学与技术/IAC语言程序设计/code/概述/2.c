#include<stdio.h>
int main()
{
	/**********  Begin  **********/
    	double l;
	int i=0;
    int s=0;
    double t=0;
	char a[10];
	scanf("%d %d %d %d %d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9]);
	for(i=0;i<10;++i){
		if(a[i] > 0){
        ++t;
		s += a[i];
	}
	}
    if(t == 0){
        l = 0.0;
    }else{
	l = (double)(s/t);
    }
	printf("累加和:%d\n平均值:%.1f",s,l);
	/**********  End  **********/
    return 0;
}