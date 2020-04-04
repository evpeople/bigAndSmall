#include<stdio.h>
#include<string.h>
#define mixer "!@#$%%^&*"
int tojump(char line[120], const char str[10][12], int start,int max) {
	int ans = 0;
	
	for (int k = 0; k < max; k++) {
		if (line[start] == str[k][0])
			if (strncmp(&line[start], str[k], strlen(str[k])) == 0) {
				ans = strlen(str[k]);
				printf(mixer); break;
			}            
	}                                 
	if (ans == 0)printf("%c", line[start]);
	else ans--;
	return ans;
}


int toput(char line[120], const char str[10][12], int max) {
	for (int i = 0; i < (int)strlen(line); i++) {
		i+=tojump(line, str, i, max);	
	}
	return 0;
}


int main() {
	FILE* file = fopen("dict.dic", "r");
	char str[10][12] = { 0 };
	char line[120] = { 0 };
	int max = 0;
	for (int i = 0;; i++) {
		if (!feof(file)) {
			fgets(str[i], 12, file);
				max = i;
				str[i][strlen(str[i])-1] = '\0';
		}else break;
	}
   
	for (; 		!feof(stdin);	) {
		
		if(fgets(line, 120, stdin)!=NULL)		toput(line, str, max);

	}
	return 0;
}

