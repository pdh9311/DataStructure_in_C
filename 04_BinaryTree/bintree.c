#include "bintree.h"
#include "linkeddeque.h"

BinTree	*makeBinTree(BinTreeNode rootNode)
{
	BinTree		*pBinTree;
	BinTreeNode	*pRootNode;

	pBinTree = malloc(sizeof(BinTree));
	if (pBinTree == NULL)
		return (NULL);
	pRootNode = malloc(sizeof(BinTreeNode));
	if (pRootNode == NULL)
	{
		free(pBinTree);
		return (NULL);
	}
	*pRootNode = rootNode;
	pRootNode->pLeftChild = NULL;
	pRootNode->pRightChild = NULL;
	pBinTree->pRootNode = pRootNode;
	return (pBinTree);
}

BinTreeNode	*getRootNodeBT(BinTree *pBinTree)
{
	if (pBinTree != NULL)
		return (pBinTree->pRootNode);
	return (NULL);
}

BinTreeNode	*insertLeftChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element)
{
	BinTreeNode	*pChildNode;

	if (pParentNode->pLeftChild != NULL)
		return (NULL);
	pChildNode = malloc(sizeof(BinTreeNode));
	if (pChildNode == NULL)
		return (NULL);
	*pChildNode = element;
	pChildNode->pLeftChild = NULL;
	pChildNode->pRightChild = NULL;
	pParentNode->pLeftChild = pChildNode;
	return (pChildNode);
}

BinTreeNode	*insertRightChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element)
{
	BinTreeNode	*pChildNode;

	if (pParentNode->pRightChild != NULL)
		return (NULL);
	pChildNode = malloc(sizeof(BinTreeNode));
	if (pChildNode == NULL)
		return (NULL);
	*pChildNode = element;
	pChildNode->pLeftChild = NULL;
	pChildNode->pRightChild = NULL;
	pParentNode->pRightChild = pChildNode;
	return (pChildNode);
}

BinTreeNode	*getLeftChildNodeBT(BinTreeNode *pNode)
{
	if (pNode == NULL)
		return (NULL);
	return (pNode->pLeftChild);
}

BinTreeNode	*getRightChildNodeBT(BinTreeNode *pNode)
{
	if (pNode == NULL)
		return (NULL);
	return (pNode->pRightChild);
}

void	deleteBinTree(BinTree *pBinTree)
{
	deleteBinTreeNode(getRootNodeBT(pBinTree));
	free(pBinTree);
}

void	deleteBinTreeNode(BinTreeNode *pNode)
{
	if (pNode == NULL)
		return ;
	deleteBinTreeNode(pNode->pLeftChild);
	deleteBinTreeNode(pNode->pRightChild);
	free(pNode);
}

void	preorderTraversalBinTree(BinTreeNode *pParentNode)
{
	if (pParentNode == NULL)
		return ;
	printf("%c ", pParentNode->data);
	preorderTraversalBinTree(pParentNode->pLeftChild);
	preorderTraversalBinTree(pParentNode->pRightChild);
}

void	preorderTraversalBinTreeIter(BinTreeNode *pParentNode)
{
	LinkedDeque	*pDeque;
	DequeNode	pDequeNode;
	DequeNode	*pCurNode;
	BinTreeNode	pBinTreeNode;

	if (pParentNode == NULL)
		return ;
	pDeque = createLinkedDeque();
	pBinTreeNode = *pParentNode;
	pDequeNode.pNode = pBinTreeNode;
	insertRearLD(pDeque, pDequeNode);
	while (isLinkedDequeEmpty(pDeque) != TRUE)
	{
		pCurNode = peekRearLD(pDeque);
		if (pCurNode->pNode.visited == 0)
			printf("%c ", pCurNode->pNode.data);
		if (2 - (!pCurNode->pNode.pLeftChild + !pCurNode->pNode.pRightChild) == pCurNode->pNode.visited)
			free(deleteRearLD(pDeque));
		else if (pCurNode->pNode.visited == 0 && pCurNode->pNode.pLeftChild)
		{
			pCurNode->pNode.visited++;
			pDequeNode.pNode = *pCurNode->pNode.pLeftChild;
			insertRearLD(pDeque, pDequeNode);
		}
		else
		{
			pCurNode->pNode.visited++;
			pDequeNode.pNode = *pCurNode->pNode.pRightChild;
			insertRearLD(pDeque, pDequeNode);
		}
	}
	deleteLinkedDeque(pDeque);
}

void	inorderTraversalBinTree(BinTreeNode *pParentNode)
{

	if (pParentNode == NULL)
		return ;
	inorderTraversalBinTree(pParentNode->pLeftChild);
	printf("%c ", pParentNode->data);
	inorderTraversalBinTree(pParentNode->pRightChild);
}

void	inorderTraversalBinTreeIter(BinTreeNode *pParentNode)
{
	LinkedDeque	*pDeque;
	DequeNode	pDequeNode;
	DequeNode	*pCurNode;
	BinTreeNode	pBinTreeNode;

	if (pParentNode == NULL)
		return ;
	pDeque = createLinkedDeque();
	pBinTreeNode = *pParentNode;
	pDequeNode.pNode = pBinTreeNode;
	insertRearLD(pDeque, pDequeNode);
	while (isLinkedDequeEmpty(pDeque) != TRUE)
	{
		pCurNode = peekRearLD(pDeque);
		if ((pCurNode->pNode.pLeftChild && pCurNode->pNode.visited == 1)
			|| (!pCurNode->pNode.pLeftChild && pCurNode->pNode.visited == 0))
			printf("%c ", pCurNode->pNode.data);
		if (2 - (!pCurNode->pNode.pLeftChild + !pCurNode->pNode.pRightChild) == pCurNode->pNode.visited)
			free(deleteRearLD(pDeque));
		else if (pCurNode->pNode.visited == 0 && pCurNode->pNode.pLeftChild)
		{
			pCurNode->pNode.visited++;
			pDequeNode.pNode = *pCurNode->pNode.pLeftChild;
			insertRearLD(pDeque, pDequeNode);
		}
		else
		{
			pCurNode->pNode.visited++;
			pDequeNode.pNode = *pCurNode->pNode.pRightChild;
			insertRearLD(pDeque, pDequeNode);
		}
	}
	deleteLinkedDeque(pDeque);
}

