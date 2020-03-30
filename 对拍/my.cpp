#include <stdio.h>
#include <string.h>

int main(void){
	char word[20];
	char article[1000010];
	int count = 0;
	gets(word);
	gets(article);
	
	int i = 0,j = 0;
	int flag = 0;
	int loc = 0;
	
	while(article[j]!='\0'){
		if(word[i]==article[j]&&(j==0||article[j-1]==' ')){			//??????letter
			flag = 1;
			for(int a = 0;a<strlen(word)-1;a++){
				i++;
				j++;
				if(word[i]!=article[j]){
					flag = 0;
					break;
				}
			}
			if(flag == 1&&(article[j+1]==' '||article[j+1]=='\n')){		//??article????????? 
				count++;
				i = 0;
			}
		}
		j++;
	}
	printf("%d %d",count,loc);
}


