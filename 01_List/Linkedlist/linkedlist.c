#include "linkedlist.h"

LinkedList*	createLinkedList()
{
	LinkedList*	linkedlist;

	linkedlist = (LinkedList*)malloc(sizeof(LinkedList));
	if (linkedlist == NULL)
		return (NULL);
	linkedlist->currentElementCount = 0;
	linkedlist->headerNode.pLink = NULL;
	return (linkedlist);
}

int	addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode	*curr;
	ListNode	*addNode;
	int			i;

	if (pList == NULL || position < 0 || position > pList->currentElementCount)
		return (FALSE);
	addNode = (ListNode *)malloc(sizeof(ListNode));
	if (addNode == NULL)
		return (FALSE);
	*addNode = element;
	if (pList->currentElementCount == 0)	// node가 하나도 없을때
	{
		pList->headerNode.pLink = addNode;
		addNode->pLink = NULL;
		pList->currentElementCount++;
	}
	else if (position == 0)	// 첫 번째 노드에 추가
	{
		addNode->pLink = pList->headerNode.pLink;
		pList->headerNode.pLink = addNode;
		pList->currentElementCount++;
	}
	else
	{
		curr = pList->headerNode.pLink;
		for (i = 0; i < position - 1; i++)	// position 이전 노드까지 이동
			curr = curr->pLink;
		if (position == pList->currentElementCount)
			addNode->pLink = NULL;
		else
			addNode->pLink = curr->pLink;
		curr->pLink = addNode;
		pList->currentElementCount++;
	}
	return (TRUE);
}

int	removeLLElement(LinkedList* pList, int position)
{
	ListNode	*curr;
	ListNode	*temp;
	int			i;

	if (pList == NULL || position < 0 || position >= pList->currentElementCount || pList->currentElementCount == 0)
		return (FALSE);
	curr = pList->headerNode.pLink;
	if (position == 0)
	{
		temp = curr;
		pList->headerNode.pLink = curr->pLink;
	}
	else
	{
		for (i = 0; i < position - 1; i++)	// position 이전 노드까지 이동
			curr = curr->pLink;
		temp = curr->pLink;
		curr->pLink = curr->pLink->pLink;
	}
	if (temp)
	{
		free(temp);
		temp = NULL;
	}
	pList->currentElementCount--;
	return (TRUE);
}

ListNode*	getLLElement(LinkedList* pList, int position)
{
	int			i;
	ListNode	*curr;

	if (pList == NULL || position < 0 || position >= pList->currentElementCount || pList->currentElementCount == 0)
		return (NULL);
	curr = pList->headerNode.pLink;
	for (i = 0; i < position; i++)	// position 노드까지 이동
		curr = curr->pLink;
	return (curr);
}

void	clearLinkedList(LinkedList* pList)
{
	if (pList == NULL)
		return ;
	while (pList->currentElementCount)
		removeLLElement(pList, 0);
}

int	getLinkedListLength(LinkedList* pList)
{
	if (pList == NULL)
		return (-1);
	return (pList->currentElementCount);
}

void	deleteLinkedList(LinkedList* pList)
{
	if (pList == NULL)
		return ;
	clearLinkedList(pList);
	if (pList)
	{
		free(pList);
		pList = NULL;
	}
}

/**
 * a b
 * tmp = a;
 * a = b;
 * b = tmp;
 */
void	reverseLinkedList(LinkedList* pList)
{
	ListNode*	prev;
	ListNode*	curr;
	ListNode*	pnode;
	int			i;

	if (pList == NULL)
		return ;
	curr = NULL;
	pnode = pList->headerNode.pLink;
	for (i = 0; i < getLinkedListLength(pList); i++)
	{
		prev = curr;
		curr = pnode;
		pnode = curr->pLink;
		curr->pLink = prev;
	}
	pList->headerNode.pLink = curr;
}
