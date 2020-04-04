/*互联网中存在许多的不和谐词汇，在我们浏览互联网的时候，搜索引擎经常会出现提示信息“根据相关法律法规和政策，部分搜索结果未予显示”。小王同学也想制作一个自己的屏蔽词库，
这样他就可以将自己不喜欢的词汇从文件中换成别的字符了。屏蔽词库是一个ASCII码文件，这个文件中只含有单词，每个单词占一行，每个单词中只可能有大小写字母与空格。
题目中和谐词库的文件名为dict.dic。（屏蔽词库中每个词汇长度小于10，屏蔽词汇个数不超过10.）
你的任务是将输入中的所有和谐词库中的词语全部替换成“!@#$%^&*”（按住键盘shift和数字1至8），然后输出。
这里要注意，如果一个词语中包含屏蔽词汇，那么只将屏蔽词汇替换，
例如“hehasAAA”被处理后将得到“he!@#$%^&*AAA”，注意屏蔽词汇区分大小写，即aaa与AAA是两个不同的单词，
为了使问题简化，屏蔽词汇中不会出现互相包含的情况，如“xabcx”与“abc”不会同时出现在同一个屏蔽词库中。由于小王同学很不擅长文件操作，所以他希望你能帮他制作这个屏蔽词汇程序。
*/
/*首先打开和谐词库的文件，然后读且只读一个词,多次读取，用边长数组*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//第一个函数用于按顺序读词库中的词。返回此时指针的位置方便下一次使用,需要一个结构
typedef struct PB
{
    long pos;//ftell的位置
    char pbWords[12];
    int ifEnd;//此变量用于看是否为最后一个屏蔽词 1为最后
} pb;
pb * findPbWord(FILE* ftr,long pos);
//void changeWord(char need[120],char Words[12]);
int main()
{
    FILE *ptr;
    ptr=fopen("dict.dic","r");
    pb * Word;
    Word=(pb*)malloc(sizeof(pb));
    Word->ifEnd=0;
    char pbWord[11][12];
    char art[10][150];
    for (size_t i = 0; i < 10; i++)
    {
        memset(art,0,10*150*sizeof(char));
    }
    
    char tempc='\0',temps[15];
    int i=0,j=0,tempI,tempJ,len=0;
    long pos_temp=0;
    while (Word->ifEnd!=1)
    {
        Word=findPbWord(ptr,pos_temp);
        strcpy(pbWord[i],Word->pbWords);
        pos_temp=Word->pos;
        i++;//总共的屏蔽词个数
    }
    fclose(ptr);
    tempI=i;
    i=0;
    int flag=0;
    int x=-1;
    while (x!=2)
    {
        while (tempc!='\n')
        {
            tempc=getchar();
            if (tempc=='\n')
            {
                flag=1;
            }
            
            if(tempc!=' ')
            {
                temps[len]=tempc;
                len++;
                if (!flag)
                {
                    continue;
                }
                

            }
            int flaglen=len;
            flaglen--;
            if (!flag)
            {
                temps[len]=' ';
                temps[len+1]='\0';
                len=0;
            }else
            {
                len--;
                temps[len]=' ';
                temps[len+1]='\0';
                len=0;

            }
            

        
        
            while (i<tempI)
            {
                int rightOrWrong;            
                rightOrWrong=strcmp(temps,pbWord[i]);
                if (!rightOrWrong)//相等
                {
                    strcpy(temps,"!@#$%^&* ");
                    break;
                }
                i++;
            }
            i=0;
            if (!flag)
            {
                strcat(art[j],temps);
            }else
            {
                temps[flaglen]='\0';
                strcat(art[j],temps);
            }
            
            

        }
        flag=0;
        tempc='\0';
        j++;//j为输入次数
        x++;
    }
    tempJ=j;
    j=0;
    while (j<tempJ)
    {
        puts(art[j]);
        j++;
    }
    return 0;
}
//第一个函数用于按顺序读词库中的词。返回此时指针的位置方便下一次使用,需要一个结构
pb * findPbWord(FILE* ftr,long pos)
{
    pb* temp=(pb*)malloc(sizeof(pb));
    char tempchar;
    char temps[12];
    int i=0;
    char a;
    fseek(ftr,pos,SEEK_SET);
    fgets(temps,12,ftr);
    strcpy(temp->pbWords,temps);
    a=temp->pbWords[i];
    i=1;
    while (a!='\n')
    {
        a=temp->pbWords[i];
        i++;
    }
    temp->pbWords[i-1]=' ';    
    temp->pbWords[i]='\0';
    temp->pos=ftell(ftr);
    tempchar=fgetc(ftr);
    if (tempchar==EOF)
    {
        temp->ifEnd=1;
    }
    return temp;
}

// void changeWord(char need[120],char Words[12])
// {
//     char*temp;
//     int len=strlen(Words);

//     temp=strstr(need,Words);
//     while (temp!=NULL)
//     {
//         while ()
//         {
//             /* code */
//         }
        
//         *temp='!';
//         *(temp+1)='@';
//         *(temp+2)='#';
//         *(temp+3)='$';
//         *(temp+4)='%';
//         *(temp+5)='^';
//         *(temp+6)='&';
//         *(temp+7)='*';
//         temp=strstr(need,Words);
//     }
    
// }