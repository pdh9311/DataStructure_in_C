#include "linkedlist.h"

void	list_print(LinkedList *lst)
{
	ListNode	*curr;

	curr = lst->headerNode.pLink;
	while (curr != NULL)
	{
		printf("%d ", curr->data);
		curr = curr->pLink;
	}
	printf("\n");
}

int	func1()
{
	LinkedList	*linkedlist;
	linkedlist = createLinkedList();

	ListNode	node;
	node.pLink = NULL;

	node.data = 10;
	addLLElement(linkedlist, 0, node);
	list_print(linkedlist);

	node.data = 11;
	addLLElement(linkedlist, 1, node);
	list_print(linkedlist);

	node.data = 12;
	addLLElement(linkedlist, 2, node);
	list_print(linkedlist);

	node.data = 13;
	addLLElement(linkedlist, 3, node);
	list_print(linkedlist);

	node.data = 14;
	addLLElement(linkedlist, 4, node);
	list_print(linkedlist);

	removeLLElement(linkedlist, 4);
	list_print(linkedlist);

	removeLLElement(linkedlist, 0);
	list_print(linkedlist);

	removeLLElement(linkedlist, 1);
	list_print(linkedlist);

	clearLinkedList(linkedlist);
	list_print(linkedlist);

	deleteLinkedList(linkedlist);
}

void func2(void)
{
	LinkedList*	list;
	ListNode	node;

	list = createLinkedList();
	node.data = 10;
	addLLElement(list, 0, node);
	node.data = 11;
	addLLElement(list, 1, node);
	node.data = 12;
	addLLElement(list, 2, node);

	reverseLinkedList(list);
	list_print(list);
}

int main(void)
{
	// func1();
	func2();
	// system("leaks a.out");
	return (0);
}