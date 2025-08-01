# 请用函数实现arctg泰勒级数计算，包含隐含参数N
def arctg(x, N=5):
    '''
    :param x: 输入值
    :param N: 迭代项数，缺省值为5
    :return: arctg值
    '''
    #   请在此添加实现代码   #
    # ********** Begin *********#
    sum = 0
    for n in range(1, N + 1):
        sum += (((-1) ** (n - 1)) * (x ** (2 * n - 1)) / (2 * n - 1))
    return sum

    # ********** End **********#