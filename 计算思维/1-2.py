# 请验证输入的列表N_list中的整数是否为五位数，并返回五位数整数的最高位数值

N_list = [int(i) for i in input().split(',')]

#   请在此添加实现代码   #
# ********** Begin *********#
my_list = []
for i in range (0,len(N_list)):
    for j in range(0, 4):
        N_list[i] = N_list[i] // 10
    if N_list[i] > 0 and N_list[i] < 10:
        my_list.append(N_list[i])
print(my_list)

# ********** End **********#
