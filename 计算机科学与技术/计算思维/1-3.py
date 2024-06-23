 # 本程序要求打印九九乘法表前N行

N = int(input())

#   请在此添加实现代码   #
# ********** Begin *********#
for i in range(1,N+1):
    for j in range(1,i+1):
        if j != i:
            print("%d * %d = %d"%(i,j,i*j),end='\t')
        else:
            print("%d * %d = %d"%(i,j,i*j))



# ********** End **********#