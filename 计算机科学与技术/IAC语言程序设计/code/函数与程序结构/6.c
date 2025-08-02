
/**
  按任务要求补全该函数
  用递归实现辗转相除法
 **/
int gcd(int x, int  y)
{
	/**********  Begin  **********/
    int c = 0;
    printf("%d %d\n",x,y);
    if(y == 0){
      return x;
    }else{
      c = x%y;
      x = y;
      y = c;
      return gcd(x,y);
    }
    
    
    /**********  End  **********/
}