#include "polylist.h"

PolyList*	createLinkedList()		// linkedlist 생성
{
	PolyList*	list;

	list = (PolyList*)malloc(sizeof(PolyList));
	if (list == NULL)
		return (NULL);
	list->currentElementCount = 0;
	list->headerNode.pLink = NULL;
	return (list);
}

int	addLLElement(PolyList* pList, int position, PolyListNode element)		// 노드 추가
{
	PolyListNode	*curr;
	PolyListNode	*addNode;
	int			i;

	if (pList == NULL || position < 0 || position > pList->currentElementCount)
		return (FALSE);
	addNode = (PolyListNode *)malloc(sizeof(PolyListNode));
	if (addNode == NULL)
		return (FALSE);
	*addNode = element;
	if (position == 0)
	{
		addNode->pLink = pList->headerNode.pLink;
		pList->headerNode.pLink = addNode;
	}
	else
	{
		curr = getLLElement(pList, position - 1);
		addNode->pLink = curr->pLink;
		curr->pLink = addNode;
	}
	pList->currentElementCount++;
	return (TRUE);
}

int	removeLLElement(PolyList* pList, int position)		// 노드 제거
{
	PolyListNode	*curr;
	PolyListNode	*temp;

	int	i;

	if (pList == NULL || position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	if (position == 0)
	{
		curr = pList->headerNode.pLink;
		temp = curr;
		pList->headerNode.pLink = curr->pLink;
	}
	else
	{
		curr = getLLElement(pList, position - 1);
		temp = curr->pLink;
		curr->pLink = curr->pLink->pLink;
	}
	free(temp);
	temp = NULL;
	pList->currentElementCount--;
	return (TRUE);
}

PolyListNode*	getLLElement(PolyList* pList, int position)		// 노드 가져오기
{
	int			i;
	PolyListNode	*curr;

	if (pList == NULL || position < 0 || position >= pList->currentElementCount)
		return (NULL);
	curr = pList->headerNode.pLink;
	for (i = 0; i < position; i++)
		curr = curr->pLink;
	return (curr);
}

void	clearLinkedList(PolyList* pList)		// linkedlist 초기화
{
	PolyListNode	*curr;
	PolyListNode	*next;

	if (pList == NULL)
		return ;
	curr = pList->headerNode.pLink;
	while (pList->currentElementCount)
	{
		next = curr->pLink;
		free(curr);
		curr = next;
		pList->currentElementCount--;
	}
	pList->headerNode.pLink = NULL;
}

int	getLinkedListLength(PolyList* pList)		// linkedlist 노드의 개수 확인
{
	if (pList == NULL)
		return (-1);
	return (pList->currentElementCount);
}

void	deleteLinkedList(PolyList* pList)		// linkedlist free
{
	if (pList == NULL)
		return ;
	clearLinkedList(pList);
	free(pList);
	pList = NULL;
}

void	reverseLinkedList(PolyList* pList)
{
	PolyListNode*	prev;
	PolyListNode*	curr;
	PolyListNode*	next;
	int			i;

	if (pList == NULL)
		return ;
	curr = NULL;
	next = pList->headerNode.pLink;
	for (i = 0; i < getLinkedListLength(pList); i++)
	{
		prev = curr;
		curr = next;
		next = curr->pLink;
		curr->pLink = prev;
	}
	pList->headerNode.pLink = curr;
}

void	displayLinkedList(PolyList *pList)
{
	PolyListNode	*curr;
	int			i;

	if (pList == NULL)
		return ;
	curr = pList->headerNode.pLink;
	if (!curr)
		printf("empty list");
	else{
		for (i = 0; i < getLinkedListLength(pList); i++)
		{
			printf("%.1fx^(%d) ", curr->coef, curr->degree);
			if (i != getLinkedListLength(pList) - 1)
				printf("+ ");
			curr = curr->pLink;
		}
	}
	printf("\n");
}


int	addPolyNode(PolyList* pList, float coef, int degree)
{
	PolyListNode*	curr;
	PolyListNode	addNode;
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
		else if (i == getLinkedListLength(pList) - 1)
		{
			addLLElement(pList, i + 1, addNode);
			break ;
		}
		else
			curr = curr->pLink;
	}
	return (TRUE);
}

int	mergePolyList(PolyList* pList, PolyList* temp)
{
	PolyListNode*	curr;
	int				i;

	if (pList == NULL || temp == NULL)
		return (FALSE);
	curr = temp->headerNode.pLink;
	for (i = 0; i < getLinkedListLength(temp); i++)
	{
		addPolyNode(pList, curr->coef, curr->degree);
		curr = curr->pLink;
	}
	return (TRUE);
}

PolyList*	plusPolyList(PolyList* a, PolyList* b)
{
	PolyList*	newlist;

	if (a == NULL || b == NULL)
		return (NULL);
	newlist = createLinkedList();
	mergePolyList(newlist, a);
	mergePolyList(newlist, b);
	return (newlist);
}
