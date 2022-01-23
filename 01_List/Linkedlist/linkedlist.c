#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkedList*	createLinkedList()
{
	LinkedList*	linkedlist;

	linkedlist = (LinkedList*)malloc(sizeof(LinkedList));
	if (linkedlist == NULL)
		return (NULL);
	memset(linkedlist, 0, sizeof(LinkedList));
	return (linkedlist);
}

int	addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode	*curr;
	ListNode	prev;
	ListNode	next;

	if (position < 0)
		return (FALSE);
	if (pList->currentElementCount == 0)	// 첫 번째 노드 추가
	{
		pList->headerNode = element;
		(pList->currentElementCount)++;
	}
	else if (position > pList->currentElementCount)	// 1
	{
		element.pLink = NULL;
		*curr = pList->headerNode;
		while (curr->pLink != NULL)
			curr = curr->pLink;
		curr->pLink = &element;
	}
	else



}

int	removeLLElement(LinkedList* pList, int position)
{

}

ListNode*	getLLElement(LinkedList* pList, int position)
{

}

void	clearLinkedList(LinkedList* pList)
{

}

int	getLinkedListLength(LinkedList* pList)
{

}

void	deleteLinkedList(LinkedList* pList)
{

}
