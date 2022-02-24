#include "linkeddeque.h"

/*
		        30
		   /         \
		  20          40
		/   \       /   \
	   10    24    34    46
	  / \   /
	 6  14 22
*/
int main(void) {
	BST *pBST = NULL;
	BSTNode rootNode;
	BSTNode node;

	rootNode.key = 30;
	pBST = makeBST(rootNode);

	node.key = 20;	insertNodeBST(pBST, node);
	node.key = 10;	insertNodeBST(pBST, node);
	node.key = 6;	insertNodeBST(pBST, node);
	node.key = 14;	insertNodeBST(pBST, node);
	node.key = 24;	insertNodeBST(pBST, node);
	node.key = 22;	insertNodeBST(pBST, node);

	node.key = 40;	insertNodeBST(pBST, node);
	node.key = 34;	insertNodeBST(pBST, node);
	node.key = 46;	insertNodeBST(pBST, node);

	printBinTree(pBST);	printf("\n\n");

	node.key = 20;	deleteNodeBST(pBST, node);
	printBinTree(pBST);	printf("\n\n");

	node.key = 28;	insertNodeBST(pBST, node);
	printBinTree(pBST);	printf("\n\n");

	node.key = 24;	deleteNodeBST(pBST, node);
	printBinTree(pBST);	printf("\n\n");

	preorderTraversal(pBST->pRootNode);
	printf("\n");
	inorderTraversal(pBST->pRootNode);
	printf("\n");
	postorderTraversal(pBST->pRootNode);
	printf("\n");
	deleteBinTree(pBST);
	system("leaks a.out");
	return (0);
}
