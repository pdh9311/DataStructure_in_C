/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binserchtree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seseo <seseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:07:31 by seseo             #+#    #+#             */
/*   Updated: 2022/02/27 17:46:26 by seseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binsearchtree.h"
#include "linkeddeque.h"

BST	*makeBST()
{
	BST	*pBST;

	pBST = malloc(sizeof(BST));
	if (pBST == NULL)
		return (NULL);
	pBST->pRootNode = NULL;
	return (pBST);
}

BSTNode	*searchBST(BST *pBST, int key)
{
	BSTNode	*pReturnNode;

	pReturnNode = pBST->pRootNode;
	while (pReturnNode != NULL)
	{
		if (pReturnNode->key == key)
			break ;
		else if (key < pReturnNode->key)
			pReturnNode = pReturnNode->pLeftChild;
		else
			pReturnNode = pReturnNode->pRightChild;
	}
	return (pReturnNode);
}

int	insertBSTNode(BST *pBST, BSTNode element)
{
	BSTNode	*pNode;
	BSTNode	*pPreNode;

	if (searchBST(pBST, element.key))
		return (FALSE);
	pNode = pBST->pRootNode;
	if (pNode == NULL)
	{
		if (insertRootNode(pBST, element))
			return (TRUE);
		return (FALSE);
	}
	while (pNode != NULL)
	{
		pPreNode = pNode;
		if (pNode->key == element.key)
			break ;
		else if (element.key < pNode->key)
			pNode = pNode->pLeftChild;
		else
			pNode = pNode->pRightChild;
	}
	if (element.key < pPreNode->key)
		insertLeftChildNodeBST(pPreNode, element);
	else
		insertRightChildNodeBST(pPreNode, element);
	return (TRUE);
}

BSTNode	*insertRootNode(BST *pBST, BSTNode element)
{
	BSTNode	*pNewNode;

	if (pBST == NULL)
		return (NULL);
	pNewNode = malloc(sizeof(BSTNode));
	if (pNewNode == NULL)
		return (NULL);
	*pNewNode = element;
	pNewNode->pLeftChild = NULL;
	pNewNode->pRightChild = NULL;
	pNewNode->visited = 0;
	pBST->pRootNode = pNewNode;
	return (pNewNode);
}

// 트리 생성시 root 주소가 무조건 있어야하므로 따로 NULL 체크 안함.
BSTNode	*insertLeftChildNodeBST(BSTNode *pParentNode, BSTNode element)
{
	BSTNode	*pChildNode;

	if (pParentNode->pLeftChild != NULL)
		return (NULL);
	pChildNode = malloc(sizeof(BSTNode));
	if (pChildNode == NULL)
		return (NULL);
	*pChildNode = element;
	pChildNode->pLeftChild = NULL;
	pChildNode->pRightChild = NULL;
	pParentNode->pLeftChild = pChildNode;
	return (pChildNode);
}

BSTNode	*insertRightChildNodeBST(BSTNode *pParentNode, BSTNode element)
{
	BSTNode	*pChildNode;

	if (pParentNode->pRightChild != NULL)
		return (NULL);
	pChildNode = malloc(sizeof(BSTNode));
	if (pChildNode == NULL)
		return (NULL);
	*pChildNode = element;
	pChildNode->pLeftChild = NULL;
	pChildNode->pRightChild = NULL;
	pParentNode->pRightChild = pChildNode;
	return (pChildNode);
}

BSTNode	*getRootNodeBST(BST *pBST)
{
	if (pBST != NULL)
		return (pBST->pRootNode);
	return (NULL);
}

// 후위 순회로 노드 삭제 or 자식 노드가 없을 경우에만 삭제?
void	deleteBSTRec(BSTNode *pNode)
{
	if (pNode == NULL)
		return ;
	deleteBSTRec(pNode->pLeftChild);
	deleteBSTRec(pNode->pRightChild);
	free(pNode);
}

// 후위 순회(Postorder Traversal)로 트리 삭제.
void	deleteBST(BST *pBST)
{
	deleteBSTRec(getRootNodeBST(pBST));
	free(pBST);
}

BSTNode	*deleteBSTNode(BST *pBST, int key)
{
	BSTNode	*pDelNode;
	BSTNode	*pParentNode;
	BSTNode	*pPredecessor;
	BSTNode	*pSuccessor;
	int		childNum;

	if (searchBST(pBST, key) == NULL)
		return (NULL);
	pDelNode = pBST->pRootNode;
	if (pBST->pRootNode->key == key)
	{
		childNum = !!(pDelNode->pLeftChild) + !!(pDelNode->pRightChild);
		switch (childNum)
		{
			case 0:
				pBST->pRootNode = NULL;

			case 1:
				if (pDelNode->pLeftChild)
					pBST->pRootNode = pDelNode->pLeftChild;
				else
					pBST->pRootNode = pDelNode->pRightChild;
				break ;

			case 2:
				pPredecessor = pDelNode->pLeftChild;
				pSuccessor = pPredecessor->pRightChild;
				if (pSuccessor == NULL)
				{
					pBST->pRootNode = pPredecessor;
					pPredecessor->pRightChild = pDelNode->pRightChild;
				}
				else
				{
					while (pSuccessor->pRightChild != NULL)
					{
						pPredecessor = pSuccessor;
						pSuccessor = pSuccessor->pRightChild;
					}
					pBST->pRootNode = pSuccessor;
					pDelNode->pLeftChild->pRightChild = pSuccessor->pLeftChild;
					pSuccessor->pLeftChild = pDelNode->pLeftChild;
					pSuccessor->pRightChild = pDelNode->pRightChild;
				}
				break ;
		}
	}
	else
	{
		pDelNode = pBST->pRootNode;
		while (key != pDelNode->key)
		{
			pParentNode = pDelNode;
			if (key < pDelNode->key)
				pDelNode = pDelNode->pLeftChild;
			else
				pDelNode = pDelNode->pRightChild;
		}
		childNum = !!(pDelNode->pLeftChild) + !!(pDelNode->pRightChild);
		switch (childNum)
		{
			case 0:
				if (pParentNode->pLeftChild == pDelNode)
					pParentNode->pLeftChild = NULL;
				else
					pParentNode->pRightChild = NULL;
				break ;

			case 1:
				if (pParentNode->pLeftChild == pDelNode)
				{
					if (pDelNode->pLeftChild)
						pParentNode->pLeftChild = pDelNode->pLeftChild;
					else
						pParentNode->pLeftChild = pDelNode->pRightChild;
				}
				else
				{
					if (pDelNode->pLeftChild)
						pParentNode->pRightChild = pDelNode->pLeftChild;
					else
						pParentNode->pRightChild = pDelNode->pRightChild;
				}
				break ;

			case 2:
				pPredecessor = pDelNode->pLeftChild;
				pSuccessor = pPredecessor->pRightChild;
				if (pSuccessor == NULL)
				{
					if (pParentNode->pLeftChild == pDelNode)
						pParentNode->pLeftChild = pPredecessor;
					else
						pParentNode->pRightChild = pPredecessor;
					pPredecessor->pRightChild = pDelNode->pRightChild;
				}
				else
				{
					while (pSuccessor->pRightChild != NULL)
					{
						pPredecessor = pSuccessor;
						pSuccessor = pSuccessor->pRightChild;
					}
					if (pParentNode->pLeftChild == pDelNode)
						pParentNode->pLeftChild = pSuccessor;
					else
						pParentNode->pRightChild = pSuccessor;
					pDelNode->pLeftChild->pRightChild = pSuccessor->pLeftChild;
					pSuccessor->pLeftChild = pDelNode->pLeftChild;
					pSuccessor->pRightChild = pDelNode->pRightChild;
				}
				break ;
		}
	}
	return (pDelNode);
}

void	preorderTraversalBST(BSTNode *pParentNode)
{
	if (pParentNode == NULL)
		return ;
	printf("%d ", pParentNode->key);
	preorderTraversalBST(pParentNode->pLeftChild);
	preorderTraversalBST(pParentNode->pRightChild);
}

void	inorderTraversalBST(BSTNode *pParentNode)
{

	if (pParentNode == NULL)
		return ;
	inorderTraversalBST(pParentNode->pLeftChild);
	printf("%d ", pParentNode->key);
	inorderTraversalBST(pParentNode->pRightChild);
}

void	postorderTraversalBST(BSTNode *pParentNode)
{
	if (pParentNode == NULL)
		return ;
	postorderTraversalBST(pParentNode->pLeftChild);
	postorderTraversalBST(pParentNode->pRightChild);
	printf("%d ", pParentNode->key);
}

void	preorderTraversalBSTIter(BSTNode *pParentNode)
{
	LinkedDeque	*pDeque;
	DequeNode	pDequeNode;
	DequeNode	*pCurNode;
	BSTNode		pBSTNode;

	if (pParentNode == NULL)
		return ;
	pDeque = createLinkedDeque();
	pBSTNode = *pParentNode;
	pDequeNode.pNode = pBSTNode;
	insertRearLD(pDeque, pDequeNode);
	while (isLinkedDequeEmpty(pDeque) != TRUE)
	{
		pCurNode = peekRearLD(pDeque);
		if (pCurNode->pNode.visited == 0)
			printf("%d ", pCurNode->pNode.key);
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

void	inorderTraversalBSTIter(BSTNode *pParentNode)
{
	LinkedDeque	*pDeque;
	DequeNode	pDequeNode;
	DequeNode	*pCurNode;
	BSTNode	pBSTNode;

	if (pParentNode == NULL)
		return ;
	pDeque = createLinkedDeque();
	pBSTNode = *pParentNode;
	pDequeNode.pNode = pBSTNode;
	insertRearLD(pDeque, pDequeNode);
	while (isLinkedDequeEmpty(pDeque) != TRUE)
	{
		pCurNode = peekRearLD(pDeque);
		if ((pCurNode->pNode.pLeftChild && pCurNode->pNode.visited == 1)
			|| (!pCurNode->pNode.pLeftChild && pCurNode->pNode.visited == 0))
			printf("%d ", pCurNode->pNode.key);
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

void	postorderTraversalBSTIter(BSTNode *pParentNode)
{
	LinkedDeque	*pDeque;
	DequeNode	pDequeNode;
	DequeNode	*pCurNode;
	BSTNode	pBSTNode;

	if (pParentNode == NULL)
		return ;
	pDeque = createLinkedDeque();
	pBSTNode = *pParentNode;
	pDequeNode.pNode = pBSTNode;
	insertRearLD(pDeque, pDequeNode);
	while (isLinkedDequeEmpty(pDeque) != TRUE)
	{
		pCurNode = peekRearLD(pDeque);
		if (2 - (!pCurNode->pNode.pLeftChild + !pCurNode->pNode.pRightChild) == pCurNode->pNode.visited)
		{
			printf("%d ", pCurNode->pNode.key);
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

static void getMaxLevelRecSub(BSTNode *pParentNode, int *current, int *max)
{
	if (pParentNode == NULL)
	{
		*current -= 1;
		return ;
	}
	if (*current > *max)
		*max = *current;
	*current += 1;
	getMaxLevelRecSub(pParentNode->pLeftChild, current, max);
	*current += 1;
	getMaxLevelRecSub(pParentNode->pRightChild, current, max);
	*current -= 1;
}

// return -1 for error
int getMaxLevelRec(BST *pBST)
{
	int	current = 1;
	int	max = 0;

	if (pBST == NULL)
		return (-1);
	getMaxLevelRecSub(pBST->pRootNode, &current, &max);
	return (max);
}


static int	getPrintCount(int level)
{
	int	getPrintCount;

	getPrintCount = 1;
	while (--level)
		getPrintCount *= 2;
	return (getPrintCount);
}

static int	getMaxSpace(int maxLevel)
{
	int	maxSpace;

	maxSpace = 1;
	while (maxLevel--)
		maxSpace = maxSpace * 2;
	return (maxSpace);
}

void	printBST(BST *pBST)
{
	LinkedDeque	*pDeque;
	DequeNode	pDequeNode;
	DequeNode	*pCurNode;
	BSTNode		pBSTNode;
	int			maxLevel;
	int			maxSpace;
	int			currentLevel = 1;
	int			printCount = 0;
	int			printLevel = 1;

	if (pBST == NULL)
		return ;
	maxLevel = getMaxLevelRec(pBST);
	maxSpace = getMaxSpace(maxLevel);
	pDeque = createLinkedDeque();
	pBSTNode = *pBST->pRootNode;
	pDequeNode.pNode = pBSTNode;
	insertRearLD(pDeque, pDequeNode);
	printf("%*d", maxSpace, pBSTNode.key);
	printCount++;
	while (TRUE)
	{
		if (printCount == printLevel)
		{
			printf("\n");
			maxSpace /= 2;
			currentLevel++;
			if (currentLevel > maxLevel)
				break ;
			pCurNode = deleteFrontLD(pDeque);
			if (pCurNode->pNode.pLeftChild)
			{
				printf("%*d", maxSpace, pCurNode->pNode.pLeftChild->key);
				pDequeNode.pNode = *pCurNode->pNode.pLeftChild;
			}
			else
			{
				printf("%*s", maxSpace, "_");
				pDequeNode.pNode.pLeftChild = NULL;
				pDequeNode.pNode.pRightChild = NULL;
			}
			insertRearLD(pDeque, pDequeNode);
			if (pCurNode->pNode.pRightChild)
			{
				printf("%*d", maxSpace * 2, pCurNode->pNode.pRightChild->key);
				pDequeNode.pNode = *pCurNode->pNode.pRightChild;
			}
			else
			{
				printf("%*s", maxSpace * 2, "_");
				pDequeNode.pNode.pLeftChild = NULL;
				pDequeNode.pNode.pRightChild = NULL;
			}
			insertRearLD(pDeque, pDequeNode);
			printCount = 2;
			printLevel *= 2;
			free(pCurNode);
		}
		else
		{
			pCurNode = deleteFrontLD(pDeque);
			if (pCurNode->pNode.pLeftChild)
			{
				printf("%*d", maxSpace * 2, pCurNode->pNode.pLeftChild->key);
				pDequeNode.pNode = *pCurNode->pNode.pLeftChild;
			}
			else
			{
				printf("%*s", maxSpace * 2, "_");
				pDequeNode.pNode.pLeftChild = NULL;
				pDequeNode.pNode.pRightChild = NULL;
			}
			insertRearLD(pDeque, pDequeNode);
			if (pCurNode->pNode.pRightChild)
			{
				printf("%*d", maxSpace * 2, pCurNode->pNode.pRightChild->key);
				pDequeNode.pNode = *pCurNode->pNode.pRightChild;
			}
			else
			{
				printf("%*s", maxSpace * 2, "_");
				pDequeNode.pNode.pLeftChild = NULL;
				pDequeNode.pNode.pRightChild = NULL;
			}
			insertRearLD(pDeque, pDequeNode);
			printCount += 2;
			free(pCurNode);
		}
	}
	deleteLinkedDeque(pDeque);
}
