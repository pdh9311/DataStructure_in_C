#include "linkeddeque.h"

void defaultTree(BST **pBST) {
	BSTNode rootNode;
	BSTNode node;

	rootNode.key = 30;
	*pBST = makeBST(rootNode);

	node.key = 20;	insertNodeBST(*pBST, node);
	node.key = 10;	insertNodeBST(*pBST, node);
	node.key = 6;	insertNodeBST(*pBST, node);
	node.key = 14;	insertNodeBST(*pBST, node);
	node.key = 24;	insertNodeBST(*pBST, node);
	node.key = 22;	insertNodeBST(*pBST, node);

	node.key = 40;	insertNodeBST(*pBST, node);
	node.key = 34;	insertNodeBST(*pBST, node);
	node.key = 46;	insertNodeBST(*pBST, node);
}

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
	BSTNode node;
	int input;

	while (1) {
		printf("| 0: 종료\t| 1: default\t| 2: create\t|\n");
		printf("| 3: insert\t| 4: delete\t| 5: clear\t|\n");
		printf("| 6: 전위순회\t| 7: 중위순회\t| 8: 후위순회\t|\n >> ");
		scanf("%d", &input); fflush(stdin);
		switch(input) {
			case 0:
				exit(0);
			case 1:
				if (pBST != NULL) {
					printf("already create!\n");
					break ;
				}
				defaultTree(&pBST);
				printBinTree(pBST);
				break ;
			case 2:
				if (pBST != NULL) {
					printf("already create!\n");
					break;
				}
				printf("root key input > ");
				scanf("%d", &node.key); fflush(stdin);
				pBST = makeBST(node);
				printBinTree(pBST);
				break ;
			case 3:
				printf("insert key input > ");
				scanf("%d", &node.key); fflush(stdin);
				insertNodeBST(pBST, node);
				printBinTree(pBST);
				break ;
			case 4:
				printf("delete key input > ");
				scanf("%d", &node.key); fflush(stdin);
				deleteNodeBST(pBST, node);
				printBinTree(pBST);
				break ;
			case 5:
				deleteBinTree(pBST);
				pBST = NULL;
				break ;
			case 6:
				if (pBST == NULL) {
					printf("please create!\n");
					break;
				}
				preorderTraversal(pBST->pRootNode);
				break ;
			case 7:
				if (pBST == NULL) {
					printf("please create!\n");
					break;
				}
				inorderTraversal(pBST->pRootNode);
				break ;
			case 8:
				if (pBST == NULL) {
					printf("please create!\n");
					break;
				}
				postorderTraversal(pBST->pRootNode);
				break ;
		}
		printf("\n\n");
	}
	return (0);
}

/*
		        30
		   /         \
		  20          40
		/   \       /   \
	   10    24    34    46
	  / \   /
	 6  14 22
*/
/*
int main(void) {
	BST *pBST = NULL;
	BSTNode rootNode;
	BSTNode node;
	int input;

	rootNode.key = 30;
	pBST = makeBST(rootNode);

	node.key = 20;
	insertNodeBST(pBST, node);
	node.key = 10;
	insertNodeBST(pBST, node);
	node.key = 6;
	insertNodeBST(pBST, node);
	node.key = 14;
	insertNodeBST(pBST, node);
	node.key = 24;
	insertNodeBST(pBST, node);
	node.key = 22;
	insertNodeBST(pBST, node);
	node.key = 40;
	insertNodeBST(pBST, node);
	node.key = 34;
	insertNodeBST(pBST, node);
	node.key = 46;
	insertNodeBST(pBST, node);
	printBinTree(pBST);
	printf("\n\n");


	node.key = 3;
	insertNodeBST(pBST, node);
	printBinTree(pBST);
	printf("\n\n");

	node.key = 4;
	insertNodeBST(pBST, node);
	printBinTree(pBST);
	printf("\n\n");

	node.key = 5;
	insertNodeBST(pBST, node);
	printBinTree(pBST);
	printf("\n\n");

	node.key = 7;
	insertNodeBST(pBST, node);
	printBinTree(pBST);
	printf("\n\n");

	node.key = 10;
	deleteNodeBST(pBST, node);
	printBinTree(pBST);
	printf("\n\n");

	// preorderTraversal(pBST->pRootNode);
	// printf("\n");
	// inorderTraversal(pBST->pRootNode);
	// printf("\n");
	// postorderTraversal(pBST->pRootNode);
	// printf("\n");
	deleteBinTree(pBST);

	// system("leaks a.out");
	return (0);
}
*/
