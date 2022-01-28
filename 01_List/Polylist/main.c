#include "polylist.h"

void	func1()
{
	PolyList*		a;
	PolyList*		b;
	PolyList*		c;

	a = createLinkedList();
	b = createLinkedList();

	/* 다항식 A*/
	addPolyNode(a, 4, 5);
	addPolyNode(a, 6, 6);
	addPolyNode(a, 2, 2);
	printf("다항식 a   : ");
	displayLinkedList(a);

	/* 다항식 B*/
	addPolyNode(b, -1, 5);
	addPolyNode(b, 2, 4);
	addPolyNode(b, 3, 2);
	addPolyNode(b, 4, 0);
	printf("다항식 b   : ");
	displayLinkedList(b);

	/* A + B */
	c = plusPolyList(a, b);
	printf("다항식 a+b : ");
	displayLinkedList(c);

	deleteLinkedList(a);
	deleteLinkedList(b);
	deleteLinkedList(c);
}

int main(void)
{
	func1();
	// system("leaks a.out");
	return (0);
}
