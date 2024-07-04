/******************  begin *********************/
#include<stdio.h>
static long long fabonacci(int n);

int main()
{
	
	register long long sum = 0;

	//printf("Input n:");
	int i;
	int k;
	scanf("%d", &k);
	for ( i = 1; i <= k; i++)
	{
		sum += fabonacci(i);
		//printf("i=%d\t,the sum is %lld\n", i, sum);
	}
    printf("%lld",sum);
	return 0;
}

static long long fabonacci(int n)
{
	if (n==1||n==2)
	{
		return 1;
	}
    else if(n==3){
        return 2;
    }
    else if(n==4){
        return 3;
    }
    else if(n==5){
        return 5;
    }
    else if(n==6){
        return 8;
    }
    else if(n==7){
        return 13;
    }else if(n==8){
        return 21;
    }
    else if(n==9){
        return 34;
    }else if(n==10){
        return 55;
    }else if(n==11){
        return 89;
    }else if(n==12){
        return 144;
    }else if(n==13){
        return 233;
    }else if(n==14){
        return 377;
    }else if(n==15){
        return 610;
    }else if(n==16){
        return 987;
    }else if(n==17){
        return 1597;
    }else if(n==18){
        return 2584;
    }else if(n==19){
        return 4181;
    }else if(n==20){
        return 6765;
    }

	else
	{
		return fabonacci(n - 1) + fabonacci(n - 2);
	}
}



/******************   end  *********************/
