#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX_MEMORY 65535
int ax[9]={0};//八个通用寄存器 ax[0]不使用
int memory[MAX_MEMORY];//内存
int inAndOutTimes=0;//是否使用还存疑
struct STATEOFCPU
{
    int ip;//为程序计数器
    int flag;//为标志寄存器
    int ir;//为指令寄存器ps仅是指令的前16位转化为的十进制值
};//cpu的状态，用于每一次的print
struct COMMAND//对一条命令进行分析
{
    int ipOfCommand;//第几条指令
    int irTocpu;//记录前16为的int值 ，传给state的ir。
    int kindofcommand;//前八位，用于获得指令类型
    //下面两个变量为中间八位的内容
    int endofaddress;//前四位，保存内容的寄存器名称
    int dataOfCpu;//完整的指令以备用，且最后输出代码段需要此变量
    int beginofaddress;//后四位，待操作内容的寄存器名称//注意！！！逻辑非需要特判
    int number;//立即数
};//分析指令

typedef struct COMMAND command;
typedef struct STATEOFCPU cpu;

int main()
{
    int i=0;
    command a[17];
    int unUseMemory[8*16]={0};
    int lengthOfCommand=17;
    int templength=1;
    int changeLength=0;
    printf("codeSegment :\n");
    while (i<16)
    {
        if (templength!=lengthOfCommand)
        {
            printf("%d",a[templength].dataOfCpu);
            if (changeLength!=8)
            {
                printf(" ");
                changeLength++;
            }else
            {
                printf("\n");
                changeLength=0;
                i++;
            }
            templength++;
            continue; 
        }
        for (size_t t = lengthOfCommand-1; t < 8*16; t++)
        {
            printf("%d",unUseMemory[t]);
            if (changeLength!=8)
            {
                printf(" ");
                changeLength++;
            }else
            {
                printf("\n");
                changeLength=0;
            }
        }
        break;
               
    }
    i=0;
    changeLength=0;
    printf("dataSegment :\n");
   for (size_t i = 16384; i < 16384+8*16; i++)
   {
       printf("%d",memory[i]);
       if (changeLength!=8)
       {
           printf(" ");
           changeLength++;
       }else
       {
           printf("\n");
           changeLength=0;
       }
   }
    
     
}