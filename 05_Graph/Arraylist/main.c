#include "arraylist.h"

void	print_cur_max(ArrayList* arraylist)
{
	printf("cur: %d | max: %d\n\n", arraylist->currentElementCount, arraylist->maxElementCount);
}

void	func(void)
{
	const int	max = 5;
	ArrayList*	arraylist;

	/* error */
	arraylist = createArrayList(-1);

	/* create arraylist */
	arraylist = createArrayList(max);

	ArrayListNode	node;
	node.data = 10;
	addALElement(arraylist, 0, node);
	node.data = 11;
	addALElement(arraylist, 1, node);
	node.data = 12;
	addALElement(arraylist, 2, node);
	displayArrayList(arraylist);
	print_cur_max(arraylist);

	node.data = 13;
	addALElement(arraylist, 2, node);
	displayArrayList(arraylist);
	print_cur_max(arraylist);

	node.data = 14;
	addALElement(arraylist, 2, node);
	displayArrayList(arraylist);
	print_cur_max(arraylist);
///////////////////////////////////////////
	node.data = 15;
	addALElement(arraylist, 6, node);
	displayArrayList(arraylist);
	print_cur_max(arraylist);

	node.data = 16;
	addALElement(arraylist, 5, node);
	displayArrayList(arraylist);
	print_cur_max(arraylist);

	node.data = 17;
	addALElement(arraylist, 0, node);
	displayArrayList(arraylist);
	print_cur_max(arraylist);
printf("----------------------------------\n");
	/* remove node */
	removeALElement(arraylist, 3);
	displayArrayList(arraylist);
	print_cur_max(arraylist);

	removeALElement(arraylist, 5);
	displayArrayList(arraylist);
	print_cur_max(arraylist);

	removeALElement(arraylist, 6);
	displayArrayList(arraylist);
	print_cur_max(arraylist);

	removeALElement(arraylist, 5);
	displayArrayList(arraylist);
	print_cur_max(arraylist);

	removeALElement(arraylist, 0);
	displayArrayList(arraylist);
	print_cur_max(arraylist);

	node.data = 18;
	addALElement(arraylist, 6, node);
	displayArrayList(arraylist);
	print_cur_max(arraylist);
printf("----------------------------------\n");
	/* get node & modify node value */
	ArrayListNode*	n1 = getALElement(arraylist, 1);
	printf("n1: %d\n", n1->data);
	n1->data = 21;
	displayArrayList(arraylist);
	print_cur_max(arraylist);

	/* clear arraylist - initialize */
	clearArrayList(arraylist);
	displayArrayList(arraylist);
	print_cur_max(arraylist);

	/* delete arraylist - free node, free arraylist */
	deleteArrayList(arraylist);
}

int main(void)
{
	func();
	// system("leaks a.out");	// check in background: leaks a.out
	return (0);
}
