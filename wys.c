#include<stdio.h>							//回车是10，星号是42，斜杠是47

int main(){
	int a[5] = {0};
	int end = 0,start = 0,sum = 0;
	int num;
	char ch;
	//int flag = 0;
	
	scanf("%d",&num);
	//num = 5;
	
	FILE *file=fopen("dict.dic","r");
	for(int i = 0;i<5;i++){
		fscanf(file,"%d",&a[i]);
	}
	ch = fgetc(file);
	//for(int i = 0;i<num;i++){
	//	end = end+a[i];
	//}
	if(num==1){
		start = 0;
		end = a[num-1]-5;
	}
	else{
		start = a[num-2]-5;
		end = a[num-1]-5;
	}
	//printf("%d",end);
	ch = fgetc(file);
	if(sum<start){
		if(ch == 10){
			sum++;
		}
		ch = fgetc(file);
	}
	//if(num==5) end--;
	while(sum<end){
		if(ch == 47){
			ch = fgetc(file);
			if(ch == 42){
				//flag = 1;						//出现“/*”型注释 
				while(start!=-1){				//一个死循环 
					while(ch!=42){
						ch = fgetc(file);
						if(ch==10) sum++;
					}
					ch = fgetc(file);
					if(ch==10) sum++;
					if(ch == 47) break;			//找到“*/”跳出循环，没找到继续死循环找“*/”
					if(ch==-1) break;
					if(sum==end) break; 
				}
			}
			else if(ch == 47){					//找到“//”，不读回车前的所有字符 
				while(ch!=10){
					ch = fgetc(file);
				}
				sum++;
				printf("\n");
			}
			else printf("/%c",ch);			    //对于“/a”,直接输出/a,如果真的有人写这种代码的话 
			ch = fgetc(file);					//向后移位 
		}
		else {
			if(ch == 10) {
				sum++;
				//printf("\n%d\n",sum);
			}
			printf("%c",ch);
			ch = fgetc(file);
		}
		if(ch==-1) break;
	}
	fclose(file);
}