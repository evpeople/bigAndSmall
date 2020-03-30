#include<stdio.h>
#include<stdlib.h>
typedef struct  DLB
{
    int number;
    struct DLB * nextPtr;

}DLB;
DLB* creat();
void destroyDLB(DLB* head);
int comapareDLb(DLB*head1,DLB*head2);
int main(void)
{ 
    DLB* head1,*head2;
    int i=10;
    head1=creat();
    head2=creat();
    i=comapareDLb(head1,head2);
    if (i==1)
    {
        printf("ListB is the sub sequence of ListA.");
    }
    else
    {
        printf("ListB is not the sub sequence of ListA.");
    }
    
   destroyDLB(head1);
   destroyDLB(head2);
   getchar();
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
//head1 is A head2 is  B
//1 2 3 4 2 3 4 5 6 7 8 9      2 3 4 2 3 4
//1 2 3 4 5 1 2 3 1 2 3 4      1 2 3 1 2 3 4 
//2 3 4 5 1 2 3 1 2 3 4      1 2 3 1 2 3 4 
int comapareDLb(DLB*head1,DLB*head2)
{
    DLB* pre1 ,*pre2,*work;
    int i=1;
    pre1=head1->nextPtr;
    pre2=head2->nextPtr;
    work=pre1;
    while (pre1&&pre2)
    {
        if (pre1->number!=pre2->number)
        {
            
            work=work->nextPtr;
            pre1=work;
            pre2=head2->nextPtr;
        }
        else 
        {
            pre1=pre1->nextPtr;
            pre2=pre2->nextPtr;
        }
    }
    //单一出口
    if (pre2==NULL)
    {
        i=1;
    }
    else
    {
        i=0;
    }
    
    return i;
}
   //有误的思路
//     while ((pb-temp)!=pb2)//大链表剩余节数小于小链表
//     {
//        //pre1=head1->nextPtr;
//         if (pre1->number!=p->number)
//         {
//             //将大表的指针后移
//             pre1=pre1->nextPtr;
//         }
//         else
//         {
//             //两表的指针均后移
//             pre1=pre1->nextPtr;
//             p=p->nextPtr;
//         }

//         if ((p->nextPtr)==NULL)
//         {
//             i=1;
//             break;
//         }
        
//         if ((pre1->nextPtr)==NULL)
//         {
//             temp++;
//             pre1=tem;
//             tem=tem->nextPtr;
//             p=head2->nextPtr;
//         }
        
//         // if (pre1->nextPtr==NULL&&p->nextPtr==NULL)
//         // {
//         //     i=1;
//         // }
        
        
//     }
//     return i;
// }


