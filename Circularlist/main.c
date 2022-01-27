#include "circularlist.h"

void	func1()
{
	CircularList	*list;
	CircularNode	node;

	/* circular list 생성 */
	list = createCircularList();

	/* 1개 생성 후 제거 */
	node.data = 10;
	addCLElement(list, 0, node);
	displayCircularList(list);

	removeCLElement(list, 0);
	displayCircularList(list);

	/* 0~4 생성 */
	node.data = 10;
	addCLElement(list, 0, node);
	displayCircularList(list);

	node.data = 11;
	addCLElement(list, 1, node);
	displayCircularList(list);

	node.data = 12;
	addCLElement(list, 2, node);
	displayCircularList(list);

	node.data = 13;
	addCLElement(list, 3, node);
	displayCircularList(list);

	node.data = 14;
	addCLElement(list, 4, node);
	displayCircularList(list);

	/* 마지막 노드 제거 */
	removeCLElement(list, 4);
	displayCircularList(list);

	/* 중간 노드 제거 */
	removeCLElement(list, 2);
	displayCircularList(list);

	/* 첫 번째 노드 제거 */
	removeCLElement(list, 0);
	displayCircularList(list);

	/* 전체 노드 제거 */
	clearCircularList(list);
	displayCircularList(list);

	/* 리스트 해제 */
	deleteCircularList(list);
}

void func2()
{
	CircularList	*list;
	CircularNode	node;

	/* circular list 생성 */
	list = createCircularList();

	/* 0~4 생성 */
	node.data = 10;
	addCLElement(list, 0, node);
	node.data = 11;
	addCLElement(list, 1, node);
	node.data = 12;
	addCLElement(list, 2, node);
	node.data = 13;
	addCLElement(list, 3, node);
	node.data = 14;
	addCLElement(list, 4, node);

	for (int i = 0; i < 34; i++)
	{
		if (i % getCircularListLength(list) == 0 && i != 0)
			printf("\n");
		printf("%d ", getCLElement(list, i % getCircularListLength(list))->data);
	}
	deleteCircularList(list);
}

int main(void)
{
	func1();
	func2();
	// system("leaks a.out");
	return (0);
}
