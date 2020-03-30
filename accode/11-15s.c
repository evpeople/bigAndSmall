DJD* create_listnode1(void)
{
	DJD* headPtr,*currentPtr=NULL,*lastPtr=NULL;
	char s[3]={0}; 
	//创建哨兵节点 
	headPtr=(DJD*)malloc(sizeof(LISTNODE));
	headPtr->nextPtr=NULL;
	//创建原链表
	currentPtr=headPtr;
	lastPtr=headPtr;
	scanf("%s",s);
	while(*s!='-'&&*(s+1)!='1')
	{
		currentPtr=(DJD*)malloc(sizeof(LISTNODE));
		currentPtr->data=s[0];
		lastPtr->nextPtr=currentPtr;
		lastPtr=currentPtr;
		lastPtr->nextPtr=NULL;
		scanf("%s",s);
	}
	return headPtr;
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


void printList(DJD** sPtr)
{
    DJD* temp=*sPtr;
	DJD* currentPtr;
	currentPtr=temp->nextPtr;//从第二个节点开始输出，即不输出哨兵节点 
	while(currentPtr->nextPtr!=NULL)
	{//一直输出，尾节点未被输出 
		printf("%c ",currentPtr->data);
		currentPtr=currentPtr->nextPtr;
	}
	printf("%c\n",currentPtr->data);//输出尾节点 
}

void printList(DJD **sPtr)
{
	DJD *headPtr=*sPtr;
	while(headPtr)
	{
		printf("%c ",headPtr->data);
		
        
        headPtr=headPtr->nextPtr;
	}
}