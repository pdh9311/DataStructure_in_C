#include "polylist.h"

void	list_print(PLinkedList *lst)
{
	PListNode	*curr;

	curr = lst->headerNode.pLink;
	while (curr != NULL)
	{
		printf("%.1fx^(%d) ", curr->coef, curr->degree);
		if (curr->pLink != NULL)
			printf("+ ");
		curr = curr->pLink;
	}
	printf("\n");
}

int	func1()
{
	PLinkedList*	a;
	PLinkedList*	b;
	PLinkedList*	c;

	PListNode		node;

	a = createLinkedList();
	b = createLinkedList();

	/* 다항식 A*/
	addPolyNodeList(a, 6, 6);
	addPolyNodeList(a, 4, 5);
	addPolyNodeList(a, 2, 2);
	list_print(a);

	/* 다항식 B*/
	addPolyNodeList(b, -1, 5);
	addPolyNodeList(b, 2, 4);
	addPolyNodeList(b, 3, 2);
	addPolyNodeList(b, 4, 0);
	list_print(b);

	/* A + B */
	c = addPolyList(a, b);
	list_print(c);

	deleteLinkedList(a);
	deleteLinkedList(b);
}

int main(void)
{
	func1();
	// func2();
	// system("leaks a.out");
	return (0);
}
