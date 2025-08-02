#include<stdio.h>

void move(int arr[],int n,int k){
	/**********  Begin  **********/
    int u[n];
    for(int i=0;i<k;i++){
        u[n-k+i]=arr[i];
    }
    for(int i=k;i<n;i++){
        u[i-k]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=u[i];
    }
    
    
    
    
	/**********  End  **********/
}
