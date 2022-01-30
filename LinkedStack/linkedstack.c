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
		printf("[%c]\n", printNode->data);
		printNode = printNode->pLink;
		if (printNode != NULL)
			printf(" ⇂\n");
	}
	printf("[bottom]\n");
}
