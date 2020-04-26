#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX_MEMORY 65535
int ax[9]={0};//八个通用寄存器 ax[0]不使用
int memory[MAX_MEMORY];//内存
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
int getLineOfCommand(FILE*ptr);
int binToDec(const char*s,int n);//s为二进制字符串，n为字符串位数//
void makeCommand(command *temp,const char*s );
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
    FILE* fptr;
    fptr=fopen("dict.dic","r");
    int numberOfCommand=0;
    int i=1;
    char tempCommand[39];
    numberOfCommand=getLineOfCommand(fptr);
    fseek(fptr,0,SEEK_SET);
    command allCommand[numberOfCommand];
    command *ptrOfCommand=NULL;
    ptrOfCommand=(command*)malloc(sizeof(command));
    while (i!=numberOfCommand+1)
    {
        ptrOfCommand=&allCommand[i];
        fgets(tempCommand,39,fptr);
        makeCommand(ptrOfCommand,tempCommand);
        allCommand[i].ipOfCommand=i;
        memory[i*2]=ptrOfCommand->dataOfCpu;
        i++;
       // printf("ipofcommand=%d\n,kindofcommand=%d\nendofaddress=%d\nbeginofaddress\nnumber=%d\n",ptrOfCommand->ipOfCommand,ptrOfCommand->kindofcommand,ptrOfCommand->endofaddress,ptrOfCommand->beginofaddress,ptrOfCommand->number);
    }
    
    //printf("%d",binToDec("1111111111100100",16));
    fclose(fptr);
    int tempflag=0;
    int tempjump=0;
    int stopFlag=0;
    cpu*temp;
    temp=(cpu*)malloc(sizeof(cpu));
    temp->ip=0;
    temp->flag=0;
    temp->ir=0;
    ptrOfCommand=&allCommand[1];
    command* firstCommand=ptrOfCommand;
    while (1)
    {
        
        switch (ptrOfCommand->kindofcommand)
        {
            
            case STOP:
                stopFlag=1;
                changeCpu(4,tempflag,ptrOfCommand->irTocpu,temp);
                outPutCpu(temp);
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
                outPutCpu(temp);
                break;
            case IN:
                myScanf(ptrOfCommand);            
                changeCpu(4,tempflag,ptrOfCommand->irTocpu,temp);
                outPutCpu(temp);
                break;
            case OUT:
                myPrintf(ptrOfCommand);
                changeCpu(4,tempflag,ptrOfCommand->irTocpu,temp);
                outPutCpu(temp);
                break;
            default:
                math(ptrOfCommand);
                changeCpu(4,tempflag,ptrOfCommand->irTocpu,temp);
                outPutCpu(temp);
                break;
        }
        if (stopFlag==1)
        {
            break;
        }
        ptrOfCommand=firstCommand+(temp->ip)/4;        
    }
    int x=0;
    int unUseMemory[8*16]={0};
    int lengthOfCommand=numberOfCommand;
    int templength=1;
    int changeLength=0;
    printf("\ncodeSegment :\n");
    for (size_t i = 2; i < 2+16*16; i+=2)
   {
       printf("%d",memory[i]);
       if (changeLength!=7)
       {
           printf(" ");
           changeLength++;
       }else
       {
           printf("\n");
           changeLength=0;
       }
   }
    i=0;
    changeLength=0;
    printf("\ndataSegment :\n");
   for (size_t i = 16384; i < 16384+32*16; i+=2)
   {
       printf("%d",memory[i]);
       if (changeLength!=15)
       {
           printf(" ");
           changeLength++;
       }else
       {
           printf("\n");
           changeLength=0;
       }
   }
    return 0;
}
int getLineOfCommand(FILE*fptr)
{   
    
    char stop[37]="00000000 00000000 0000000000000000";
    char temp[37]="22222222 22222222 222222222222";
    int tempnumber=0;        
    while (strcmp(temp,stop))
    {
        fgets(temp,39,fptr);
        temp[34]='\0';
        tempnumber++;
        //printf("%d",strcmp(temp,stop));
    }
    
    return tempnumber;
    //printf("%d",numberOfCommand);
}
int binToDec(const char*s,int n)
{
    char temp[39];
    strcpy(temp,s);
    int i=0;
    int binFlag=0;
    double answer=0;
    if (temp[0]=='1'&&n==16)
    {
        binFlag=1;
    }
    
    while (n>0)
    {
        if (temp[i]==' ')
        {
            i++;
            continue;
        }
        
        answer+=(temp[i]-'0')*pow(2.0,(n-1)*1.0);
        i++;
        n--;
    }
    if (binFlag==1)
    {
        answer-=65536;
    }
    
    return answer;

}
void makeCommand(command *ptr,const char*s)
{
    char a[5];//前四位
    char b[5];//后四位
    char number[18];//立即数
    for (size_t i = 0; i < 16; i++)
    {
        if (i<4)
        {
            b[i]=s[i+13];
            a[i]=s[i+9];
        }
        number[i]=s[i+18];  
    }

    ptr->kindofcommand=binToDec(s,8);
    ptr->irTocpu=binToDec(s,16);
    ptr->dataOfCpu=binToDec(s,32);
    ptr->endofaddress=binToDec(a,4);
    ptr->beginofaddress=binToDec(b,4);
    ptr->number=binToDec(number,16);
    
//    getchar();
    
    
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
    printf("\n");
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
        ax[temp->endofaddress]=memory[ax[temp->beginofaddress]];
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
    }else if (temp->beginofaddress==1&&flag==0)
    {
        return temp->number;
    }else if (temp->beginofaddress==2&&flag==1)
    {
        return temp->number;
    }else if (temp->beginofaddress==3&&flag==-1)
    {
        return temp->number;
    }else
    {
        return 4;
    }
    
    
    
            
}
void myScanf(command* temp)
{
    printf("in:\n");
    scanf("%d",&ax[temp->endofaddress]);
    //memory[16384]=ax[temp->endofaddress];
    //inAndOutTimes+=2;//此指令需要在每个动了memory的命令后面都加一遍，负责不能多次输入
}
void myPrintf(command* temp)
{
    printf("out: %d\n",ax[temp->endofaddress]);
}