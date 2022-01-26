#include "polylist.h"

PLinkedList*	createLinkedList()
{
	PLinkedList*	linkedlist;

	linkedlist = (PLinkedList*)malloc(sizeof(PLinkedList));
	if (linkedlist == NULL)
		return (NULL);
	linkedlist->currentElementCount = 0;
	linkedlist->headerNode.pLink = NULL;
	return (linkedlist);
}

int	addLLElement(PLinkedList* pList, int position, PListNode element)
{
	PListNode	*curr;
	PListNode	*addNode;
	int			i;

	if (pList == NULL || position < 0 || position > pList->currentElementCount)
		return (FALSE);
	addNode = (PListNode *)malloc(sizeof(PListNode));
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

int	removeLLElement(PLinkedList* pList, int position)
{
	PListNode	*curr;
	PListNode	*temp;
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

PListNode*	getLLElement(PLinkedList* pList, int position)
{
	int			i;
	PListNode	*curr;

	if (pList == NULL || position < 0 || position >= pList->currentElementCount || pList->currentElementCount == 0)
		return (NULL);
	curr = pList->headerNode.pLink;
	for (i = 0; i < position; i++)	// position 노드까지 이동
		curr = curr->pLink;
	return (curr);
}

void	clearLinkedList(PLinkedList* pList)
{
	if (pList == NULL)
		return ;
	while (pList->currentElementCount)
		removeLLElement(pList, 0);
}

int	getLinkedListLength(PLinkedList* pList)
{
	if (pList == NULL)
		return (-1);
	return (pList->currentElementCount);
}

void	deleteLinkedList(PLinkedList* pList)
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
void	reverseLinkedList(PLinkedList* pList)
{
	PListNode*	prev;
	PListNode*	curr;
	PListNode*	pnode;
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

int	addPolyNodeList(PLinkedList* pList, float coef, int degree)
{
	PListNode*	curr;
	PListNode	addNode;
	int			i;

	if (pList == NULL)
		return (FALSE);
	addNode.coef = coef;
	addNode.degree = degree;
	curr = pList->headerNode.pLink;
	if (pList->currentElementCount == 0)
	{
		addLLElement(pList, 0, addNode);
		return (TRUE);
	}
	for (i = 0; i < getLinkedListLength(pList); i++)
	{
		if (curr->degree == degree)
		{
			curr->coef += coef;
			break ;
		}
		else if (curr->degree < degree)
		{
			addLLElement(pList, i, addNode);
			break ;
		}
		else if (i == getLinkedListLength(pList) - 1 && curr->degree > degree)
		{
			addLLElement(pList, i + 1, addNode);
			break ;
		}
		else
			curr = curr->pLink;
	}
	return (TRUE);
}

int	addPolyNode(PLinkedList* pList, PLinkedList* temp)
{
	PListNode*	tmp;
	int			i;

	if (pList == NULL || temp == NULL)
		return (FALSE);
	tmp = temp->headerNode.pLink;
	for (i = 0; i < getLinkedListLength(temp); i++)
	{
		addPolyNodeList(pList, tmp->coef, tmp->degree);
		tmp = tmp->pLink;
	}
	return (TRUE);
}

PLinkedList*	addPolyList(PLinkedList* a, PLinkedList* b)
{
	PLinkedList*	newlist;

	newlist = createLinkedList();
	addPolyNode(newlist, a);
	addPolyNode(newlist, b);
	return (newlist);
}
