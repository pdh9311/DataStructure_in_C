#include "circularlist.h"

CLinkedList*	createLinkedList()
{
	CLinkedList*	linkedlist;

	linkedlist = (CLinkedList*)malloc(sizeof(CLinkedList));
	if (linkedlist == NULL)
		return (NULL);
	linkedlist->currentElementCount = 0;
	/* add start */
	linkedlist->headerNode.pLink = NULL;
	// end
	return (linkedlist);
}

int	addLLElement(CLinkedList* pList, int position, CListNode element)
{
	CListNode*	curr;
	CListNode*	addNode;
	int			i;

	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	addNode = (CListNode *)malloc(sizeof(CListNode));
	if (addNode == NULL)
		return (FALSE);
	*addNode = element;
	if (pList->currentElementCount == 0)	// node가 하나도 없을때
	{
		pList->headerNode.pLink = addNode;
		/* add start */
		addNode->pLink = addNode;
		// end
	}
	else if (position == 0)	// 첫 번째 노드에 추가
	{
		/* add start */
		curr = pList->headerNode.pLink;
		for (i = 0; i < pList->currentElementCount; i++)
			curr = curr->pLink;
		curr->pLink = addNode;
		// end
		addNode->pLink = pList->headerNode.pLink;
		pList->headerNode.pLink = addNode;
	}
	else
	{
		curr = pList->headerNode.pLink;
		for (i = 0; i < position - 1; i++)	// position 이전 노드까지 이동
			curr = curr->pLink;
		/* modify & add start */
		if (position == pList->currentElementCount - 1)
			addNode->pLink = pList->headerNode.pLink;
		else
			addNode->pLink = curr->pLink;
		// end
		curr->pLink = addNode;
	}
	/* move & add start */
	pList->currentElementCount++;
	// end
	return (TRUE);
}

int	removeLLElement(CLinkedList* pList, int position)
{
	CListNode*	curr;
	CListNode*	temp;
	int			i;

	curr = pList->headerNode.pLink;
	if (position < 0 || position >= pList->currentElementCount || pList->currentElementCount == 0)
		return (FALSE);
	if (position == 0)	// 첫 번째 노드 제거
	{
		temp = curr;
		/* modify & add start */
		for (i = 0; i < pList->currentElementCount; i++)
			curr = curr->pLink;
		curr->pLink = temp->pLink;
		pList->headerNode.pLink = temp->pLink;
		// end
	}
	else
	{
		for (i = 0; i < position - 1; i++)	// position 이전 노드까지 이동
			curr = curr->pLink;
		temp = curr->pLink;
		/* modify & add start */
		if (position == pList->currentElementCount - 1)
			curr->pLink = pList->headerNode.pLink;
		else
			curr->pLink = curr->pLink->pLink;
		// end
	}
	if (temp)
	{
		free(temp);
		temp = NULL;
	}
	pList->currentElementCount--;
	return (TRUE);
}

CListNode*	getLLElement(CLinkedList* pList, int position)
{
	int			i;
	CListNode*	curr;

	if (position < 0 || position >= pList->currentElementCount || pList->currentElementCount == 0)
		return (NULL);
	curr = pList->headerNode.pLink;
	for (i = 0; i < position; i++)	// position 노드까지 이동
		curr = curr->pLink;
	return (curr);
}

void	clearLinkedList(CLinkedList* pList)
{
	while (pList->currentElementCount)
		removeLLElement(pList, 0);
}

int	getLinkedListLength(CLinkedList* pList)
{
	return (pList->currentElementCount);
}

void	deleteLinkedList(CLinkedList* pList)
{
	clearLinkedList(pList);
	if (pList)
	{
		free(pList);
		pList = NULL;
	}
}

int	moveHeaderNode(CLinkedList *pList, int position)
{
	CListNode*	curr;
	int	i;

	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	curr = pList->headerNode.pLink;
	for (i = 0; i < position; i++)
		curr = curr->pLink;
	pList->headerNode.pLink = curr;
	return (TRUE);
}
