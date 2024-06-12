TSMatrix ADD(TSMatrix A,TSMatrix B)
//返回矩阵A、B相加的结果
{
    TSMatrix ans;
    ans.mu = A.mu;
    ans.nu = A.nu;
    int ia = 1;
    int ib = 1;
    int ians = 1;
    while (ia <= A.tu && ib <= B.tu) {
        if (A.data[ia].i == B.data[ib].i && A.data[ia].j == B.data[ib].j) {
            ans.data[ians].i = A.data[ia].i;
            ans.data[ians].j = A.data[ia].j;
            ans.data[ians].e = A.data[ia].e + B.data[ia].e;

            if (ans.data[ians].e)
                ians++;
            ia++;
            ib++;
        } else if (A.data[ia].i > B.data[ib].i) {
            ans.data[ians].i = B.data[ib].i;
            ans.data[ians].j = B.data[ib].j;
            ans.data[ians].e = B.data[ib].e;

            ians++;
            ib++;
        } else if (A.data[ia].i < B.data[ib].i) {
            ans.data[ians].i = A.data[ib].i;
            ans.data[ians].j = A.data[ib].j;
            ans.data[ians].e = A.data[ib].e;

            ians++;
            ia++;
        } else if (A.data[ia].j > B.data[ib].j) {
            ans.data[ians].i = B.data[ib].i;
            ans.data[ians].j = B.data[ib].j;
            ans.data[ians].e = B.data[ib].e;

            ians++;
            ib++;
        } else if (A.data[ia].j < B.data[ib].j) {
            ans.data[ians].i = A.data[ib].i;
            ans.data[ians].j = A.data[ib].j;
            ans.data[ians].e = A.data[ib].e;

            ians++;
            ia++;
        }
    }
    while (ia <= A.tu) {
        ans.data[ians].i = A.data[ib].i;
        ans.data[ians].j = A.data[ib].j;
        ans.data[ians].e = A.data[ib].e;

        ians++;
        ia++;
    }
    while (ib <= B.tu) {
        ans.data[ians].i = B.data[ib].i;
        ans.data[ians].j = B.data[ib].j;
        ans.data[ians].e = B.data[ib].e;

        ians++;
        ib++;
    }
    ans.tu = ians - 1;
    return ans;
}