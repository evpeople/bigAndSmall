#include <stdio.h>
#include <stdlib.h>

struct list{
	int data;
	struct list *nextPtr;
};

											//头指针，避免特判情况 

struct list *create(){
	int num;
	struct list *headPtr = NULL,*currentPtr = NULL,*lastPtr = NULL;
	scanf("%d",&num);
	while(num!=-1){
		currentPtr = (struct list*)malloc(sizeof(struct list));
		if(currentPtr!=NULL){
			currentPtr->data = num;
			if(headPtr==NULL){
				headPtr = currentPtr;
				lastPtr = currentPtr;
			}
			else{
				lastPtr->nextPtr = currentPtr;
				lastPtr = currentPtr;
			}
		}
		scanf("%d",&num);
	}
	if(headPtr!=NULL){
		lastPtr->nextPtr = NULL;
	}
	return headPtr;
}

void compound(struct list *list1current, struct list *list2current){
	struct list *list1front = NULL, *list2front = NULL;
	struct list *tempPtr1 = NULL, *tempPtr2 = NULL;
	list1front = list1current;
	list2front = list2current;
	if(list1current->nextPtr!=NULL&&list2current->nextPtr!=NULL){
		list1current = list1current->nextPtr;
		list2current = list2current->nextPtr;
	} 
	else if(list1current->nextPtr==NULL&&list2current->nextPtr!=NULL){
		list1current->nextPtr = list2current->nextPtr;
		list2current->nextPtr = NULL;
		return;
	}
	else{
		return;
	}
	
	
	//if(list1current->nextPtr ==NULL){
		//printf("There is no item in A list.\n");
	//	return;
	//}
	//else if(list2current->nextPtr ==NULL){
		//printf("There is no item in B list.\n");
	//	return;
	//}
	//else{
		while(list2current->nextPtr!=NULL){
			if(list1current->data<list2current->data){
				list1front = list1current;
				if(list1current->nextPtr!=NULL){
					list1current = list1current->nextPtr;			//第一个链表向后移移一位
				}
				else{
					//while(list1current->data<list2current->data&&list2current->nextPtr!=NULL){
					//	list2current = list2current->nextPtr;
					//}
					list1current->nextPtr = list2current;
					list2front->nextPtr = NULL;
					return;
				}
			}
			else if(list1current->data == list2current->data){
				if(list1current->nextPtr!=NULL){
					list2front = list2current;
					list2current = list2current->nextPtr;
					//list1front = list1current;
					//list1current = list1current->nextPtr;			//两个链表都平移 
				}
				else{
					list1current->nextPtr = list2current->nextPtr;
					list2current->nextPtr = NULL;
					return;
				}
			}
			else{
				if(list1current->nextPtr!=NULL){
					tempPtr1 = list1front->nextPtr;
					list1front->nextPtr = list2current;
					tempPtr2 = list2current->nextPtr;
					list2current->nextPtr = tempPtr1;
					list2front->nextPtr = tempPtr2;
					list1current = list2current;
					list2current = tempPtr2;					//更改指向顺序之后，第一个链表的current移动到刚加入的新链结上，第二个链表的current向后移动一位，即tempPtr2储存的位置 
				}
				else{
					while(list1current->data>list2current->data&&list2current->nextPtr!=NULL){
						list2current = list2current->nextPtr;
					}
				}	
			}
			
		}
	//}
	return;
}

void printList1(struct list *currentPtr)
{
    if (currentPtr==NULL)
    	   printf("There is no item in A list.\n");
    else
	{
	   	printf("The new list A:");
   	   	while(currentPtr->nextPtr!=NULL)
		{
   	        printf("%d ",currentPtr->data);
            currentPtr=currentPtr->nextPtr;
        } 
        printf("%d\n",currentPtr->data);  
    }
    return; 
}

void printList2(struct list *currentPtr)
{
    if (currentPtr==NULL)
    	   printf("There is no item in B list.");
    else
	{
	   	printf("The new list B:");
   	   	while(currentPtr->nextPtr!=NULL)
		{
   	        printf("%d ",currentPtr->data);
            currentPtr=currentPtr->nextPtr;
        } 
        printf("%d\n",currentPtr->data);  
    }
    return;
}

void compound3(int* a)
{
	//int *p=&a;
	int b=*a;
	b++;
	*a=b;
}
void compound2(struct list *list1current)
{

    list1current=list1current->nextPtr;
	
}
int main(){
	struct list *head1, *head2;	
	int x=4;
	int *p=&x;
	compound3(&x);	
	head1 = (struct list*)malloc(sizeof(struct list));
	head2 = (struct list*)malloc(sizeof(struct list));
	head1->nextPtr = create();
	head2->nextPtr = create();
	//printf("1");
	//compound(head1,head2);
	compound2(head1);
	//printf("2");
	printList1(head1->nextPtr);
	//printList2(head2->nextPtr);
	//printf("3");
	return 0;
}
