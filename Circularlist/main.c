#include "circularlist.h"

void	func1()
{
	CircularList	*clist;
	CircularNode	node;

	/* circular list 생성 */
	clist = createCircularList();

	/* 1개 생성 후 제거 */
	node.data = 10;
	addCLElement(clist, 0, node);
	displayCircularList(clist);

	removeCLElement(clist, 0);
	displayCircularList(clist);

	/* 0~4 생성 */
	node.data = 10;
	addCLElement(clist, 0, node);
	displayCircularList(clist);

	node.data = 11;
	addCLElement(clist, 1, node);
	displayCircularList(clist);

	node.data = 12;
	addCLElement(clist, 2, node);
	displayCircularList(clist);

	node.data = 13;
	addCLElement(clist, 3, node);
	displayCircularList(clist);

	node.data = 14;
	addCLElement(clist, 4, node);
	displayCircularList(clist);

	/* 마지막 노드 제거 */
	removeCLElement(clist, 4);
	displayCircularList(clist);

	/* 중간 노드 제거 */
	removeCLElement(clist, 2);
	displayCircularList(clist);

	/* 첫 번째 노드 제거 */
	removeCLElement(clist, 0);
	displayCircularList(clist);

	/* 전체 노드 제거 */
	clearCircularList(clist);
	displayCircularList(clist);

	/* 리스트 해제 */
	deleteCircularList(clist);
}

void func2()
{
	CircularList	*clist;
	CircularNode	node;

	/* circular list 생성 */
	clist = createCircularList();

	/* 0~4 생성 */
	node.data = 10;
	addCLElement(clist, 0, node);
	node.data = 11;
	addCLElement(clist, 1, node);
	node.data = 12;
	addCLElement(clist, 2, node);
	node.data = 13;
	addCLElement(clist, 3, node);
	node.data = 14;
	addCLElement(clist, 4, node);

	for (int i = 0; i < 34; i++)
	{
		if (i % getCircularListLength(clist) == 0 && i != 0)
			printf("\n");
		printf("%d ", getCLElement(clist, i % getCircularListLength(clist))->data);
	}
	deleteCircularList(clist);
}

int main(void)
{
	func1();
	func2();
	// system("leaks a.out");
	return (0);
}
