# include "linkeddeque.h"

BST* makeBST(BSTNode rootNode) {
	BST *pBST = NULL;

	pBST = (BST *)malloc(sizeof(BST));
	if (pBST == NULL)
		return (NULL);
	pBST->pRootNode = (BSTNode *)malloc(sizeof(BSTNode));
	if (pBST->pRootNode == NULL) {
		free(pBST);
		pBST = NULL;
		return (NULL);
	}
	pBST->pRootNode->key = rootNode.key;
	pBST->pRootNode->pLeftChild = NULL;
	pBST->pRootNode->pRightChild = NULL;
	return (pBST);
}

BSTNode* initBSTNode(int key) {
	BSTNode *newNode = NULL;

	newNode = (BSTNode *)malloc(sizeof(BSTNode));
	if (newNode == NULL)
		return (NULL);
	newNode->key = key;
	newNode->pLeftChild = NULL;
	newNode->pRightChild = NULL;
	return (newNode);
}

BSTNode* getRootNodeBST(BST* pBST) {
	if (pBST == NULL)
		return (NULL);
	return (pBST->pRootNode);
}

BSTNode* insertLeftChildNodeBST(BSTNode* pParentNode, BSTNode element) {
	BSTNode *addNode = NULL;

	if (pParentNode == NULL || pParentNode->pLeftChild != NULL)
		return (NULL);
	addNode = (BSTNode *)malloc(sizeof(BSTNode));
	if (addNode == NULL)
		return (NULL);
	addNode->key  = element.key;
	addNode->pLeftChild = NULL;
	addNode->pRightChild = NULL;
	pParentNode->pLeftChild = addNode;
	return (addNode);
}

BSTNode* insertRightChildNodeBST(BSTNode* pParentNode, BSTNode element) {
	BSTNode *addNode = NULL;

	if (pParentNode == NULL || pParentNode->pRightChild != NULL)
		return (NULL);
	addNode = (BSTNode *)malloc(sizeof(BSTNode));
	if (addNode == NULL)
		return (NULL);
	addNode->key = element.key;
	addNode->pLeftChild = NULL;
	addNode->pRightChild = NULL;
	pParentNode->pRightChild = addNode;
	return (addNode);
}

BSTNode* getLeftChildNodeBST(BSTNode* pNode) {
	if (pNode == NULL)
		return(NULL);
	return (pNode->pLeftChild);
}

BSTNode* getRightChildNodeBST(BSTNode* pNode) {
	if (pNode == NULL)
		return(NULL);
	return (pNode->pRightChild);
}

void deleteBinTree(BST* pBST) {
	if (pBST == NULL) {
		printf("please create!");
		return ;
	}
	deleteBinTreeNode(pBST->pRootNode);
	free(pBST);
}

void deleteBinTreeNode(BSTNode* pNode) {
	if(pNode == NULL)
		return ;
	deleteBinTreeNode(pNode->pLeftChild);
	deleteBinTreeNode(pNode->pRightChild);
	free(pNode);
}

void preorderTraversal(BSTNode *pNode) {
	if (pNode == NULL)
		return ;
	printf("%d ", pNode->key);
	preorderTraversal(pNode->pLeftChild);
	preorderTraversal(pNode->pRightChild);
}

void inorderTraversal(BSTNode *pNode) {
	if (pNode == NULL)
		return ;
	inorderTraversal(pNode->pLeftChild);
	printf("%d ", pNode->key);
	inorderTraversal(pNode->pRightChild);
}

void postorderTraversal(BSTNode *pNode) {
	if (pNode == NULL)
		return ;
	postorderTraversal(pNode->pLeftChild);
	postorderTraversal(pNode->pRightChild);
	printf("%d ", pNode->key);
}

static BSTNode* insertPositionBST(BSTNode *pParentNode, int position, BSTNode element) {
	BSTNode *addNode = NULL;

	addNode = initBSTNode(element.key);
	if (addNode == NULL)
		return (NULL);
	if (position == LEFT) {
		pParentNode->pLeftChild = addNode;
	} else if (position == RIGHT) {
		pParentNode->pRightChild = addNode;
	}
	return (addNode);
}


BSTNode* insertNodeBST(BST *pBST, BSTNode element) {
	BSTNode *node = NULL;
	BSTNode *parent = NULL;

	if (pBST == NULL) {
		printf("please create!\n");
		return (NULL);
	}
	node = pBST->pRootNode;
	while (1) {
		parent = node;
		if (node->key == element.key) {
			return (NULL);
		} else if (node->key > element.key) {
			node = node->pLeftChild;
			if (node == NULL)
				return (insertPositionBST(parent, LEFT, element));
		} else {
			node = node->pRightChild;
			if (node == NULL)
				return (insertPositionBST(parent, RIGHT, element));
		}
	}
	return (NULL);
}

static BSTNode *changeNode(BSTNode *node) {
	BSTNode *ret = NULL;
	BSTNode *parent = NULL;

	while (1) {
		if (node->pLeftChild == NULL)
			break;
		parent = node;
		node = node->pLeftChild;
	}
	ret = node;
	if (parent != NULL && node != NULL) {
		parent->pLeftChild = node->pRightChild;
		ret->pRightChild = NULL;
	}
	return (ret);
}

