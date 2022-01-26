#include "doublylist.h"

void	func(void)
{
	DLinkedList*	dlist;
	DListNode		node;
	DListNode*		curr;
	int				i;

	dlist = createDoublyList();

	/* 마지막 노드 추가 */
	node.data = 10;
	addDLElement(dlist, 0, node);
	node.data = 11;
	addDLElement(dlist, 1, node);
	node.data = 12;
	addDLElement(dlist, 2, node);
	node.data = 13;
	addDLElement(dlist, 3, node);
	displayDoublyList(dlist);

	/* 중간 노드 추가 */
	node.data = 14;
	addDLElement(dlist, 1, node);
	displayDoublyList(dlist);

	/* 첫 번째 노드 추가 */
	node.data = 15;
	addDLElement(dlist, 0, node);
	displayDoublyList(dlist);

	/* data 수정 */
	curr = getDLElement(dlist, 3);
	curr->data = 20;
	displayDoublyList(dlist);

	/* double linked list 앞 뒤에서 출력 */
	printf("\n");
	curr = dlist->headerNode.pRLink;
	for (i = 0; i < getDoublyListLength(dlist); i++)
	{
		printf("%d ", curr->data); fflush(stdout);
		if (curr->pRLink != NULL)
			curr = curr->pRLink;
	}
	printf("\n");
	for (i = 0; i < getDoublyListLength(dlist); i++)
	{
		printf("%d ", curr->data); fflush(stdout);
		curr = curr->pLLink;
	}
	printf("\n");

	/* free */
	clearDoublyList(dlist);
	deleteDoublyList(dlist);
}

int	main(void)
{
	func();
	// system("leaks a.out");
	return (0);
}
