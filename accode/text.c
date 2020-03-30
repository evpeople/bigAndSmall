#include<stdio.h>
#include<stdlib.h>
typedef struct  DLB
{
    int number;
    struct DLB * nextPtr;

}DLB;

 DLB* creat();
 DLB* compare(DLB* head);

 void destroyDLB(DLB* head);
 void  printfDLB(DLB* head);
int main(void)
{ 
    DLB* head,*ans;


  head=creat();

    ans=compare(head);

    printfDLB(ans);
   destroyDLB(ans);
    return 0;
}


DLB* creat()
{
    int num;
    DLB * head=NULL,*current=NULL,*last=NULL,*sum;
    scanf("%d",&num);
    int i=0;
    while(num!=-1)
    {
        i++;
        current=(DLB*)malloc(sizeof(DLB));
        current->number=num;
        if (head==NULL)
        {
            //head=(DLB*)malloc(sizeof(DLB));
            //head->number=num;
            head=current;
            last=current;
        }

        else
        {
            last->nextPtr=current;
            last=current;
        }
         scanf("%d",&num);
    }
    sum=(DLB*)malloc(sizeof(DLB));
    //空节点指向头节点
    sum->nextPtr=head;
    //在头节点处存和
    sum->number=i;
    last->nextPtr=NULL;
    return sum;
}



DLB* compare(DLB *head)
{							//排序中没有修改头节点指针值，只是修改指针内容head->next的值
	DLB *pre,*p,*tail,*temp;
	tail=NULL;
	pre=head;

	while((head->nextPtr->nextPtr)!=tail)
	{
		p=head->nextPtr;
		pre=head;
		while(p->nextPtr!=tail)
		{
			if((p->number)>(p->nextPtr->number))
			{

                pre->nextPtr=p->nextPtr; //交换节点方法二
                temp=p->nextPtr->nextPtr;
                p->nextPtr->nextPtr=p;
                p->nextPtr=temp;
                p=pre->nextPtr;  //p回退一个节点

			}
			p=p->nextPtr;  //p再前进一个节点
			pre=pre->nextPtr;
		}
		tail=p;
	}
	return head ;
}


//DLB* compare(DLB* sum)
//{
//
//    int length=sum->number;
//    DLB* temp=sum->nextPtr;
//    DLB* temp2=sum;
//    for (int i=0;i<length-1 ; i++)
//    {
//
//            for (int j=0;j<length-1-i ; j++)
//            {
//                    if(sum->nextPtr->number > sum->nextPtr->nextPtr->number)
//                    {
//                        sum->nextPtr=sum->nextPtr->nextPtr;
//                        temp->nextPtr=sum->nextPtr->nextPtr;
//                        sum->nextPtr=temp;
//                    }
//
//            }
//    }
//    printf("#############%d\n",temp2->number);
//    return temp2;
//}
void destroyDLB(DLB* headPtr)
{
    DLB* tempPtr;
    while (headPtr!=NULL)
	{

        tempPtr=headPtr;
        headPtr=headPtr->nextPtr;/*headPtr指向下一个要删除的结点*/
        free(tempPtr);
    }
}
 void  printfDLB(DLB* head)
 {
     DLB* temp=head->nextPtr;
     int length=head->number;
    printf("The new list is:");
    for (int i=0;i<length ; i++)
    {
        if(i==length)
        {
            printf("%d\n",temp->number);
        }
        printf("%d ",temp->number);
        temp=temp->nextPtr;
    }
 }
