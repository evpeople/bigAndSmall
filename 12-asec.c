#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fuc(FILE *fp);
char * examWord(char**ptr,char word[20],int numberOfMingGanci);
char* examsten(char**ptr,char setences[130],int numberOfMingGanci);

int main()
{
    FILE *fp = fopen("dict.dic", "r");
    fuc(fp);
    fclose(fp);

    return 0;
}
char*examWord(char**ptr,char word[20],int numberOfMin)

{

    int i=0,flag=1;
    while (i<numberOfMin)
    {
        flag=strcmp(ptr[i],word);
        if (flag==0)
        {
            strcpy(ptr[i],"!@#$%^&");
            break;
        }
        i++;
    }
    return word;
}
//char* examsten(char**ptr,char setences[130],int numberOfMingGanci)
void fuc(FILE *fp)
{
    char setences[130];
    int i,cnt;
    char **ptr;
    char *temp;
    ptr = (char **)malloc(sizeof(char *) * 111);
    i = 0;
    memset(setences,0,sizeof(char));
    while (!feof(fp)) //读入文件内的敏感字符到ptr中
    {
        ptr[i] = (char *)malloc(sizeof(char) * 30);
        fgets(ptr[i], 10, fp);
        if (ptr[i][strlen(ptr[i]) - 1] == '\n')
        {
            ptr[i][strlen(ptr[i]) - 1] = '\0';
        }
        i++;
    }
    cnt = i-1;//cnt is number of minganci
while (!feof(stdin))
{
    char word[20];
    int lenOfWord=0;
    int flag=0;
    word[lenOfWord]=getchar();    
    while (word[lenOfWord]!=' '&&word[lenOfWord]!='\n')//||word[lenOfWord]!='\n');
    {
        lenOfWord++;
        word[lenOfWord]=getchar();
    }
    if (word[lenOfWord-1]=='\n')
    {
        flag=1;
        word[lenOfWord-1]='\0';
    }
    word[lenOfWord]='\0';
    lenOfWord=0;
    strcpy(word,examWord(ptr,word,cnt));//此函数用于检查word内部有没有敏感词
    strcat(setences,word);
    if (flag==1)
    {
        //examsten(ptr,setences,cnt);
        puts(setences);
    }
}
}
    //printf("cnt==%d\n", cnt);


    /*while (gets(words) != EOF)//读取一段话
    {
        for (i = 0; i < cnt; i++)//最外层循环，来更新敏感词库
        {
            for (j = 0; j < strlen(words); j++)//内层循环，进行判断
            {
                f = 0;
                char temp[strlen(ptr[i])+1];//ptr是敏感词的长度。加一防止溢出且\0
                for (i1 = 0; f < strlen(ptr[i]);i1++)//把words的前strlen(ptr[i])个字符复制进去
                {
                    temp[i1] = words[j];
                    j++;
                    f++;
                }
                temp[strlen(ptr[i])] = '\0';//添加结束\0
                if(strcmp(temp,ptr[i])==0)//如果相等，则替换
                {
                    printf("!@#$%^&*");
                }
                else//否则输出
                {
                    printf("%s", temp);
                }
                j--;//复位j，进行下一次操作
            }
        }
    }
}*/