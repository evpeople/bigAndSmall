#include<stdio.h>
int main()
{
	int num;
	scanf("%d",&num);
	char a,aa[5];
    short b,bb[5] = {0};
    int c,cc[5] = {0};
    long d,dd[5] = {0};
    long long e,ee[5] = {0};
    float f,ff[5] = {0};
    double g,gg[5] = {0};
    FILE *fp=fopen("dic.dict","rb");
    for(int i = 0;i<num;i++){
    	fread(&a,sizeof(char),1,fp); 
    	fread(&b,sizeof(short),1,fp); 
    	fread(&c,sizeof(int),1,fp); 
    	fread(&d,sizeof(long),1,fp); 
    	fread(&e,sizeof(long long),1,fp); 
    	fread(&f,sizeof(float),1,fp); 
    	fread(&g,sizeof(double),1,fp); 
    	fread(aa,sizeof(char),5,fp);
    	fread(bb,sizeof(short),5,fp);
    	fread(cc,sizeof(int),5,fp);
    	fread(dd,sizeof(long),5,fp);
    	fread(ee,sizeof(long long),5,fp);
    	fread(ff,sizeof(float),5,fp);
    	fread(gg,sizeof(double),5,fp);
	}
    fclose(fp);
    
    printf("%c\n",a);
    printf("%d\n",b);
    printf("%d\n",c);
    printf("%ld\n",d);
    printf("%lld\n",e);
    printf("%f\n",f);
    printf("%f\n",g);
    puts(aa); 
    for(int i = 0;i<4;i++)	printf("%d ",bb[i]);
    printf("%d\n",bb[4]);
    for(int i = 0;i<4;i++)	printf("%d ",cc[i]);
    printf("%d\n",cc[4]);
    for(int i = 0;i<4;i++)	printf("%ld ",dd[i]);
    printf("%ld\n",dd[4]);
    for(int i = 0;i<4;i++)	printf("%lld ",ee[i]);
    printf("%lld\n",ee[4]);
    for(int i = 0;i<4;i++)	printf("%f ",ff[i]);
    printf("%f\n",ff[4]);
    for(int i = 0;i<4;i++)	printf("%lf ",gg[i]);
    printf("%lf\n",gg[4]);
    return 0;
}