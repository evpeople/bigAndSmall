#include <stdio.h>
#include <stdlib.h>
typedef struct dlb
{
	char data;
	struct dlb *nextPtr;
} DJD;

DJD* create();
//CHAI lian biao 
void splitList(DJD **TEMP1sPtr,DJD **WordPtr,DJD **NumbersPtr,DJD **OthersPtr);
void printList(DJD **sPtr);
void destoryList(DJD **sPtr);
//刚开始还想着再从头节点里放个数，可拆来拆去没有个数了c
int lenList(DJD **sPtr);
//啊啊啊啊啊啊 下次一定用选择排序！！！！！！！
//第一次就该用选择排序来着啊啊啊啊啊！
void Compare(DJD **sPtr);

int main(void)
{
	DJD *TEMP1,*Word=NULL,*Number=NULL,*Others=NULL;;
	TEMP1=create();
	splitList(&TEMP1,&Word,&Number,&Others);
	Compare(&Word);
	Compare(&Number);
	Compare(&Others);
	if(Word!=NULL)
	{	printf("The list A is: ");
		printList(&Word); 	}
	else
		printf("There is no item in A list.\n");
	if(Number)
	{	printf("The list B is: ");
		printList(&Number); 	}
	else
		printf("There is no item in B list.\n");
	if(Others)
	{	printf("The list C is: ");
		printList(&Others); 	}
	else
		printf("There is no item in C list.\n");
	destoryList(&TEMP1);
	destoryList(&Word);
	destoryList(&Number);
	destoryList(&Others);
	return 0;
}

DJD* create()
{
	char s[1000],*p=s;
	gets(s);
	DJD *currentPtr,*TEMP1_headptr=NULL,*lastPtr=NULL;
    //int gs=0
	while(!((*p=='-')&&(*(p+1)=='1')))//用p 因为好加减
	{
		if(*p==' ') 
        {
        p++;continue;	
        }
		currentPtr=(DJD*)malloc(sizeof(DJD));
		currentPtr->data=*p;
		if(!TEMP1_headptr)
		{
            TEMP1_headptr=lastPtr=currentPtr;
        }

		else
		{
			lastPtr->nextPtr=currentPtr;
			lastPtr=currentPtr;
		}
		++p;
	}
	if(lastPtr) lastPtr->nextPtr=NULL;

	return TEMP1_headptr;
}

void splitList(DJD **TEMP1sPtr,DJD **WordPtr,DJD **NumbersPtr,DJD **OthersPtr)
{
	DJD *TEMP1=*TEMP1sPtr,*Word=*WordPtr,*Number=*NumbersPtr,*Others=*OthersPtr;
	char ch;
    int state;
    int a[3]={1,2,3};
	while(TEMP1)
	{
		ch=TEMP1->data;
		if('0'<=ch&&ch<='9') state=2;
		else if (('A'<=ch&&ch<='Z')||('a'<=ch&&ch<='z')) state=1;
		else state=3;
        if (state==1)
        {
            if(!Word)
					*WordPtr=TEMP1;
				else
					Word->nextPtr=TEMP1;
				Word=TEMP1;
				
        }
        else if (state==2)
        {
           	if(!Number)//头结点的处理
					*NumbersPtr=TEMP1;
				else
					Number->nextPtr=TEMP1;
				Number=TEMP1;
        }
        else if (state==3)
        {
         	if(!Others)
					{
                        *OthersPtr=TEMP1;
                    }
				else
					{
                        Others->nextPtr=TEMP1;
                    }
				Others=TEMP1;
        }
        
		
		TEMP1=TEMP1->nextPtr;
	}
	if(Number) Number->nextPtr=NULL;
	if(Word) Word->nextPtr=NULL;
	if(Others) Others->nextPtr=NULL;
	*TEMP1sPtr=NULL;
}

void printList(DJD** sPtr)
{
    DJD* temp=*sPtr;
	DJD* currentPtr;
	currentPtr=temp;
	while(currentPtr->nextPtr!=NULL)
	{
		printf("%c ",currentPtr->data);
		currentPtr=currentPtr->nextPtr;
	}
	printf("%c\n",currentPtr->data);
}




void destoryList(DJD **sPtr)
{
	DJD *headPtr=*sPtr,*tmpPtr;
	while(headPtr)
	{
		tmpPtr=headPtr;
		headPtr=headPtr->nextPtr;
		free(tmpPtr);
	}
	*sPtr=NULL;
}

int lenList(DJD **sPtr)
{
	DJD *headPtr=*sPtr;
	int cnt=0;
	while(headPtr)
	{
		cnt++;
		headPtr=headPtr->nextPtr;
	}	
	return cnt;
}

void Compare(DJD **sPtr)
{
	int n=lenList(sPtr),i,j,isChanged;
	if(n==0||n==1) return ;
	DJD *aPtr,*bPtr,*prevPtr;
	for(i=1;i<n;++i)
	{
		prevPtr=NULL;
		aPtr=(*sPtr);
		bPtr=(*sPtr)->nextPtr;
		isChanged=0;
		for(j=0;j<n-i;++j)
		{
			if(!prevPtr)
			{
				if((aPtr->data)>(bPtr->data))
				{
					*sPtr=bPtr;
					aPtr->nextPtr=bPtr->nextPtr;
					bPtr->nextPtr=aPtr;
					isChanged=1;
				}
				if(isChanged)
				{
					bPtr=aPtr->nextPtr;
					isChanged=0;
				}
				else
				{
					bPtr=bPtr->nextPtr;
					aPtr=aPtr->nextPtr;
				}
				prevPtr=*sPtr;
			}
			else
			{
				if((aPtr->data)>(bPtr->data))
				{
					isChanged=1;
					aPtr->nextPtr=bPtr->nextPtr;
					prevPtr->nextPtr=bPtr;
					bPtr->nextPtr=aPtr;
				}
				if(isChanged)
				{
					isChanged=0;
					prevPtr=prevPtr->nextPtr;
					bPtr=aPtr->nextPtr;
					aPtr=prevPtr->nextPtr;
				}
				else
				{
					bPtr=bPtr->nextPtr;
					aPtr=aPtr->nextPtr;
					prevPtr=prevPtr->nextPtr;
				}
			}
		}
	}
}
