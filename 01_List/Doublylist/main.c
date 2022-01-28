#include "doublylist.h"

void	func1()
{
	DoublyList		*list;
	DoublyListNode	node;

	/* Doubly list 생성 */
	list = createDoublyList();

	/* 1개 생성 후 제거 */
	node.data = 10;
	addDLElement(list, 0, node);
	displayDoublyList(list);

	removeDLElement(list, 0);
	displayDoublyList(list);

	/* 0~4 생성 */
	node.data = 10;
	addDLElement(list, 0, node);
	displayDoublyList(list);

	node.data = 11;
	addDLElement(list, 1, node);
	displayDoublyList(list);

	node.data = 12;
	addDLElement(list, 2, node);
	displayDoublyList(list);

	node.data = 13;
	addDLElement(list, 3, node);
	displayDoublyList(list);

	node.data = 14;
	addDLElement(list, 4, node);
	displayDoublyList(list);

	/* 마지막 노드 제거 */
	removeDLElement(list, 4);
	displayDoublyList(list);

	/* 중간 노드 제거 */
	removeDLElement(list, 2);
	displayDoublyList(list);

	/* 첫 번째 노드 제거 */
	removeDLElement(list, 0);
	displayDoublyList(list);

	/* 전체 노드 제거 */
	clearDoublyList(list);
	displayDoublyList(list);

	/* 리스트 해제 */
	deleteDoublyList(list);
}


int main(void)
{
	func1();

	// system("leaks a.out");
	return (0);
}
