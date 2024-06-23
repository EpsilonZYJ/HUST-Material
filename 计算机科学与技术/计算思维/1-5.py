import math
def ln(x, N=50):
    '''
    :param x: 输入值
    :param N: 迭代项数，缺省值为50
    :return: 对数值，误差的绝对值
    '''
    #   请在此添加实现代码   #
    # ********** Begin *********#
    sum = 0
    for n in range(1, N + 1):
        sum += (((-1)**(n+1))/n)*((x-1)**n)
    return sum,math.fabs(math.log(x,math.e)-sum)
    # ********** End **********#