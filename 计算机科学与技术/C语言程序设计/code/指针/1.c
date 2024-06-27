#include<stdio.h>
//冒泡升序排序 ，程序的输入为 int类型数组 和数组长度 
//请在此处编辑您的代码
/**********  Begin  **********/
void bubble_sort(int*p,int n){
    int *m;
    m=p;
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(m[j]>m[j+1]){
                temp=m[j+1];
                m[j+1]=m[j];
                m[j]=temp;
            }
        }
    }

}
/**********  End  **********/
