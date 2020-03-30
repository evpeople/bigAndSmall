#include<stdio.h>
enum CHARS
{
    capital,lowercase,digit,others,line,max,min,letter,LOWletter
};
typedef enum CHARS Chars;
//注意！！！换行符有问题！！！！！
//统计字符
//可以用来求各种字符的数量，所以可以用来算换行
int sum_of_Char(FILE * fPtr,Chars a,int letters);
int maxAndMin(FILE*fPtr,Chars a,int line);
int main(void)
{
    FILE *fPtr;
    fPtr=fopen("dict.dic","r");
    int task;
    int answer[9];//用于输出前两个任务的答案
    int task3[28];//用于输出字母个数
    char lett='A';//用于方便printf
    Chars a;
    scanf("%d",&task);
    switch (task)
    {
    case 1://统计四种字符
        a=capital;
        while (a!=line)
        {
            answer[a]=sum_of_Char(fPtr,a,0);
            a++;
        }
        a--;
        answer[a]=(answer[a]-answer[0]-answer[1]-answer[2]-1);
        fclose(fPtr);
        printf("Task1:\ncapital: %d\nlowercase: %d\ndigit: %d\nothers: %d",answer[0],answer[1],answer[2],answer[3]);  
        break;
    case 2:
        a=line;
        answer[line]=sum_of_Char(fPtr,a,30);
        a=max;
        answer[max]=maxAndMin(fPtr,a,answer[line]);
        a=min;
        answer[min]=maxAndMin(fPtr,a,answer[line]);
        fclose(fPtr);
        printf("Task2:\nline: %d\n%d characters in max line.\n%d characters in min line.",answer[line],answer[max],answer[min]);
        break;
    case 3:
        a=letter;
        int letters=1;
        printf("Task3:\nCAPITAL:\n");
        while (letters!=27)
        {
            task3[letters]=sum_of_Char(fPtr,a,letters);
            letters++;
        }
        letters=1;
        while (letters!=27)
        {
            printf("%c:%d\n",lett,task3[letters]);
            letters++;
            lett++;
        }
        letters=1;
        lett='a';
        a=LOWletter;
        printf("LOWERCASE:\n");
        while (letters!=27)
        {
            task3[letters]=sum_of_Char(fPtr,a,letters);
            letters++;
        }
        letters=1;
        while (letters!=27)
        {
            printf("%c:%d\n",lett,task3[letters]);
            letters++;
            lett++;
        }
        fclose(fPtr);
        break;
    default:
        break;
    }
    return 0;
}
//a为我要求和的类型，letters=0 则为task1，30则为行数，1-26代表26个字母
//查找应该是相同的操作
/*enum CHARS
{
    capital,lowercase,digit,others,line,max,min,letter
};*/
int sum_of_Char(FILE * fPtr,Chars a,int letters)
{

    int ch=0;
    int answer=0;
    rewind(fPtr);
    switch (a)
    {
    case capital:
        while (ch!=EOF)
        {
            ch=fgetc(fPtr);
            if (ch<='Z'&&ch>='A')
            {
                answer++;
            }    
        }
        
        break;
    case lowercase:
        while (ch!=EOF)
        {
            ch=fgetc(fPtr);
            if (ch<='z'&&ch>='a')
            {
                answer++;
            }    
        }
        break;
    case others:
        while (ch!=EOF)
        {
            ch=fgetc(fPtr);
            //求出总和再做差
            answer++;
                
        }
        break;
    case digit:
        while (ch!=EOF)
        {
            ch=fgetc(fPtr);
            if (ch<='9'&&ch>='0')
            {
                answer++;
            }    
        }
        break;
    case line:
        while (ch!=EOF)
        {
            ch=fgetc(fPtr);
            if (ch=='\n'||ch==EOF)
            {
                answer++;
            }    
        }
        break;
    //大写
    case letter:
        while (ch!=EOF)
        {
            ch=fgetc(fPtr);
            if (ch=='A'-1+letters)
            {
                answer++; 
            }
            
        }
        
        break;
    case LOWletter:
        while (ch!=EOF)
        {
            ch=fgetc(fPtr);
            if (ch=='a'-1+letters)
            {
                answer++; 
            }
            
        }
        break;

     }
    return answer;
}
int maxAndMin(FILE*fPtr,Chars a,int line)
{
    rewind(fPtr);
    int answer,temp=0;
    int templine=1;
    int ch=0;
    switch (a)
    {
    case max:
        answer=0;
     
        while (ch!=EOF)
        {
            if (templine!=line)
            {
                ch=fgetc(fPtr);
                temp++;
                if (ch!='\n')
                {
                  continue;
                }
                
                if (ch=='\n')
                {
                    templine++;
                    temp--;
                    answer=answer>temp? answer:temp;
                    temp=0;
                    continue;
                }
            }
            if (templine==line)
            {
                temp=0;
                while (ch!=EOF)
                {
                    ch=fgetc(fPtr);
                    temp++;
                }
                temp--;   
                answer=answer>temp?answer:temp;
            }
        }
        break;
    case min:
        answer=1000000;
     
        while (ch!=EOF)
        {
            if (templine!=line)
            {
                ch=fgetc(fPtr);
                temp++;
                if (ch!='\n')
                {
                  continue;
                }
                if (ch=='\n')
                {
                    templine++;
                    temp--;
                    answer=answer<temp? answer:temp;
                    temp=0;
                    continue;
                }
            }
            if (templine==line)
            {
                temp=0;
                while (ch!=EOF)
                {
                    ch=fgetc(fPtr);
                    temp++;
                }
                temp--;
                answer=answer<temp?answer:temp;
            }
        }    
        break;
    default:
        break;
    }
    return answer;
}