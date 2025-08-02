#include<stdio.h>
#include<string.h>
/*********************************************************************************
  完成函数，连接filename1、filename2 和 filename3 三个文件的内容到 filename 文件中
  先连接file1，再连接file2，最后连接file3
  ********************************************************************************/
void connect(char *filename,char *filename1,char *filename2,char *filename3)
{
	// 请在此处编辑您的代码
	/********** Begin **********/
  FILE* fp1 = fopen(filename1,"r+");
  FILE* fp2 = fopen(filename2,"r+");
  FILE* fp3 = fopen(filename3,"r+");
  FILE* fp4 = fopen(filename,"r+");

  char buf[1024];
  while(fgets(buf,sizeof(buf),fp1) != NULL)
  {
    fputs(buf,fp4);
  }
  while(fgets(buf,sizeof(buf),fp2) != NULL)
  {
    fputs(buf,fp4);
  }
  while(fgets(buf,sizeof(buf),fp3) != NULL)
  {
    fputs(buf,fp4);
  }
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
  fclose(fp4);
	/********** End **********/
   
}