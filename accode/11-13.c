#include<stdio.h>
#include<stdlib.h>
typedef struct  DLB
{
    int number;
    struct DLB * nextPtr;

}DLB;

DLB* creat();
void destroyDLB(DLB* head);
void  printfDLB(DLB* head);
void swap(DLB* head1);
int main(void)
{ 
    DLB* head1;
    
    head1=creat();
    
    swap(head1);
   printfDLB(head1); 
   destroyDLB(head1);

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
void swap(DLB* head1)
{
    int s1,t1,s2,t2;
    int i=0;
    int magic=0;
    //magic 用于判断是否相邻
    scanf("%d%d%d%d",&s1,&t1,&s2,&t2);
    s1--;
    s2--;
    //s减一因为下一项才是要移动的块的起始项，t不用动。
    //先在这四个位置分配四个指针
    DLB* sp1, *tp1,*sp2,*tp2,*temp,*temp1;
    temp=head1;
    //此方法过不了1 1 2 2
    // while (temp!=NULL)
    // {
    //     if (i<s1)
    //     {
    //         temp=temp->nextPtr;
    //         i++;
    //         continue;
    //     }
    //     if (i=s1)
    //     {
    //        sp1=temp; 
    //     }
    //     if (i>s1&&i<t1)
    //     {
    //         temp=temp->nextPtr;
    //         i++;
    //         continue;
    //     }
    //     if (i=t1)
    //     {
    //        tp1=temp; 
    //     }
    //     if (i>t1&&i<s2)
    //     {
    //         temp=temp->nextPtr;
    //         i++;
    //         continue;
    //     }
    //     if (i=s2)
    //     {
    //        sp2=temp; 
    //     }
    //     if (i>s2&&i<t2)
    //     {
    //         temp=temp->nextPtr;
    //         i++;
    //         continue;
    //     }
    //     if (i=t2)
    //     {
    //        tp2=temp; 
    //     }
    //     temp=temp->nextPtr;
    //     i++;
    // }
     while (i<=s1)
    {
        if (i<s1)
        {
            temp=temp->nextPtr;
            i++;
        }
        if (i==s1)
        {
           sp1=temp;
           break; 
        }
    }
    //i=0;
    while (i<=t1)
    {
        if (i<t1)
        {
            temp=temp->nextPtr;
            i++;
        }
        if (i==t1)
        {
           tp1=temp; 
           break;
        }
    }
    //i=0;
    while (i<=s2)
    {
        if (i<s2)
        {
            temp=temp->nextPtr;
            i++;
            magic++;
            //加入相邻 magic则不变化
        }
        if (i==s2)
        {
           sp2=temp;
           break;
        }
    }
    //i=0;
         while (i<=t2)
    {
        if (i<t2)
        {
            temp=temp->nextPtr;
            i++;
        }
        if (i==t2)
        {
           tp2=temp;
           break;
        }
    }
//分配好指针了
// 相邻是特殊情况

if (magic!=0)
{
    temp=sp1->nextPtr;
    temp1=tp2->nextPtr;
    sp1->nextPtr=sp2->nextPtr;
    tp2->nextPtr=tp1->nextPtr;
    sp2->nextPtr=temp;
    tp1->nextPtr=temp1;
}
else
{
    temp=sp1->nextPtr;
    sp1->nextPtr=sp2->nextPtr;
    tp1->nextPtr=tp2->nextPtr;
    tp2->nextPtr=temp;
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