void	postorderTraversalBinTree(BinTreeNode *pParentNode)
{
	if (pParentNode == NULL)
		return ;
	postorderTraversalBinTree(pParentNode->pLeftChild);
	postorderTraversalBinTree(pParentNode->pRightChild);
	printf("%c ", pParentNode->data);
}

void	postorderTraversalBinTreeIter(BinTreeNode *pParentNode)
{
	LinkedDeque	*pDeque;
	DequeNode	pDequeNode;
	DequeNode	*pCurNode;
	BinTreeNode	pBinTreeNode;

	if (pParentNode == NULL)
		return ;
	pDeque = createLinkedDeque();
	pBinTreeNode = *pParentNode;
	pDequeNode.pNode = pBinTreeNode;
	insertRearLD(pDeque, pDequeNode);
	while (isLinkedDequeEmpty(pDeque) != TRUE)
	{
		pCurNode = peekRearLD(pDeque);
		if (2 - (!pCurNode->pNode.pLeftChild + !pCurNode->pNode.pRightChild) == pCurNode->pNode.visited)
		{
			printf("%c ", pCurNode->pNode.data);
			free(deleteRearLD(pDeque));
		}
		else if (pCurNode->pNode.visited == 0 && pCurNode->pNode.pLeftChild)
		{
			pCurNode->pNode.visited++;
			pDequeNode.pNode = *pCurNode->pNode.pLeftChild;
			insertRearLD(pDeque, pDequeNode);
		}
		else
		{
			pCurNode->pNode.visited++;
			pDequeNode.pNode = *pCurNode->pNode.pRightChild;
			insertRearLD(pDeque, pDequeNode);
		}
	}
	deleteLinkedDeque(pDeque);
}

static BinTreeNode	*preorderSearch(BinTreeNode *pParentNode, char c)
{
	BinTreeNode	*pReturnNode = NULL;

	if (pParentNode == NULL)
		return (NULL);
	if (pParentNode->data == c)
		pReturnNode = pParentNode;
	if (pReturnNode == NULL)
		pReturnNode = preorderSearch(pParentNode->pLeftChild, c);
	if (pReturnNode == NULL)
		pReturnNode = preorderSearch(pParentNode->pRightChild, c);
	return (pReturnNode);
}

BinTreeNode	*searchBinTreeNode(BinTree *pBinTree, char c)
{
	return (preorderSearch(getRootNodeBT(pBinTree), c));
}

static void getMaxLevelRecSub(BinTreeNode *pParentNode, int *current, int *max)
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

int getMaxLevelRec(BinTree *pBinTree)
{
	int	current = 1;
	int	max = 0;

	getMaxLevelRecSub(pBinTree->pRootNode, &current, &max);
	return (max);
}

int	getMaxLevel(BinTree *pBinTree)
{
	int	maxLevel = 0;
	int	currentLevel = 0;
	LinkedDeque	*pDeque;
	DequeNode	pDequeNode;
	DequeNode	*pCurNode;
	BinTreeNode	pBinTreeNode;

	if (pBinTree->pRootNode == NULL)
		return (0);
	pDeque = createLinkedDeque();
	pBinTreeNode = *pBinTree->pRootNode;
	pDequeNode.pNode = pBinTreeNode;
	insertRearLD(pDeque, pDequeNode);
	while (isLinkedDequeEmpty(pDeque) != TRUE)
	{
		pCurNode = peekRearLD(pDeque);
		if (pCurNode->pNode.visited == 0)
			currentLevel++;
		if (2 - (!pCurNode->pNode.pLeftChild + !pCurNode->pNode.pRightChild) == pCurNode->pNode.visited)
		{
			if (currentLevel > maxLevel)
				maxLevel = currentLevel;
			currentLevel--;
			free(deleteRearLD(pDeque));
		}
		else if (pCurNode->pNode.visited == 0 && pCurNode->pNode.pLeftChild)
		{
			pCurNode->pNode.visited++;
			pDequeNode.pNode = *pCurNode->pNode.pLeftChild;
			insertRearLD(pDeque, pDequeNode);
		}
		else
		{
			pCurNode->pNode.visited++;
			pDequeNode.pNode = *pCurNode->pNode.pRightChild;
			insertRearLD(pDeque, pDequeNode);
		}
	}
	deleteLinkedDeque(pDeque);
	return (maxLevel);
}

int	pow(int	d)
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

void	printBinTree(BinTree *pBinTree)
{
	LinkedDeque	*pDeque;
	DequeNode	pDequeNode;
	DequeNode	*pCurNode;
	BinTreeNode	pBinTreeNode;
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
	printf("%c", pBinTreeNode.data);
	printCount++;
	while (currentLevel < maxLevel && isLinkedDequeEmpty(pDeque) == FALSE)
	{
		if (printCount == pow(currentLevel))
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
				printf("%c", pCurNode->pNode.pLeftChild->data);
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
				printf("%c", pCurNode->pNode.pRightChild->data);
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
