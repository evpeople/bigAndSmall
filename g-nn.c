#include<stdlib.h>
#include<stdio.h>
#include<string.h>




int cmp(const void *p1, const void *p2)
{
    return *(char *)p1 - *(char *)p2;
}

char * customSortString(char * S, char * T){
    int len = strlen(S);
    char *sRight = (char *)malloc(len);
    memcpy(sRight, S, len);
    qsort(sRight, len, sizeof(char), cmp);
    int hash1[27] = {0}; // 存储自定义序列的字符下标 (1.2.3...)，用于正映射
    for (int i = 0; i < len; i++) {
        hash1[S[i]] = i + 1;
    }
    int hash2[256] = {0}; // 存储自定义序列排序后的字符下标 (1.2.3...)，用于反映射
    for (int i = 0; i < len; i++) {
        hash2[sRight[i]] = i + 1;
    }

    len = strlen(T);
    // 正映射
    for (int i = 0; i < len; i++) {
        if (hash1[T[i]]) {
            T[i] = sRight[hash1[T[i]] - 1];
        }
    }

    /* 正常序列排序 */
    qsort(T, len, sizeof(char), cmp);

    /* 反映射 */
    for (int i = 0; i < len; i++) {
        if (hash1[T[i]]) {
            T[i] = S[hash2[T[i]] - 1];
        }
    }

    free(sRight);
    return T;
}
int main()
{
    char a[100000];
    int word[29]={0};
    //char x[100000];
    char b[60];
    char c[100000];
    gets(a);
    gets(b);
    strcpy(c,customSortString(b,a));
    puts(c);
    return 0;
}