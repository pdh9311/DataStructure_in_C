#include "linkedlist.h"

void	func1()
{
	LinkedList	*linkedlist;
	linkedlist = createLinkedList();

	ListNode	node;
	node.pLink = NULL;

	node.data = 10;
	addLLElement(linkedlist, 0, node);
	displayLinkedList(linkedlist);

	node.data = 11;
	addLLElement(linkedlist, 1, node);
	displayLinkedList(linkedlist);

	node.data = 12;
	addLLElement(linkedlist, 2, node);
	displayLinkedList(linkedlist);

	node.data = 13;
	addLLElement(linkedlist, 3, node);
	displayLinkedList(linkedlist);

	node.data = 14;
	addLLElement(linkedlist, 4, node);
	displayLinkedList(linkedlist);

	removeLLElement(linkedlist, 4);
	displayLinkedList(linkedlist);

	removeLLElement(linkedlist, 0);
	displayLinkedList(linkedlist);

	removeLLElement(linkedlist, 1);
	displayLinkedList(linkedlist);

	clearLinkedList(linkedlist);
	displayLinkedList(linkedlist);

	deleteLinkedList(linkedlist);
}

void func2(void)
{
	LinkedList*	list;
	ListNode	node;
	int			i;

	list = createLinkedList();
	for (i = 0; i < 10; i++)
	{
		node.data = i + 10;
		addLLElement(list, i, node);
	}
	displayLinkedList(list);

	reverseLinkedList(list);
	displayLinkedList(list);
}

int main(void)
{
	func1();
	func2();
	// system("leaks a.out");
	return (0);
}
