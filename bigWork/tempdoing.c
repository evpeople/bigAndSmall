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
enum kindOfTheCommand{STOP,TRAVELDATE,COMPARE=9,JUMP,IN,OUT};
void outPutCpu(cpu* temp);
void traveldate(command* temp);
void math(command* temp);
int doMath(int a,int b,int state);//a为主操作数
int compare(command*temp);
int jump(command* temp,int flag);
void myScanf(command* temp);
void myPrintf(command* temp);
void changeCpu(int changeIp,int changeFlag,int changeIr,cpu*temp);

int main()
{
    //测试用代码
    // ptrOfCommand->ipOfCommand=1;
    // ptrOfCommand->beginofaddress=0;
    // ptrOfCommand->endofaddress=5;
    // ptrOfCommand->dataOfCpu=185597952;
    // ptrOfCommand->irTocpu=337;
    // ptrOfCommand->kindofcommand=1;
    // ptrOfCommand->number=16384;
    int tempflag=0;
    int tempjump=0;
    int stopFlag=0;
    cpu*temp;
    temp=(cpu*)malloc(sizeof(cpu));
    temp->ip=0;
    temp->flag=0;
    temp->ir=0;
    while (1)
    {
        
        switch (ptrOfCommand->kindofcommand)
        {
            
            case STOP:
                stopFlag=1;
                break;
            case TRAVELDATE:
                traveldate(ptrOfCommand);
                changeCpu(4,tempflag,ptrOfCommand->irTocpu,temp);
                outPutCpu(temp);   
                break;
            case COMPARE:
                tempflag=compare(ptrOfCommand);
                changeCpu(4,tempflag,ptrOfCommand->irTocpu,temp);
                outPutCpu(temp);
                break;
            case JUMP:
                tempjump=jump(ptrOfCommand,temp->flag);
                changeCpu(tempjump,tempflag,ptrOfCommand->irTocpu,temp);
                break;
            case IN:
                myScanf(ptrOfCommand);            
                break;
            case OUT:
                myPrintf(ptrOfCommand);
                break;
            default:
                
                break;
        }
        if (stopFlag==1)
        {
            break;
        }
        ptrOfCommand=&tempCommand[(temp->ip)/4];        
    }
    

}
void outPutCpu(cpu* temp)
{
    printf("ip = %d\nflag = %d\nir = %d\n",temp->ip,temp->flag,temp->ir);
    for (size_t i = 1; i < 9; i++)
    {
        if (i==5)
        {
            printf("\n");
        }
        
        printf("ax%d = %d ",i,ax[i]);
    }
    
}
void traveldate(command* temp)
{
    switch (temp->beginofaddress)
    {
    case 0:
        ax[temp->endofaddress]=temp->number;
        break;
    case 1:case 2:case 3: case 4:
        memory[ax[temp->endofaddress]]=ax[temp->beginofaddress];
        break;
    default:
        ax[temp->endofaddress]=memory[ax[temp->endofaddress]];
        break;
    }
}
int doMath(int a,int b,int state)
{
    if (state==2)
    {
        return a+b;
    }
    if (state==3)
    {
        return a-b;
    }
    if (state==4)
    {
        return a*b;
    }
    if (state==5)
    {
        return a/b;
    }
    if (state==6)
    {
        return a&&b;
    }
    if (state==7)
    {
        return a||b;
    } 
    if (state==8)
    {
        return !a;
    }
    if (state==9)
    {
        return a==b?0:(a<b?-1:1);
    }
    
}
void math(command* temp)
{
 
    if (temp->beginofaddress==0)
    {
       ax[temp->endofaddress]=doMath(ax[temp->endofaddress],temp->number,temp->kindofcommand);
 
    }else if (temp->kindofcommand==8)
    {
        memory[ax[temp->beginofaddress]]=doMath(memory[ax[temp->beginofaddress]],0,8);
    }else
    {
        ax[temp->endofaddress]=doMath(ax[temp->endofaddress],memory[ax[temp->beginofaddress]],temp->kindofcommand);
    }
}
void changeCpu(int changeIp,int changeFlag,int changeIr,cpu*temp)
{
    temp->ip+=changeIp;
    temp->flag=changeFlag;
    temp->ir=changeIr;
}
int compare(command*temp)
{
    if (temp->beginofaddress==0)
    {
        return doMath(ax[temp->endofaddress],temp->number,temp->kindofcommand);
    }else
    {
        return doMath(ax[temp->endofaddress],memory[ax[temp->beginofaddress]],temp->kindofcommand);
    }
}
int jump(command* temp,int flag)
{
    if (temp->beginofaddress==0)
    {
        return temp->number;
    }else if (temp->beginofaddress==1)
    {
        return temp->number;
    }else if (temp->beginofaddress==2)
    {
        return temp->number;
    }else if (temp->beginofaddress==3)
    {
        return temp->number;
    }
    
    
    
        
}
void myScanf(command* temp)
{
    printf("in:\n");
    scanf("%d",&ax[temp->endofaddress]);
    memory[16384+inAndOutTimes]=ax[temp->endofaddress];
    //inAndOutTimes+=2;//此指令需要在每个动了memory的命令后面都加一遍，负责不能多次输入
}
void myPrintf(command* temp)
{
    printf("out: %d\n",ax[temp->endofaddress]);
}