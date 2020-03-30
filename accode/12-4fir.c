//目前情况是beginandend* calculation有问题，计数不对。可能是1没问题2 有问题3 有问题
//上已解决，现在出现了不能以注释开头不能/**/or/*开头，不能//  /n开头
/*//
	@Author: BUPT
	@Date: 2010 8 26
*///这种不能通过
/*
//

	@Author: BUPT
	@Date: 2010 8 26
*/  //这种可以

//遇到的麻烦，fgets可以读的量有限，大概是不能超过缓冲区，更改方法，从该位置进去，然后删除最后返回，那么就不需要计数函数了
//末尾的注释
#include<stdio.h>
#include <stdlib.h>
//思路，先实现只有//的模式，且直接不管几组
//然后实现/**/，且不管机组
//接着实现混合
//最后是分组定位
//需要一个函数，可以做到找从已知到某一特定字符之间总共多少字符
//上函数不需要了，原因见头，改为使用删除函数。
//enum STATE {DOUBLEGANG,GANGXING,NONE};
struct BEANDEND
{
    int a;
    int b;
};
typedef struct BEANDEND beginandend;
void delWordone(FILE*fp,int begin,int end);//begin和and为开始和结束的ftell的值，而非行数
//void delWordtwo(FILE*fp);
int delSomeWord(FILE* ptr,char lastWorld,char useful,long lastpoint);
beginandend* calculation(int a[3],FILE* fp);//传入开始行数结束行数得到值
int note1(FILE *p);
int note2(FILE *p,int line,int high);

int main()
{
    FILE* fp;
    fp=fopen("dict.dic","r");
    int firstFive[7];//前五行
    int temp=1;
    firstFive[0]=5;
    while (temp<8)
    {
        fscanf(fp,"%d",&firstFive[temp]);
        temp++;
    }
    scanf("%d",&temp);
    //temp=4;
    if (temp!=4)
    {
        
        int a[3];//所用两行
        a[0]=firstFive[temp-1];
        a[1]=firstFive[temp];
        beginandend * i= calculation(a,fp);
        rewind(fp);
        delWordone(fp,i->a,i->b);
        fclose(fp);        
    }
    else
    {   
        fclose(fp);    
        FILE *p=fopen("dict.dic","r");
        int line=1,low=6,high,i;	
	    char ch;
    	fscanf (p,"%d",&high);
	
	    i=4;
	    line++;
	    for (;line<=5;line++)
    	{
	    	if (line<=i)
		    {
			    low=high+1;
			    fscanf (p,"%d",&high);
		    }else	fscanf (p,"%*d");
	    }
	    fseek(p,2,1);	
	    while(line!=low)
	    {
		    ch=fgetc(p);
		    if (ch=='\n')	line++;
	    }
	    line=low; 
	    while(line!=high+1)
	    {
		    ch=fgetc(p);
		    if (ch=='/')
		    {
			    ch=fgetc(p);
			    if (ch=='/')
			    {
				    note1(p);	
			    	printf ("\n");
				    line++;
			    }else
			    {
				    if (ch=='*')
				    {
					    line=note2(p,line,high);	
				    }else	printf ("/%c",ch);
			    }
		    }else	printf ("%c",ch);
		    if (ch=='\n')	line++;
		    if (feof(p)!=0)	break;	
	    }
	    fclose(p);

    }
    
 
    return 0;
   
}

