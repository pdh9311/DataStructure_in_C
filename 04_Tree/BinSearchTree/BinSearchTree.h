#ifndef _BIN_SEARCH_TREE_
#define _BIN_SEARCH_TREE_

# include <stdio.h>
# include <stdlib.h>

# define LEFT 0
# define RIGHT 1

typedef struct BSTNodeType
{
	int key;
	int visited;
	struct BSTNodeType* pLeftChild;
	struct BSTNodeType* pRightChild;
} BSTNode;

typedef struct BSTType
{
	struct BSTNodeType* pRootNode;
} BST;


BST* makeBST(BSTNode rootNode);
BSTNode* initBSTNode(int key);
BSTNode* getRootNodeBST(BST* pBST);
BSTNode* insertLeftChildNodeBST(BSTNode* pParentNode, BSTNode element);
BSTNode* insertRightChildNodeBST(BSTNode* pParentNode, BSTNode element);
BSTNode* getLeftChildNodeBST(BSTNode* pNode);
BSTNode* getRightChildNodeBST(BSTNode* pNode);

void deleteBinTree(BST* pBST);
void deleteBinTreeNode(BSTNode* pNode);

void preorderTraversal(BSTNode* pNode);
void inorderTraversal(BSTNode *pNode);
void postorderTraversal(BSTNode *pNode);

BSTNode* insertNodeBST(BST *pBST, BSTNode element);
void deleteNodeBST(BST *pBST, BSTNode element);

void	printBinTree(BST *pBinTree);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif
