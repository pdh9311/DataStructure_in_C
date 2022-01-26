#include "CircularLinkedlist.h"

void	list_print(CLinkedList *list)
{
	CListNode*	curr;
	int			i;

	curr = list->headerNode.pLink;
	for (i = 0; i < getLinkedListLength(list); i++)
	{
		printf("%d ", curr->data);
		curr = curr->pLink;
	}
	printf("\n");
}

void	func1()
{
	CLinkedList*	list1;
	list1 = createLinkedList();

	CListNode	node;
	node.pLink = NULL;

	node.data = 10;
	addLLElement(list1, 0, node);
	list_print(list1);

	node.data = 11;
	addLLElement(list1, 1, node);
	list_print(list1);

	node.data = 12;
	addLLElement(list1, 2, node);
	list_print(list1);

	node.data = 13;
	addLLElement(list1, 3, node);
	list_print(list1);

	node.data = 14;
	addLLElement(list1, 4, node);
	list_print(list1);

	removeLLElement(list1, 4);
	list_print(list1);

	removeLLElement(list1, 0);
	list_print(list1);

	removeLLElement(list1, 1);
	list_print(list1);

	clearLinkedList(list1);
	list_print(list1);

	deleteLinkedList(list1);
}

void func2()
{
	CLinkedList*	list2;
	list2 = createLinkedList();

	CListNode	node;
	node.pLink = NULL;

	node.data = 10;
	addLLElement(list2, 0, node);
	node.data = 11;
	addLLElement(list2, 1, node);
	node.data = 12;
	addLLElement(list2, 2, node);
	node.data = 13;
	addLLElement(list2, 3, node);
	node.data = 14;
	addLLElement(list2, 4, node);
	list_print(list2);

	moveHeaderNode(list2, 3);
	list_print(list2);

	deleteLinkedList(list2);
}

int main(void)
{
	func1();
	printf("======================\n");
	func2();
	// system("leaks a.out");
	return (0);
}
