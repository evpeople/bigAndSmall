#include<stdio.h>
#include<string.h>
int main()
{
    char a[100000];
    int word[29]={0};
    //char x[100000];
    char b[60];
  gets(a);
    gets(b);

    for (size_t i = 0; i < strlen(a); i++)
    {
        word[a[i]-'a']++;
    }
    
    for (size_t t = 0; t < 27; t+=1)
    {
        if (word[(b[t]-'a')]==0)
        {
            continue;
        }else
        {
            int temp=word[b[t]-'a'];
            //char temps[temp];
            //printf("iamsb");
            if (temp>=200)
            {
              break;
            }
            
            for (size_t i = 0; i < temp; i++)
            {
                printf("%c",b[t]);
            }
        }
    }
    return 0;
    
}

char * customSortString(char * S, char * T)
{
    int sLen = strlen(S);
    int tLen = strlen(T);

    // 1. 建立数组，按S中字母顺序建立排序的依据
    for (int i = 0; i < sLen; i++) {
        gCharIndex[S[i] - 'a'] = i;
    }

    // 2. 对T进行排序
    qsort(T, tLen, sizeof(char), Cmp);
    return T;
}