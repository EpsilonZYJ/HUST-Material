def fact(n):
  #  ********* Begin *********#
  #  在此处补全代码#
    if n<=1:
        product=1
    else:
        product=n*fact(n-1)
    return product
  #  ********* End *********#