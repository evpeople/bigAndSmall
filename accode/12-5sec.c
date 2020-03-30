#include<stdio.h>


/*
    char a,aa[5];//注意这里数组aa为正常使用的字符串，所以会包含字符'\0'，它不需要输出
    short b,bb[5];
    int c,cc[5];
    long d,dd[5];
    long long e,ee[5];
    float g,gg[5];
    double h,hh[5];
    int i ;*/
int main()
{
    FILE* fptr;
    fptr=fopen("dic.dic","rb");
    char a,aa[5];//注意这里数组aa为正常使用的字符串，所以会包含字符'\0'，它不需要输出
    short b,bb[5];
    int c,cc[5];
    long d,dd[5];
    long long e,ee[5];
    float g,gg[5];
    double h,hh[5];
    int i;
    int temp=0;
    scanf("%d",&i);
    while (i>0)
    {
    fread(&a,sizeof(char),1,fptr);
    fread(&b,sizeof(short),1,fptr); 
    fread(&c,sizeof(int),1,fptr);
    fread(&d,sizeof(long),1,fptr);
    fread(&e,sizeof(long long),1,fptr);
    fread(&g,sizeof(float),1,fptr);
    fread(&h,sizeof(double),1,fptr);
    fread(aa,sizeof(char),5,fptr);
    fread(bb,sizeof(short),5,fptr);
    fread(cc,sizeof(int),5,fptr);
    fread(dd,sizeof(long),5,fptr);
    fread(ee,sizeof(long long),5,fptr);
    fread(gg,sizeof(float),5,fptr);
    fread(hh,sizeof(double),5,fptr);
    i--;
    }  
    printf("%c\n%d\n%d\n%ld\n%lld\n%f\n%lf\n",a,b,c,d,e,g,h);
    printf("%s\n",aa);
    while (temp<5)
    {
        printf("%d ",bb[temp]);
        temp++;
    }
    printf("\n");
    temp=0;
    while (temp<5)
    {
        printf("%d ",cc[temp]);
        temp++;
    }
    printf("\n");
    temp=0;
    while (temp<5)
    {
        printf("%ld ",dd[temp]);
        temp++;
    }
    printf("\n");
    temp=0;
    while (temp<5)
    {
        printf("%lld ",ee[temp]);
        temp++;
    }
    printf("\n");
    temp=0;
    while (temp<5)
    {
        printf("%f ",gg[temp]);
        temp++;
    }
    printf("\n");
    temp=0;
    while (temp<5)
    {
        printf("%lf ",hh[temp]);
        temp++;
    }
    printf("\n");
    temp=0;
    fclose(fptr);
   return 0;
}