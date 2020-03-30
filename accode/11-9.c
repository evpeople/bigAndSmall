#include <stdio.h>
#include <stdlib.h>
typedef struct LINK
{
    int data;
    struct LINK *nextPtr;
    struct LINK *beforPtr;
} LINK;
typedef LINK *LINKPTR;

LINKPTR creatLink();
void destoryLink(LINKPTR a);
void printLink(LINKPTR a);
void compare(LINKPTR a, LINKPTR b);

int main(void)
{
    LINKPTR a, b;
    a = creatLink();
    b = creatLink();
    compare(a, b);
    if (a->nextPtr == NULL && b->nextPtr == NULL)
    {
        printf("There is no item in A list.\nThere is no item in B list.");
    }
    else if (a->nextPtr != NULL && b->nextPtr == NULL)
    {
        printf("The new list A:");
        printLink(a);
        printf("There is no item in B list.");
    }

    else
    {
        printf("The new list A:");
        printLink(a);
        printf("The new list B:");
        printLink(b);
    }

    destoryLink(a);
    destoryLink(b);
    return 0;
}
LINKPTR creatLink()
{
    LINKPTR current = NULL, last = NULL, head = NULL, beforHead = NULL, lasthead = NULL;
    int num;
    int i = 0;
    scanf("%d", &num);
    while (num != -1)
    {
        i++;
        current = (LINKPTR)malloc(sizeof(LINK));
        current->data = num;
        if (head == NULL)
        {

            head = current;
            last = current;
        }
        else
        {

            current->beforPtr = last;
            last->nextPtr = current;
            last = current;
        }
        scanf("%d", &num);
    }
    beforHead = (LINKPTR)malloc(sizeof(LINK));
    lasthead = (LINKPTR)malloc(sizeof(LINK));
    beforHead->data = 10000000;
    beforHead->nextPtr = head;
    head->beforPtr = beforHead;
    last->nextPtr = lasthead;
    lasthead->beforPtr = last;
    lasthead->nextPtr = NULL;
    return beforHead;
}
void destoryLink(LINKPTR a)
{
    LINKPTR temp;

    while (a != NULL)
    {
        temp = a;
        a = a->nextPtr;
        free(temp);
    }
}
void printLink(LINKPTR a)
{
    LINKPTR temp;
    a = a->nextPtr;
    while (a != NULL)
    {
        if (a->nextPtr != NULL)
        {
            printf("%d ", a->data);
        }
        else
        {
            printf("%d\n", a->data);
        }
        a = a->nextPtr;
    }
}
void compare(LINKPTR a, LINKPTR b)
{
    LINKPTR temp, tempA, tempB, tempS;
    tempS = b->nextPtr->nextPtr;
    tempB = b;
    tempA = a;
    temp = a->nextPtr;
    //tempDelete=NULL;

    while (tempS->beforPtr->beforPtr != NULL)
    {

        tempB = tempS->beforPtr;
        if (
            (temp->data < tempB->data && tempB->data < (temp->nextPtr->data)) || (temp->data < tempB->data && temp->nextPtr == NULL))
        {
            tempB->beforPtr = temp;
            tempB->nextPtr = temp->nextPtr;
            temp->nextPtr = tempB;
            temp->nextPtr->beforPtr = tempB;
            tempS->beforPtr = b;
            b->nextPtr = tempS;
            temp = temp->nextPtr;
            // tempA=temp->nextPtr;
            // tempS=tempB;
            // tempB=tempB->nextPtr;
            // //tempGD=tempB;
            // temp->nextPtr=tempS;
            // tempS->nextPtr=tempA;
            // //tempB=tempB->beforPtr;
            // //上面是插入
            // //下面是删除
            // tempDelete=tempB->beforPtr;
            // tempDelete->nextPtr=tempB->nextPtr;
        }
        tempS = tempS->nextPtr;
    }
}