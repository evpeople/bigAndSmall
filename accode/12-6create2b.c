#include<stdio.h>
int main()
{
    FILE* ftp;
    ftp=fopen("csdatas","r");
    while (!feof(ftp))
    {
        fgetc(ftp);
        ftell(ftp);

    }
    
}