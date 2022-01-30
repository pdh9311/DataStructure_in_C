#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount)
{
	ArrayStack* stack;
	
	if (maxElementCount <= 0)
		return (NULL);
	stack = (ArrayStack*)malloc(sizeof(ArrayStack));
	if (stack == NULL)
		return (NULL);
	stack->maxElementCount = maxElementCount;
	stack->currentElementCount = 0;
	stack->pElement = (ArrayStackNode*)malloc(sizeof(ArrayStackNode) * maxElementCount);
	if (stack->pElement == NULL)
	{
		free(stack);
		stack = NULL;
		return (NULL);
	}
	return (stack);
}

int pushAS(ArrayStack* pStack, ArrayStackNode element)
{
	int current; 
	int max;

	if (pStack == NULL || pStack->pElement == NULL)
	{
		printf("(NULL)\n");
		return (FALSE);
	}
	current = pStack->currentElementCount;
	max = pStack->maxElementCount;
	if (isArrayStackFull(pStack))
	{
		printf("overflow\n");	
		return (FALSE);
	}
	pStack->pElement[current].data = element.data;
	pStack->currentElementCount++;
	return (TRUE);
}

ArrayStackNode* popAS(ArrayStack* pStack)
{
	int	pop;

	if (pStack == NULL || pStack->pElement == NULL)
	{
		printf("(NULL)\n");
		return (NULL);
	}
	if (isArrayStackEmpty(pStack))
	{
		printf("underflow\n");
		return (NULL);
	}
	pop = pStack->currentElementCount - 1;
	pStack->currentElementCount--;
	return (&pStack->pElement[pop]);
}

ArrayStackNode* peekAS(ArrayStack* pStack) //top을 보는 것!
{
	int	top;

	if (pStack == NULL || pStack->pElement == NULL)
	{
		printf("(NULL)\n");
		return (NULL);
	}
	if (pStack->currentElementCount == 0)
	{
		printf("empty\n");
		return (NULL);
	}
	top = pStack->currentElementCount - 1;
	return (&pStack->pElement[top]);
}

void deleteArrayStack(ArrayStack* pStack)
{
	if (pStack == NULL || pStack->pElement == NULL)
	{
		printf("(NULL)\n");
		return ;
	}
	free(pStack->pElement);
	pStack->pElement = NULL;
	free(pStack);
	pStack = NULL;
}

int isArrayStackFull(ArrayStack* pStack)
{
	if (pStack == NULL || pStack->pElement == NULL)
	{
		printf("(NULL)\n");
		return (FALSE);
	}
	if (pStack->currentElementCount == pStack->maxElementCount)
		return (TRUE);
	return (FALSE);
}
int isArrayStackEmpty(ArrayStack* pStack)
{
	if (pStack == NULL || pStack->pElement == NULL)
	{
		printf("(NULL)\n");
		return (FALSE);
	}
	if (pStack->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

void displayArrayStack(ArrayStack* pStack)
{
	int	i;
	
	if (pStack == NULL || pStack->pElement == NULL)
	{
		printf("(NULL)\n");
		return ;
	}
	printf("Max : %d\n", pStack->maxElementCount);
	for (i = pStack->currentElementCount - 1; i >= 0; i--)
	{
		printf("|%c|\n", pStack->pElement[i].data);
		fflush(stdout);

	}
	printf(" ⎺\n");
}
