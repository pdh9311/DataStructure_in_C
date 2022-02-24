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

	if (pParentNode == NULL || pParentNode->pLeftChild != NULL)
		return (NULL);
	addNode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (addNode == NULL)
		return (NULL);
	addNode->data = element.data;
	addNode->pLeftChild = NULL;	
	addNode->pRightChild = NULL;
	pParentNode->pLeftChild = addNode;
	return (addNode);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element) {
	BinTreeNode *addNode;

	if (pParentNode == NULL || pParentNode->pRightChild != NULL)
		return (NULL);
	addNode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (addNode == NULL)
		return (NULL);
	addNode->data = element.data;
	addNode->pLeftChild = NULL;
	addNode->pRightChild = NULL;
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
	if(pNode == NULL )
		return ;
	deleteBinTreeNode(pNode->pLeftChild);
	deleteBinTreeNode(pNode->pRightChild);
	free(pNode);
}

void preorderTraversal(BinTreeNode *pNode) {
	if (pNode == NULL)
		return ;
	printf("%c ", pNode->data);
	preorderTraversal(pNode->pLeftChild);
	preorderTraversal(pNode->pRightChild);
}

void inorderTraversal(BinTreeNode *pNode) {
	if (pNode == NULL)
		return ;
	inorderTraversal(pNode->pLeftChild);
	printf("%c ", pNode->data);
	inorderTraversal(pNode->pRightChild);
}

void postorderTraversal(BinTreeNode *pNode) {
	if (pNode == NULL)
		return ;
	postorderTraversal(pNode->pLeftChild);
	postorderTraversal(pNode->pRightChild);
	printf("%c ", pNode->data);
}
