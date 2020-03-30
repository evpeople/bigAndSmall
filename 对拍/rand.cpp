#include<bits/stdc++.h>
using namespace std;
#define random(a,b) ((a)+rand()%((b)-(a)+1))

stringstream ss;

int main( int argc, char *argv[] )
{ 
	int seed=time(NULL);
	if(argc)
	{
		ss.clear();
		ss<<argv[1];
		ss>>seed;
	}
	srand(seed);
	//以上为随机数初始化，请勿修改
	//random(a,b)生成[a,b]的随机整数
	
	//以下写你自己的数据生成代码 
	int len=random(1,10);
	for(int i=0;i<len;i++)
	{
		printf("%c",random(97,122));
	}
	printf("\n");
	//int n=random(102,116);
	
//	printf("%c%c%c%c%c%c%c\n",n+1,n-3,n+6,n,n-2,n-4,n-5);
	for(int i=0;i<1000;i++){
		int m=random(97,122);
		printf("%c",m);	
						}
						printf("\n");
	
/*	int c=random(1,100);
	char x='0'+m;
	switch(x)
{
		case '1':
			printf("1 201817123 Tom %d %d %d",c+m,c,c-m);
			break;
	case '2':
		printf("2 201817123");
			break;
	case '3':
			printf("3 201817123 %d %d %d",c+m,c-m,c);
			break;	
	case '4':
			printf("4 201817123");
			break;
		}
		printf("\n");
	}*/
	return 0;
}
