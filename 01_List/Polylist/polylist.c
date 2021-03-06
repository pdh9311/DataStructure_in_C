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

/* 처음 가지고 있는 노드가 하나도 없다면 첫번재 위치에 노드를 추가해준다.
 * 그 다음...
 * 노드를 리스트의 처음부터 끝까지 이동하면서
 * 이동된 노드 위치에서의 degree값 과 파라미터의 degree값을 비교한다.
 * 파라미터의 degree값이 현재 노드 위치에서의 degree값과 같다면 새로운 노드를 추가하지 않고 바로 coef를 더해주게된다.
 * 파라미터의 degree값이 현재 노드 위치에서의 degree값보다 크다면 현재위치에 파라미터의 coef, degree를 가지는 새로운 노드를 추가한다.
 * 마지막 노드까지 이동했지만 위의 두 경우에 포함되지 않았다면 파라미터의 degree가 pList에 있는 degree중 가장 작다는 것을 의미하기 때문에
 * 마지막 노드 뒤에 파라미터의 coef, degree를 가지는 새로운 노드를 추가해준다. */
int	addPolyNode(PolyList* pList, float coef, int degree)
{
	PolyListNode*	curr;
	PolyListNode	addNode;
	int				i;
	int				listLength;

	if (pList == NULL)
		return (FALSE);
	listLength = getLinkedListLength(pList);
	addNode.coef = coef;
	addNode.degree = degree;
	curr = pList->headerNode.pLink;
	if (pList->currentElementCount == 0)
	{
		addLLElement(pList, 0, addNode);
		return (TRUE);
	}
	for (i = 0; i < listLength; i++)
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
		else if (i == listLength - 1)
		{
			addLLElement(pList, i + 1, addNode);
			break ;
		}
		else
			curr = curr->pLink;
	}
	return (TRUE);
}

/* 이 함수에서는 pList에 temp에 들어있는 다항식을 합쳐주는 역할을 합니다. */
int	mergePolyList(PolyList* pList, PolyList* temp)
{
	PolyListNode*	curr;
	int				i;
	int				listLength;

	if (pList == NULL || temp == NULL)
		return (FALSE);
	curr = temp->headerNode.pLink;
	listLength = getLinkedListLength(temp);
	for (i = 0; i < listLength; i++)
	{
		addPolyNode(pList, curr->coef, curr->degree);
		curr = curr->pLink;
	}
	return (TRUE);
}

/* addPolyListNode()함수를 사용해서 다항식의 리스트를 만들었다면
 * 이번 함수에서는 두 다항식 a, b를 더해주는 역할을 한다. */
PolyList*	plusPolyList(PolyList* a, PolyList* b)
{
	PolyList*	newlist;

	if (a == NULL || b == NULL)
		return (NULL);
	newlist = createLinkedList();
	if (newlist == NULL)
		return (NULL);
	mergePolyList(newlist, a);
	mergePolyList(newlist, b);
	return (newlist);
}

void	displayLinkedList(PolyList *pList)
{
	PolyListNode	*curr;
	int				i;
	int				listLength;

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
			printf("%.1fx^(%d) ", curr->coef, curr->degree);
			if (i != listLength - 1)
				printf("+ ");
			curr = curr->pLink;
		}
	}
	printf("\n");
}