static void deletePosition(BSTNode *parent, BSTNode *node, int position) {
	BSTNode *tmp = NULL;

	if (node->pLeftChild == NULL && node->pRightChild == NULL) {
		if (position == LEFT)
			parent->pLeftChild = NULL;
		else
			parent->pRightChild = NULL;
		free(node);
	} else if (node->pLeftChild == NULL) {
		tmp = node->pRightChild;
		if (position == LEFT)
			parent->pLeftChild = tmp;
		else
			parent->pRightChild = tmp;
		free(node);
	} else if (node->pRightChild == NULL) {
		tmp = node->pLeftChild;
		if (position == LEFT)
			parent->pLeftChild = tmp;
		else
			parent->pRightChild = tmp;
		free(node);
	} else {
		tmp = changeNode(node->pRightChild);
		if (tmp->key != node->pRightChild->key)
			tmp->pRightChild = node->pRightChild;
		tmp->pLeftChild = node->pLeftChild;
		parent->pLeftChild = tmp;
		free(node);
	}
}


void deleteNodeBST(BST *pBST, BSTNode element) {
	BSTNode *parent = NULL;
	BSTNode *node = NULL;

	if (pBST == NULL) {
		printf("please create!\n");
		return ;
	}
	node = pBST->pRootNode;
	while (1) {
		parent = node;
		if (node->key > element.key) {
			node = node->pLeftChild;
			if (node == NULL) {
				printf("not found!\n");
				return ;
			}
			if (node->key == element.key) {
				deletePosition(parent, node, LEFT);	// parent의 왼쪽 node가 삭제 될거다.
				break ;
			}
		} else {
			node = node->pRightChild;
			if (node == NULL) {
				printf("not found!\n");
				return ;
			}
			if (node->key == element.key) {
				deletePosition(parent, node, RIGHT);	// parent의 오른쪽 node가 삭제 될거다.
				break ;
			}
		}
	}
}

////////////////////// print start //////////////////////
static void getMaxLevelRecSub(BSTNode *pParentNode, int *current, int *max)
{
	if (pParentNode == NULL)
	{
		*current -= 1;
		return ;
	}
	if (*current > *max)
		*max = *current;
	*current = *current + 1;
	getMaxLevelRecSub(pParentNode->pLeftChild, current, max);
	*current = *current + 1;
	getMaxLevelRecSub(pParentNode->pRightChild, current, max);
	*current -= 1;
}

int getMaxLevel(BST *pBinTree)
{
	int	current = 1;
	int	max = 0;

	getMaxLevelRecSub(pBinTree->pRootNode, &current, &max);
	return (max);
}

static int	getPrintCount(int	d)
{
	int	i;

	i = 1;
	while (d--)
		i *= 2;
	return (i);
}

static void	printBlank(int c)
{
	while (c-- > 0)
		printf(" ");
}

void	printBinTree(BST *pBinTree)
{
	LinkedDeque	*pDeque;
	DequeNode	pDequeNode;
	DequeNode	*pCurNode;
	BSTNode		pBinTreeNode;
	int			maxLevel;
	int			tmp;
	int			maxSpace;
	int			currentLevel = 0;
	int			printCount = 0;

	if (pBinTree == NULL)
		return ;
	maxLevel = getMaxLevel(pBinTree);
	maxSpace = 1;
	tmp = maxLevel;
	while (--tmp > 1)
		maxSpace = maxSpace * 2 + 1;
	pDeque = createLinkedDeque();
	pBinTreeNode = *pBinTree->pRootNode;
	pDequeNode.pNode = pBinTreeNode;
	insertRearLD(pDeque, pDequeNode);
	printBlank(maxSpace);
	printf("%d", pBinTreeNode.key);
	printCount++;
	while (currentLevel < maxLevel && isLinkedDequeEmpty(pDeque) == FALSE)
	{
		if (printCount == getPrintCount(currentLevel))
		{
			printf("\n");
			maxSpace /= 2;
			printBlank(maxSpace);
			printCount = 0;
			currentLevel++;
		}
		else
		{
			pCurNode = peekFrontLD(pDeque);
			if (pCurNode->pNode.pLeftChild)
			{
				printf("%d", pCurNode->pNode.pLeftChild->key);
				printBlank(maxSpace * 2 + 1);
				pDequeNode.pNode = *pCurNode->pNode.pLeftChild;
				insertRearLD(pDeque, pDequeNode);
			}
			else
			{
				printf("_");
				printBlank(maxSpace * 2 + 1);
				pDequeNode.pNode.pLeftChild = NULL;
				pDequeNode.pNode.pRightChild = NULL;
				insertRearLD(pDeque, pDequeNode);
			}
			printCount++;
			if (pCurNode->pNode.pRightChild)
			{
				printf("%d", pCurNode->pNode.pRightChild->key);
				printBlank(maxSpace * 2 + 1);
				pDequeNode.pNode = *pCurNode->pNode.pRightChild;
				insertRearLD(pDeque, pDequeNode);
			}
			else
			{
				printf("_");
				printBlank(maxSpace * 2 + 1);
				pDequeNode.pNode.pLeftChild = NULL;
				pDequeNode.pNode.pRightChild = NULL;
				insertRearLD(pDeque, pDequeNode);
			}
			printCount++;
			free(deleteFrontLD(pDeque));
		}
	}
	deleteLinkedDeque(pDeque);
}
///////////////////// print end /////////////////////
