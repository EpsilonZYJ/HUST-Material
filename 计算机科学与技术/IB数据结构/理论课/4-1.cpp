void ShiftRightCircular(ElemType *A,int n,int k)
{
    if(k % n == 0)
        return;
    int start = 0;
    int init = A[0];
    int cnt = 0;
    int i = (k+n) % n;
    while(cnt < n){
        int tmp = A[i];
        A[i] = init;
        init = tmp;
        cnt ++;
        if(i == start){
            i = (i+1)%n;
            init = A[i];
            start = i;
        }
        i = (i+k+n)%n;
    }
}