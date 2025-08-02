#include<stdio.h>

/*****请在下面补充函数 inArray、selectSort 和 outArray 的定义 *****/
void inArray(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

void selectSort(int arr[],int n){
    if(n<2){
        int m;
        if(arr[1]>arr[0]){
            ;
        }else if(arr[1]<arr[0])
        {
            m=arr[0];
            arr[0]=arr[1];
            arr[1]=m;
        }
    }else{
        int i;
        int max=0;
        int t;
        for(i=0;i<n;i++){
            if(arr[i]>max){
                max=arr[i];
                t=i;
            }
        }
        arr[t]=arr[n-1];
        arr[n-1]=max;
        selectSort(arr,n-1);
    }
}

void outArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

