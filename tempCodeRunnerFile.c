#include<stdio.h>

int main()
{

    char a;
    int n;
    int i=0;
    int sum=0;
    scanf("%d",&n);
    while (n>0)
    {
        getchar();

        scanf("%c",&a);
        //printf("%s",a);
        while (a!='\n')
        {

            sum+=(a-'0');
            scanf("%c",&a);
        }
        i=0;
        n--;
        printf("%d\n",sum%9);
    }
}