#include<stdio.h>
#include<string.h>
int main()
{
    char a[100000];
    int word[29]={0};
    char x[100000];
    char b[60];
    scanf("%s",a);
    getchar();
    gets(b);

    for (size_t i = 0; i < strlen(a); i++)
    {
        word[a[i]-'a']++;
    }
    
    for (size_t t = 0; t < 52; t+=2)
    {
        if (word[(b[t]-'a')]==0)
        {
            continue;
        }else
        {
            //printf("iamsb");   
            char s[1000];
            strnset(s,'a',word[(b[t]-'a')]);
            s[word[(b[t]-'a')]+1]='\0';
            printf("%s",s);
            
        }
    }
    return 0;
    
}