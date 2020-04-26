//天灵灵，地灵灵，一定过一定过
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char right[29];
int index[60] = {0}; 
    char left[10000000];
int myhanshu(const void *a ,const void *b);
int main()
{
    gets(left);
    gets(right);
    int lenOfright = strlen(right);
    for (size_t i = 0; i < lenOfright; i+=2)
    {
        index[right[i]-'a']=i;//right 中的第i项离a的距离比如  第20项为d，则index[3]=20,  就是说index储存了abcd的新的序列
    }
    
    qsort(left,strlen(left),sizeof(char),myhanshu);
    puts(left);
    return 0;
}
int myhanshu(const void* a, const void* b)
{
    return index[*(char*)a - 'a'] - index[*(char*)b - 'a'];// 比如 a为z， b为d，  则index【25】-index【3】，返回的为在实际序列里的差。模仿ascil的那种
}