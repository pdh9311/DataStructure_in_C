#include "arraylist.h"

void	func(void)
{

}

int main(void)
{
		const int	max = 7;
	int			i;
	ArrayList*	arraylist;

	/* error */
	arraylist = createArrayList(-1);
	arraylist = createArrayList(__INT_MAX__ + 1);

	/* create arraylist */
	arraylist = createArrayList(max);

	ArrayListNode	node0;
	ArrayListNode	node1;
	ArrayListNode	node2;
	ArrayListNode	node3;
	ArrayListNode	node4;
	node0.data = 10;
	node1.data = 11;
	node2.data = 12;
	node3.data = 13;
	node4.data = 14;
	addALElement(arraylist, 0, node0);
	addALElement(arraylist, 1, node1);
	addALElement(arraylist, 2, node2);
	addALElement(arraylist, 3, node3);
	addALElement(arraylist, 4, node4);
	displayArrayList(arraylist);
	printf("cur: %d | max: %d\n\n", arraylist->currentElementCount, arraylist->maxElementCount);

	ArrayListNode	node5;
	node5.data = 15;
	addALElement(arraylist, 2, node5);
	displayArrayList(arraylist);
	printf("cur: %d | max: %d\n\n", arraylist->currentElementCount, arraylist->maxElementCount);

	ArrayListNode	node6;
	node6.data = 16;
	addALElement(arraylist, 2, node6);
	displayArrayList(arraylist);
	printf("cur: %d | max: %d\n\n", arraylist->currentElementCount, arraylist->maxElementCount);

	ArrayListNode	node7;
	node7.data = 17;
	addALElement(arraylist, 2, node7);
	displayArrayList(arraylist);
	printf("cur: %d | max: %d\n\n", arraylist->currentElementCount, arraylist->maxElementCount);

	ArrayListNode	node8;
	node8.data = 18;
	addALElement(arraylist, 2, node8);
	displayArrayList(arraylist);
	printf("cur: %d | max: %d\n\n", arraylist->currentElementCount, arraylist->maxElementCount);

	ArrayListNode	node9;
	node9.data = 19;
	addALElement(arraylist, 0, node9);
	displayArrayList(arraylist);
	printf("cur: %d | max: %d\n\n", arraylist->currentElementCount, arraylist->maxElementCount);

	/* remove node */
	removeALElement(arraylist, 3);
	displayArrayList(arraylist);
	printf("cur: %d | max: %d\n\n", arraylist->currentElementCount, arraylist->maxElementCount);

	/* get node & modify node value */
	ArrayListNode*	n1 = getALElement(arraylist, 1);
	printf("n1: %d\n", n1->data);
	n1->data = 21;
	displayArrayList(arraylist);
	printf("cur: %d | max: %d\n\n", arraylist->currentElementCount, arraylist->maxElementCount);

	/* clear arraylist - initialize */
	clearArrayList(arraylist);
	displayArrayList(arraylist);
	printf("cur: %d | max: %d\n\n", arraylist->currentElementCount, arraylist->maxElementCount);

	/* delete arraylist - free node, free arraylist */
	// deleteArrayList(arraylist);
	while (1);
	return (0);
}