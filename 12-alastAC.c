#include<stdio.h>
#include<string.h>
#define mixer "!@#$%%^&*"
int putsAndChange(char line[120], const char str[10][12], int start,int max);
int main() {
	FILE* file = fopen("dict.dic", "r");
	char ptr[10][12];
	char line[120] ;
	int max = 0;
    int i=0;
    memset(ptr,0,10*12*sizeof(char));
    memset(line,0,120*sizeof(char));
    while (!feof(file)) //读入文件内的敏感字符到ptr中
    {
        fgets(ptr[i], 12, file);

            ptr[i][strlen(ptr[i]) - 1] = '\0';
        
        i++;
    }
    max=i;
    /*for (int i = 0;; i++) {
		if (!feof(file)) {
			fgets(ptr[i], 12, file);
				max = i;
				ptr[i][strlen(ptr[i])-1] = '\0';
		}else break;
	}*/
   
	while (!feof(stdin)){
		
		if(fgets(line, 120, stdin)!=NULL)
        {
		 	for (int i = 0; i < (int)strlen(line); i++)
            {
		        i+=putsAndChange(line, ptr, i, max);	
	        }
        }

	}
	return 0;
}
int putsAndChange(char line[120], const char str[10][12], int start,int max)
{
	int pos = -1;
	pos++;
	for (int k = 0; k < max; k++) 
    {
        if (line[start] != str[k][0])
        {
           continue;
        }
        else
        {
		    if (strncmp(&line[start], str[k], strlen(str[k])) == 0) 
                {
				    pos = strlen(str[k]);
				    printf(mixer); 
                    break;
			    }  
        }	          
	}                                 
	if (pos == 0)printf("%c", line[start]);
	else pos--;//是因为for循环中i还会接着++
	return pos;
}