void delWordone(FILE*fp,int begin,int end)
{
    char ch,ch2;
    //char *temp;
    //enum STATE i=NONE; //i 用于判断是否在某一种注释中 
    long strlen;
    //int jcbl;
    FILE *fptr=fp;    
     fseek(fptr,begin,SEEK_SET);
    
   
                 
      
       while(ftell(fptr)!=end)
        {//逐字符复制
            ch=fgetc(fptr);//从源文件读取一个字符
            ch2=getc(fptr);

            
            if (ch=='/'&&ch2=='/')
                {
                    //i=DOUBLEGANG;
                    //fgets(temp,50000000000,fptr);
                   // jcbl=ftell(fptr);
                    strlen=delSomeWord(fptr,'\n','\n',end);
                    if (strlen==-100)
                    {
                        //printf("\n");
                        continue;
                    }
                    
                    fseek(fptr,strlen,SEEK_SET);//这个位置是/n，然后读\n的下一个
                    //jcbl=ftell(fptr);
                    if (strlen==-2)
                    {
                        return ;
                    }
                    
                    continue;
                }//如果找到了//则读到换行符为止，然后进入下一行。//注！！！！！！！！下一行可能还是//开头
            //fseek(fptr,-1,SEEK_CUR);//如果没有读到换行符，就回退一格，防止0// 的发生。
            //putchar(ch);
            if (ch=='/'&&ch2=='*')
                {
                    //i=DOUBLEGANG;
                    //fgets(temp,50000000000,fptr);
                   // jcbl=ftell(fptr);
                    strlen=delSomeWord(fptr,'*','/',end);
                    if (strlen==-100)
                    {
                        //printf("\n");
                        continue;
                    }
                    if (strlen==-3)
                    {
                        return;
                    }
                    
                    fseek(fptr,strlen,SEEK_SET);
                    //jcbl=ftell(fptr);
                    continue;
                }//如果找到了//则读到换行符为止，然后进入下一行。//注！！！！！！！！下一行可能还是//开头
            // if (ch2!='\n')
            // {
            //     fseek(fptr,-1,SEEK_CUR);//如果没有读到换行符，就回退一格，防止0// 的发生。
            // }
            // else
            // {
            //     fseek(fptr,-2,SEEK_CUR);//换行符为两格
            // }


            //上面的一串是因为123 121 /n为两位，但提示输出超限。
            fseek(fptr,-1,SEEK_CUR);//如果没有读到换行符，就回退一格，防止0// 的发生。
            

            putchar(ch);
            if (ch2==EOF)
                {
                    break;
                }   
            //ch=fgetc(fptr);
        }
  
   
   
}

int delSomeWord(FILE* ptr,char lastWord,char useful,long lastpoint)
{


    int test=1;
    char temp=0;
    char temp1=0;
    

    temp=fgetc(ptr);
    temp1=fgetc(ptr);
    if (lastWord=='\n')
    {
        fseek(ptr,-1,SEEK_CUR);
        while (temp!=lastWord&&ftell(ptr)!=lastpoint)
        {
            test=0;
            temp=fgetc(ptr);
        }
        if (ftell(ptr)==lastpoint)
        {
            return -2;
        }
        
        if (!test)
        {
            return ftell(ptr)-1;//之所以-1，为了返回/n 的准确位置
        }
        else return -100;       
    }
    else
    {/**/
        fseek(ptr,-1,SEEK_CUR);
        while ((temp!='*'||temp1!='/')&&ftell(ptr)!=lastpoint)
        {
            test=0;
            temp=fgetc(ptr);
            temp1=fgetc(ptr);
            fseek(ptr,-1,SEEK_CUR);
        }
        if (ftell(ptr)==lastpoint)
        {
           return -3;
        }
        
       if (!test)
        {
            return ftell(ptr)+1;//返回的是/ 后面的位置
        }
        else return -100;     
    }
    
    


}
//不能处理//接空行 不能处理多个//
beginandend * calculation(int a[3],FILE* fp)
{
    beginandend * temp=(beginandend* )malloc(sizeof(beginandend));
    rewind(fp);
    int line=0;
    int i=0;
    char hs;
    while (!feof(fp))
    {   
        hs=fgetc(fp);
        if (hs!='\n')
        {
            continue;
        }
        else
        {
            line++;
            if (a[i]==line&&i==0)
            {
                temp->a=ftell(fp);
                i++;
            }
            if (a[i]==line&&i==1)
            {
                  /////////////////此处有问题，白天再调！！！！！！！！！！！！
                temp->b=ftell(fp);
                break;
            }
        }
      
        
    }
    return temp;
    





}
 int note1(FILE *p)
 {
 	char ch=fgetc(p);
 	while (ch!='\n')
 	{
 		if (feof(p)!=0)	break;	
 		ch=fgetc(p);	
	 }
	 return 0;
 }
 
 int note2(FILE *p,int line,int high)
 {
 	char ch=fgetc(p),temp=fgetc(p);
 	while(line!=high+1)
 	{
 		if (ch=='\n')	line++;
 		if (ch=='*'&&temp=='/')	break;
 		ch=temp;
 		temp=fgetc(p);
	 }
	 return line;
 }