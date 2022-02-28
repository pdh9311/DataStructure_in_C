#include "linkedlist.h"

LinkedList* createLinkedList()
{
	LinkedList	*new;

	new = malloc(sizeof (LinkedList));
	if (new == NULL)
		return (NULL);
	new->currentElementCount = 0;
	new->headerNode.pLink = NULL;
	return (new);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);

	ListNode *new = malloc(sizeof (ListNode));
	*new = element;

	if (position == 0)
	{
		if (pList->headerNode.pLink == NULL)
			pList->headerNode.pLink = new;
		else
		{
			new->pLink = pList->headerNode.pLink;
			pList->headerNode.pLink = new;
		}
	}
	else
	{
		ListNode *prev = NULL;
		ListNode *cur = pList->headerNode.pLink;
		while (--position >= 0)
		{
			prev = cur;
			cur = cur->pLink;
		}
		prev->pLink = new;
		new->pLink = cur;
	}
	(pList->currentElementCount)++;
	return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);

	ListNode *prev = NULL;
	ListNode *del = pList->headerNode.pLink;
	while (--position >= 0)
	{
		prev = del;
		del = del->pLink;
	}
	// position == 0 인 경우
	if (!prev)
		pList->headerNode.pLink = del->pLink;
	else
		prev->pLink = del->pLink;
	free(del);
	(pList->currentElementCount)--;
	return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);

	ListNode *cur = pList->headerNode.pLink;
	while (--position >= 0)
	{
		cur = cur->pLink;
	}
	return (cur);
}

void clearLinkedList(LinkedList* pList)
{
	ListNode *cur = pList->headerNode.pLink;
	if (cur == NULL)
		return ;

	ListNode *del;
	while (cur->pLink)
	{
		del = cur;
		cur = cur->pLink;
		free(del);
	}
	free(cur);
	pList->currentElementCount = 0;
	pList->headerNode.pLink = NULL;
}

int getLinkedListLength(LinkedList* pList)
{
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
	clearLinkedList(pList);
	free(pList);
}

void displayLinkedList(LinkedList* pList)
{
	ListNode *node;

	node = (pList->headerNode).pLink;
	for (int i = 0; i < pList->currentElementCount; i++)
	{
		printf("%d ", node->data);
		node = node->pLink;
	}
}