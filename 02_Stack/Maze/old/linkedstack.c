#include "linkedstack.h"

LinkedStack* createLinkedStack()
{
    LinkedStack *stack;

    stack = (LinkedStack *)malloc(sizeof(LinkedStack));
    if (stack == NULL)
    {
        printf("(NULL)\n");
        return (NULL);
    }
    stack->currentElementCount = 0;
    stack->pTopElement = NULL;
    return (stack);
}

int pushLS(LinkedStack* pStack, StackNode element)
{
    StackNode* addNode;
    StackNode* top;

    if (pStack == NULL)
    {
        printf("(NULL)\n");
        return (FALSE);
    }
    addNode = (StackNode*)malloc(sizeof(StackNode));
    if (addNode == NULL)
        return (FALSE);
    *addNode = element;
    addNode->pLink = NULL;
    top = pStack->pTopElement;
    addNode->pLink = top;
    pStack->pTopElement = addNode;
    pStack->currentElementCount++;
    return (TRUE);
}

StackNode* popLS(LinkedStack* pStack)
{
    StackNode* pop;
    StackNode* top;

    if (pStack == NULL || pStack->pTopElement == NULL || pStack->currentElementCount == 0)
    {
        printf("(NULL)\n");
        return (NULL);
    }

    pop = pStack->pTopElement;
    top = pop->pLink;
    pStack->pTopElement = top;  
    pStack->currentElementCount--;
    return (pop);
}

// pStack == NULL pStack->pTopElement == NULL
//의 구분을 잘하자!

StackNode* peekLS(LinkedStack* pStack)
{
    if (pStack == NULL || pStack->pTopElement == NULL || pStack->currentElementCount == 0)
    {
        printf("(NULL)\n");
        return (NULL);
    }
    return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack* pStack)
{
    StackNode *delNode;
    StackNode *nextNode;

    if (pStack == NULL)
    {
        printf("(NULL)\n");
        return ;
    }
    else if (pStack->pTopElement == NULL)
    {
        printf("(NULL)\n");
        free(pStack);
        return ;
    }
    delNode = pStack->pTopElement;
    while (delNode)
    {
        nextNode = delNode->pLink;
        free(delNode);
        delNode = nextNode;
    }
    pStack->currentElementCount = 0;
    pStack->pTopElement = NULL;
    free(pStack);
    // pStack = NULL; 이거는 의미가 없다
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
    if (pStack == NULL)
        return (FALSE);
    if (pStack->pTopElement == NULL)
        return (TRUE);
    return (FALSE);
}

void displayLinkedStack(LinkedStack* pStack)
{
    StackNode *printNode;

    if (pStack == NULL)
    {
        printf("pStack is (NULL)\n");
        return ;
    }
    printNode = pStack->pTopElement;
    printf("=== current : [%d] ===\n", pStack->currentElementCount);
    printf("[head]\n");
    printf(" ⇂\n");
    while (printNode)
    {
        printf("[%d, %d]\n", printNode->data.x, printNode->data.y);
        printNode = printNode->pLink;
        if (printNode != NULL)
            printf(" ⇂\n");
    }
    printf("[bottom]\n");
}

//del -> pop
///del -> 출력이 되는거
//del -> del

// int main(void)
// {
//     LinkedStack* stack = NULL;
//     StackNode temp = {0, 0};
//     StackNode* getNode;
//     int input;
    
//     while(1)
//     {
//         printf("\n1.create | 2.push | 3.pop | 4.peek | 5.delete | 6.display | 0.exit\n");
//         printf("input num : ");
//         scanf("%d", &input); fflush(stdin);
//         switch(input)
//         {
//             case 1:
//                 if (stack != NULL)
//                 {
//                     printf("alredy create\n");
//                     break;
//                 }
//                 stack = createLinkedStack();
//                 if (!stack)
//                 {
//                     printf("fail\n");
//                     return (1);
//                 }
//                 break ;
//             case 2:
//                 printf("input char > ");
//                 scanf("%c", &temp.data); fflush(stdin);
//                 pushLS(stack, temp);
//                 displayLinkedStack(stack);
//                 break ;
//             case 3:
//                 getNode = popLS(stack);
//                 if (getNode != NULL)
//                 {
//                     printf("pop data: %c\n", getNode->data);
//                     free(getNode);
//                 }
//                 displayLinkedStack(stack);
//                 break ;
//             case 4:
//                 getNode = peekLS(stack);
//                 if (getNode != NULL)
//                     printf("peek data: %c\n", getNode->data);
//                 displayLinkedStack(stack);
//                 break ;
//             case 5:
//                 deleteLinkedStack(stack);
//                 stack = NULL;
//                 displayLinkedStack(stack);
//                 break ;
//             case 6:
//                 displayLinkedStack(stack);
//                 break ;
//             case 0: 
//                 deleteLinkedStack(stack);
//                 exit(0);
//                 break ;
//         }
//     }
//     return (0);
// }