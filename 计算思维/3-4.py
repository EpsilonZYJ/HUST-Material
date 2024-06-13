class Counter(object) :
    def __init__(self, fun) :
        self._fun = fun
        self.counter=0
    def __call__(self,*args, **kwargs) :
        self.counter += 1
        return self._fun(*args, **kwargs)

@Counter
def Fibonacci(n):
   #********* Begin *********#
   # 在此处补全代码#
    if n==1:
       return 1
    elif n==0:
        return 0
    else:
       return  Fibonacci(n-1)+Fibonacci(n-2)
   #********* End *********#