#coding=utf-8

from math import pi as PI

n = input()

# 请在此添加函数circle_area的代码，返回以n为半径的圆面积计算结果
#********** Begin *********#
def circle_area(n):
    if n.isdigit():
        n=int(n)
        return ("%.2f"%(n*n*PI))
    else:
        return "You must input an integer or float as radius."




#********** End **********#
print(circle_area(n))