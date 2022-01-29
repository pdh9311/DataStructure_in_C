#include "arraystack.h"

ArrayStack*		createArrayStack(int maxElementCount)
{
	ArrayStack*	stack;
	
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

int	pushAS(ArrayStack* pStack, ArrayStackNode element)
{
	if (pStack == NULL || pStack->currentElementCount == pStack->maxElementCount)	// overflow
		return (FALSE);
	pStack->pElement[pStack->currentElementCount] = element;
	pStack->currentElementCount++;
	return (TRUE);	
}

ArrayStackNode*	popAS(ArrayStack* pStack)
{
	if (pStack == NULL || pStack->currentElementCount == 0)	// underflow
		return (NULL);
	pStack->currentElementCount--;
	return (&pStack->pElement[pStack->currentElementCount]);
}

ArrayStackNode*	peekAS(ArrayStack* pStack)
{
	if (pStack == NULL || pStack->currentElementCount == 0)
		return (NULL);
	return (&pStack->pElement[pStack->currentElementCount - 1]);
}

void	deleteArrayStack(ArrayStack* pStack)
{
	if (pStack == NULL)
		return ;
	free(pStack->pElement);
	pStack->pElement = NULL;
	free(pStack);
}

int	isArrayStackFull(ArrayStack* pStack)
{
	if (pStack == NULL || pStack->currentElementCount != pStack->maxElementCount)
		return (FALSE);
	return (TRUE);
}

int	isArrayStackEmpty(ArrayStack* pStack)
{
	if (pStack == NULL || pStack->currentElementCount != 0)
		return (FALSE);
	return (TRUE);
}

void	displayArrayStack(ArrayStack* pStack)
{
	if (pStack == NULL)
		return ;
	// for (int i = 0; i < pStack->maxElementCount - pStack->currentElementCount; i++)
	// 	printf("| |\n");
	for (int i = pStack->currentElementCount - 1; i >= 0; i--)
		printf("|%c|\n", pStack->pElement[i].data);
	printf(" ⎺\n");
}