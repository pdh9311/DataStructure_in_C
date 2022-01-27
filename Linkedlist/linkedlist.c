#include "linkedlist.h"

LinkedList*	createLinkedList()		// linkedlist 생성
{
	LinkedList* linkedlist;

	linkedlist = (LinkedList*)malloc(sizeof(LinkedList));
	if (linkedlist == NULL)
		return (NULL);
	linkedlist->currentElementCount = 0;
	linkedlist->headerNode.pLink = NULL;
	return (linkedlist);
}

int	addLLElement(LinkedList* pList, int position, ListNode element)		// 노드 추가
{
	ListNode	*curr;
	ListNode	*addNode;
	int			i;

	if (pList == NULL || position < 0 || position > pList->currentElementCount)
		return (FALSE);
	addNode = (ListNode *)malloc(sizeof(ListNode));
	if (addNode == NULL)
		return (FALSE);
	addNode->data = element.data;
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

int	removeLLElement(LinkedList* pList, int position)		// 노드 제거
{
	ListNode	*curr;
	ListNode	*temp;

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

ListNode*	getLLElement(LinkedList* pList, int position)		// 노드 가져오기
{
	int			i;
	ListNode	*curr;

	if (pList == NULL || position < 0 || position >= pList->currentElementCount)
		return (NULL);
	curr = pList->headerNode.pLink;
	for (i = 0; i < position; i++)
		curr = curr->pLink;
	return (curr);
}

void	clearLinkedList(LinkedList* pList)		// linkedlist 초기화
{
	ListNode	*curr;
	ListNode	*next;

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

int	getLinkedListLength(LinkedList* pList)		// linkedlist 노드의 개수 확인
{
	if (pList == NULL)
		return (-1);
	return (pList->currentElementCount);
}

void	deleteLinkedList(LinkedList* pList)		// linkedlist free
{
	if (pList == NULL)
		return ;
	clearLinkedList(pList);
	free(pList);
	pList = NULL;
}

void	reverseLinkedList(LinkedList* pList)
{
	ListNode*	prev;
	ListNode*	curr;
	ListNode*	next;
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

void	displayLinkedList(LinkedList *pList)
{
	ListNode	*curr;
	int			i;

	if (pList == NULL)
		return ;
	curr = pList->headerNode.pLink;
	if (!curr)
		printf("empty list");
	else{
		for (i = 0; i < getLinkedListLength(pList); i++)
			printf("%d ", getLLElement(pList, i)->data);
	}
	printf("\n");
}
