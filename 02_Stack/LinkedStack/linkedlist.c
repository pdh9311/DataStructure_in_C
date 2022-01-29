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

/* 리스트 역순을 만들기 위해서
 * 리스트를 처음부터 끝까지 이동할때
 * 현재위치를 기준으로 이전위치와 다음위치를 저장해두어야
 * 다음 위치로 이동할 수 있고, 현재위치에서 가리키는 곳을 이전위치로 변경할 수 있습니다.
 * 즉,
 * 1. 현재 노드가 가리키는 다음 노드를 끊어서 이전 노드를 가리켜야 하기 때문에
 *    가리키는 노드를 바꾸는 순간 다음 노드는 찾아갈 방법이 없습니다.
 *    따라서 다음노드를 저장해둘 next 포인터 변수가 필요합니다.
 * 2. 마찬가지로 현재 노드가 가리키는 곳을 이전 노드로 바꾸어야하는데
 *    현재노드로 이동한 순간 이전노드는 찾아갈 방법이 없으므로 prev 포인터 변수가 필요하게 됩니다.
 *************************************************************
 * 여기서 중요한 점은 역순으로 만드는것이기 때문에
 * 역순으로 만들었을때 마지막 NULL위치를 시작 위치로 잡고 가는 것입니다. */
void	reverseLinkedList(LinkedList* pList)
{
	ListNode*	prev;
	ListNode*	curr;
	ListNode*	next;
	int			i;
	int			listLength;

	if (pList == NULL)
		return ;
	curr = NULL;
	next = pList->headerNode.pLink;
	listLength = getLinkedListLength(pList);
	for (i = 0; i < listLength; i++)
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
	int			listLength;

	if (pList == NULL)
		return ;
	curr = pList->headerNode.pLink;
	listLength = getLinkedListLength(pList);
	if (!curr)
		printf("empty list");
	else
	{
		for (i = 0; i < listLength; i++)
		{
			printf("%d ", curr->data);
			curr = curr->pLink;
		}
	}
	printf("\n");
}
