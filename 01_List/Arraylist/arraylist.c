#include "arraylist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ArrayList*	createArrayList(int maxElementCount)
{
	ArrayList	*arraylist;

	if (maxElementCount > 0 && maxElementCount <= __INT_MAX__)
	{
		arraylist = (ArrayList *)malloc(sizeof(ArrayList));
		if (arraylist == NULL)
			return (NULL);
		arraylist->maxElementCount = maxElementCount;
		arraylist->currentElementCount = 0;
		arraylist->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
		if (arraylist->pElement == NULL)
		{
			free(arraylist);
			arraylist = NULL;
			return (NULL);
		}
		memset(arraylist->pElement, 0, sizeof(ArrayListNode) * maxElementCount);
	}
	else
	{
		printf("Error:parameter:maxElementCount < 0 or maxElementCount > __INT_MAX__\n");
		return (NULL);
	}
	return (arraylist);
}

void	deleteArrayList(ArrayList* pList)
{
	free(pList->pElement);
	pList->pElement = NULL;
	free(pList);
	pList = NULL;
}

int	isArrayListFull(ArrayList* pList)
{
	if (pList->maxElementCount == pList->currentElementCount)
		return (TRUE);
	return (FALSE);
}

/**
 * 0 1 2 3 4 5	(curr: 6)
 * a b c d e f
 ************************
 * position:2에 추가
 * 0 1 2 3 4 5 6	(curr: 7)
 * a b g c d e f
 ************************
 * position:7에 추가
 * 0 1 2 3 4 5 6 7	(curr: 7)
 * a b g c d e f h
 */
int	addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	int				i;
	ArrayListNode	*newElement;

	if (position < 0 || position > pList->maxElementCount)
		return (FALSE);
	if (isArrayListFull(pList) == TRUE)	// maxElementCount 4, 10, 14
	{
		if (pList->maxElementCount % 10 != 0)
			pList->maxElementCount += (10 - pList->maxElementCount % 10);
		else
			pList->maxElementCount += 10;
		newElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * pList->maxElementCount);
		if (newElement == NULL)
			return (FALSE);
		for (i = 0; i < pList->currentElementCount; i++)
			newElement[i] = pList->pElement[i];
		free(pList->pElement);
		pList->pElement = newElement;
		if (addALElement(pList, position, element) == FALSE)
			return (FALSE);
	}
	else if (position >= pList->currentElementCount)	// 마지막 위치에 노드 추가
	{
		pList->pElement[pList->currentElementCount] = element;
		(pList->currentElementCount)++;
	}
	else	// 중간 위치에 노드 추가
	{
		for (i = pList->currentElementCount - 1; i >= position; i--)
		{
			pList->pElement[i + 1] = pList->pElement[i];
		}
		pList->pElement[position] = element;
		(pList->currentElementCount)++;
	}
	return (TRUE);
}

int	removeALElement(ArrayList* pList, int position)
{
	int	i;

	if (position < 0 || position > pList->maxElementCount)
		return (FALSE);
	memset(&pList->pElement[position], 0, sizeof(ArrayListNode));
	for (i = position; i < pList->currentElementCount; i++)
	{
		pList->pElement[i] = pList->pElement[i + 1];
	}
	memset(&pList->pElement[i], 0, sizeof(ArrayListNode));
	(pList->currentElementCount)--;
}

ArrayListNode*	getALElement(ArrayList* pList, int position)
{
	return (&(pList->pElement[position]));
}

void	displayArrayList(ArrayList* pList)
{
	int	i;

	if (pList->currentElementCount == 0)
		return ;
	printf("|");
	for (i = 0; i < pList->currentElementCount; i++)
		printf("%2d|", pList->pElement[i].data);
	printf("\n");
}

void	clearArrayList(ArrayList* pList)
{
	free(pList->pElement);
	pList->pElement = NULL;
	pList->maxElementCount = 10;
	pList->currentElementCount = 0;
	pList->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * 10);
}

int	getArrayListLength(ArrayList* pList)
{
	return (pList->currentElementCount);
}
