#include<stdio.h>

int main()
{

    char a;
    int n;
    int i=0;
    int sum=0;
    scanf("%d",&n);
     getchar();
    while (n>0)
    {
       

        scanf("%c",&a);
        //printf("%s",a);
        while (1)
        {

            sum+=(a-'0');
            scanf("%c",&a);
            if (a=='\n')
            {
                break;
            }
            
        }
        i=0;
        n--;
        printf("%d\n",sum%9);
        sum=0;
    }
}
      if (temp>=2)
            {
              break;
            }
            
            for (size_t i = 0; i < temp; i++)
            {
                printf("%c",b[t]);
            }