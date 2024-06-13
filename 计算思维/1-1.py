 # 本程序计算1-N整数平方的累加和

N = int(input())

#   请在此添加实现代码   #
# ********** Begin *********#
n=1
sum=0
while n<=N:
    sum+=n**2
    n+=1
print(sum)


# ********** End **********#