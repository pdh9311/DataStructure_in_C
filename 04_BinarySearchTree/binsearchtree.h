#ifndef _BIN_SEARCH_TREE_
# define _BIN_SEARCH_TREE_

# include <stdio.h>
# include <stdlib.h>

typedef struct	BSTNodeType
{
	int						visited;
	int					key;
	struct BSTNodeType	*pLeftChild;
	struct BSTNodeType	*pRightChild;
}	BSTNode;

typedef struct	BSTType
{
	struct BSTNodeType	*pRootNode;
}	BST;

BST		*makeBST(void);
BSTNode	*getRootNodeBST(BST *pBST);
BSTNode	*searchBST(BST *pBST, int key);
int		insertBSTNode(BST *pBST, BSTNode element);
BSTNode	*insertRootNode(BST *pBST, BSTNode element);
BSTNode	*insertLeftChildNodeBST(BSTNode *pParentNode, BSTNode element);
BSTNode	*insertRightChildNodeBST(BSTNode *pParentNode, BSTNode element);

void	deleteBST(BST *pBST);
BSTNode	*deleteBSTNode(BST *pBST, int key);

void	preorderTraversalBST(BSTNode *pParentNode);
void	inorderTraversalBST(BSTNode *pParentNode);
void	postorderTraversalBST(BSTNode *pParentNode);

void	preorderTraversalBSTIter(BSTNode *pParentNode);
void	inorderTraversalBSTIter(BSTNode *pParentNode);
void	postorderTraversalBSTIter(BSTNode *pParentNode);

int		getMaxLevel(BST *pBST);
int 	getMaxLevelRec(BST *pBST);

void	printBST(BST *pBST);

BSTNode	*searchBSTNode(BST *pBST, char c);

#endif

#ifndef _COMMON_TREE_DEF_
# define _COMMON_TREE_DEF_

# define TRUE		1
# define FALSE		0

#endif
