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
int getLineOfCommand(FILE*ptr);
int binToDec(const char*s,int n);//s为二进制字符串，n为字符串位数//
void makeCommand(command *temp,const char*s );
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
    while (numberOfCommand!=i)
    {
        ptrOfCommand=&allCommand[i];
        fgets(tempCommand,39,fptr);
        makeCommand(ptrOfCommand,tempCommand);
        allCommand[i].ipOfCommand=i;
        i++;
        printf("ipofcommand=%d\n,kindofcommand=%d\nendofaddress=%d\nbeginofaddress\nnumber=%d\n",ptrOfCommand->ipOfCommand,ptrOfCommand->kindofcommand,ptrOfCommand->endofaddress,ptrOfCommand->beginofaddress,ptrOfCommand->number);
    }
    
    //printf("%d",binToDec("1111111111100100",16));
    fclose(fptr);

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