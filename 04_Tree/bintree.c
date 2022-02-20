#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode) {
	BinTree *binTree;

	binTree = (BinTree *)malloc(sizeof(BinTree));
	if (binTree == NULL)
		return (NULL);
	binTree->pRootNode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (binTree->pRootNode == NULL) {
		free(binTree);
		binTree = NULL;
		return (NULL);
	}
	binTree->pRootNode->data = rootNode.data;
	binTree->pRootNode->pLeftChild = NULL;
	binTree->pRootNode->pRightChild = NULL;
	return (binTree);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree) {
	if (pBinTree == NULL)
		return (NULL);
	return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element) {
	BinTreeNode *addNode;
	BinTreeNode *tmp;

	if (pParentNode == NULL)
		return (NULL);
	addNode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (addNode == NULL)
		return (NULL);
	addNode->data = element.data;
	addNode->pRightChild = NULL;
	tmp = pParentNode->pLeftChild;
	addNode->pLeftChild = tmp;
	pParentNode->pLeftChild = addNode;
	return (addNode);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element) {
	BinTreeNode *addNode;
	BinTreeNode *tmp;

	if (pParentNode == NULL)
		return (NULL);
	addNode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (addNode == NULL)
		return (NULL);
	addNode->data = element.data;
	addNode->pLeftChild = NULL;
	tmp = pParentNode->pRightChild;
	addNode->pRightChild = tmp;
	pParentNode->pRightChild = addNode;
	return (addNode);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode) {
	if (pNode == NULL)
		return(NULL);
	return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode) {
	if (pNode == NULL)
		return(NULL);
	return (pNode->pRightChild);
}

void deleteBinTree(BinTree* pBinTree) {
	deleteBinTreeNode(pBinTree->pRootNode);
	free(pBinTree);
}

void deleteBinTreeNode(BinTreeNode* pNode) {
	if(pNode->pLeftChild == NULL && pNode->pRightChild == NULL) {
		free(pNode);
		return ;
	}
	if (pNode->pLeftChild != NULL)
		deleteBinTreeNode(pNode->pLeftChild);
	if (pNode->pRightChild != NULL)
		deleteBinTreeNode(pNode->pRightChild);
	pNode->pLeftChild = NULL;
	pNode->pRightChild = NULL;
	free(pNode);
}

void preorderTraversal(BinTreeNode *pNode) {
	if (pNode->pLeftChild == NULL && pNode->pRightChild == NULL) {
		printf("%c ", pNode->data);
		return ;
	}
	printf("%c ", pNode->data);
	if (pNode->pLeftChild != NULL)
		preorderTraversal(pNode->pLeftChild);
	if (pNode->pRightChild != NULL)
		preorderTraversal(pNode->pRightChild);
}

void inorderTraversal(BinTreeNode *pNode) {
	if (pNode->pLeftChild == NULL && pNode->pRightChild == NULL) {
		printf("%c ", pNode->data);
		return ;
	}
	if (pNode->pLeftChild != NULL)
		inorderTraversal(pNode->pLeftChild);
	printf("%c ", pNode->data);
	if (pNode->pRightChild != NULL)
		inorderTraversal(pNode->pRightChild);
}

void postorderTraversal(BinTreeNode *pNode) {
	if (pNode->pLeftChild == NULL && pNode->pRightChild == NULL) {
		printf("%c ", pNode->data);
		return ;
	}
	if (pNode->pLeftChild != NULL)
		postorderTraversal(pNode->pLeftChild);
	if (pNode->pRightChild != NULL)
		postorderTraversal(pNode->pRightChild);
	printf("%c ", pNode->data);
}
