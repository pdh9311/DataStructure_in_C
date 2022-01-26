#include "doublylist.h"

DLinkedList*	createDoublyList()
{
	DLinkedList*	doublyList;

	doublyList = (DLinkedList*)malloc(sizeof(DLinkedList));
	if (doublyList == NULL)
		return (NULL);
	doublyList->currentElementCount = 0;
	doublyList->headerNode.pLLink = NULL;
	doublyList->headerNode.pRLink = NULL;
	return (doublyList);
}

void	deleteDoublyList(DLinkedList* pList)
{
	if (pList == NULL)
		return ;
	clearDoublyList(pList);
	if (pList != NULL)
	{
		free(pList);
		pList = NULL;
	}
}

/**
 * 0 1 2 3 4 (curr: 5)
 * ADD: position(5)
 */
int	addDLElement(DLinkedList* pList, int position, DListNode element)
{
	DListNode*	addNode;
	DListNode*	curr;
	int				i;

	if (pList == NULL || position < 0 || position > pList->currentElementCount)
		return (FALSE);
	addNode = (DListNode*)malloc(sizeof(DListNode));
	if (addNode == NULL)
		return (FALSE);
	*addNode = element;
	if (pList->currentElementCount == 0)
	{
		pList->headerNode.pRLink = addNode;
		addNode->pLLink = NULL;
		addNode->pRLink = NULL;
	}
	else if (position == 0)
	{
		addNode->pLLink = NULL;
		addNode->pRLink = pList->headerNode.pRLink;
		pList->headerNode.pRLink->pLLink = addNode;
		pList->headerNode.pRLink = addNode;
	}
	else
	{
		curr = pList->headerNode.pRLink;
		for (i = 0; i < position - 1; i++)
			curr = curr->pRLink;
		addNode->pLLink = curr;
		if (position == pList->currentElementCount)	// 마지막 노드 추가
			addNode->pRLink = NULL;
		else										// 중간 노드 추가
		{
			addNode->pRLink = curr->pRLink;
			curr->pRLink->pLLink = addNode;
		}
		curr->pRLink = addNode;
	}
	pList->currentElementCount++;
	return (TRUE);
}

int	removeDLElement(DLinkedList* pList, int position)
{
	DListNode*	curr;
	DListNode*	temp;
	int				i;

	if (pList == NULL || position < 0 || position >= pList->currentElementCount || pList->currentElementCount == 0)
		return (FALSE);
	temp = NULL;
	curr = pList->headerNode.pRLink;
	if (position == 0)
	{
		temp = curr;
		if (curr->pRLink != NULL)
			curr->pRLink->pLLink = NULL;
		pList->headerNode.pRLink = curr->pRLink;
	}
	else
	{
		for (i = 0; i < position - 1; i++)
			curr = curr->pRLink;
		temp = curr->pRLink;
		if (position == pList->currentElementCount - 1)
			curr->pRLink = NULL;
		else
		{
			curr->pRLink = curr->pRLink->pRLink;
			curr->pRLink->pRLink->pLLink = curr;
		}
	}
	if (temp != NULL)
	{
		free(temp);
		temp = NULL;
	}
	pList->currentElementCount--;
	return (TRUE);
}

void	clearDoublyList(DLinkedList* pList)
{
	if (pList == NULL)
		return ;
	while (pList->currentElementCount)
		removeDLElement(pList, 0);
}

int	getDoublyListLength(DLinkedList* pList)
{
	if (pList == NULL)
		return (-1);
	return (pList->currentElementCount);
}

DListNode*	getDLElement(DLinkedList* pList, int position)
{
	DListNode*	curr;
	int				i;

	if (pList == NULL)
		return (NULL);
	curr = pList->headerNode.pRLink;
	for (i = 0; i < position; i++)
		curr = curr->pRLink;
	return (curr);
}

void	displayDoublyList(DLinkedList* pList)
{
	int	i;

	if (pList == NULL)
		return ;
	for (i = 0; i < getDoublyListLength(pList); i++)
		printf("%d ", getDLElement(pList, i)->data);
	printf("\n");
}
