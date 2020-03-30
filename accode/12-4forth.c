#include <stdio.h>

int note1(FILE *p);
int note2(FILE *p,int line,int high);
int main()
{
	FILE *p=fopen("dict.dic","r");
	int line=1,low=6,high,i;	
	char ch;
	fscanf (p,"%d",&high);
	
	i=4;
	line++;
	for (;line<=5;line++)
	{
		if (line<=i)
		{
			low=high+1;
			fscanf (p,"%d",&high);
		}else	fscanf (p,"%*d");
	}
	fseek(p,2,1);	
	while(line!=low)
	{
		ch=fgetc(p);
		if (ch=='\n')	line++;
	}
	line=low; 
	while(line!=high+1)
	{
		ch=fgetc(p);
		if (ch=='/')
		{
			ch=fgetc(p);
			if (ch=='/')
			{
				note1(p);	
				printf ("\n");
				line++;
			}else
			{
				if (ch=='*')
				{
					line=note2(p,line,high);	
				}else	printf ("/%c",ch);
			}
		}else	printf ("%c",ch);
		if (ch=='\n')	line++;
		if (feof(p)!=0)	break;	
	}
	fclose(p);
	return 0;
 } 
 
 int note1(FILE *p)
 {
 	char ch=fgetc(p);
 	while (ch!='\n')
 	{
 		if (feof(p)!=0)	break;	
 		ch=fgetc(p);	
	 }
	 return 0;
 }
 
 int note2(FILE *p,int line,int high)
 {
 	char ch=fgetc(p),temp=fgetc(p);
 	while(line!=high+1)
 	{
 		if (ch=='\n')	line++;
 		if (ch=='*'&&temp=='/')	break;
 		ch=temp;
 		temp=fgetc(p);
	 }
	 return line;
 }