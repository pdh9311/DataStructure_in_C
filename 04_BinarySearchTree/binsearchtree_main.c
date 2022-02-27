#include "binsearchtree.h"
#include "color.h"

void	printMode(void)
{
	printf("%s", ANSI_COLOR_CYAN);
	printf("\n========================================\n");
	printf("%s", ANSI_COLOR_GREEN);
	printf("[1] Create BST\n");
	printf("[2] Search Node\n");
	printf("[3] Insert Node\n");
	printf("[4] Set Default\n");
	printf("[5] Delete BSTNode\n");
	printf("[6] Pre/In/Postorder Traversal(Rec)\n");
	printf("[7] Pre/In/Postorder Traversal(Iter)\n");
	printf("[8] Print Tree\n");
	printf("[9] Delete BinarySearchTree\n");
	printf("[0] End Program\n");
	printf("%s", ANSI_COLOR_CYAN);
	printf("========================================\n\n");
	printf("%s", ANSI_COLOR_RESET);
}

void	BSTNodeInit(BSTNode *pNode)
{
	pNode->pLeftChild = NULL;
	pNode->pRightChild = NULL;
	pNode->visited = 0;
}

BST	*setDefault()
{
	BST		*pBST;
	BSTNode	pNode;
	int		numSet[] = {30, 20, 40, 10, 24, 34, 46, 6, 14, 22};
	int		i = 0;

	BSTNodeInit(&pNode);
	pBST = makeBST();
	while (i < 10)
	{
		pNode.key = numSet[i];
		insertBSTNode(pBST, pNode);
		i++;
	}
	return (pBST);
}

int	main(void)
{
	int		command;
	BST		*pBST;
	BSTNode	*pTempNode;
	BSTNode	pNode;

	pTempNode = NULL;
	pBST = NULL;
	BSTNodeInit(&pNode);
	while (TRUE)
	{
		printMode();
		printf("Select Mode: ");
		scanf("%d", &command);
		printf("\n");
		switch (command)
		{
		case 1:
			if (pBST != NULL)
			{
				printf("%sPlease delete BST before create it.%s\n\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
				break ;
			}
			pBST = makeBST();
			printf("\n");
			break ;

		case 2:
			if (pBST == NULL)
			{
				printf("%sPlease create BST before search node.%s\n\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
				break ;
			}
			printf("Put node key to search: ");
			scanf(" %d", &pNode.key);
			printf("\n");
			pTempNode = searchBST(pBST, pNode.key);
			if (pTempNode != NULL)
				printf("%s[%d] node is in BST. The node address is %p%s\n\n", ANSI_COLOR_BLUE, pNode.key, pTempNode, ANSI_COLOR_RESET);
			else
				printf("%s[%d] node is not found.%s\n\n", ANSI_COLOR_RED, pNode.key, ANSI_COLOR_RESET);
			break ;

		case 3:
			if (pBST == NULL)
			{
				printf("%sPlease create BST before insert node.%s\n\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
				break ;
			}
			printf("Put new node key: ");
			scanf(" %d", &pNode.key);
			printf("\n");
			insertBSTNode(pBST, pNode);
			printf("%sBST%s\n\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
			printBST(pBST);
			printf("\n");
			break ;

		case 4:
			if (pBST != NULL)
			{
				printf("%sPlease delete BST before set default.%s\n\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
				break ;
			}
			pBST = setDefault();
			printf("\n");
			printf("%sBST%s\n\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
			printBST(pBST);
			printf("\n");
			break ;

		case 5:
			if (pBST == NULL)
			{
				printf("%sPlease create BST before delete node.%s\n\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
				break ;
			}
			printf("Put delete node key: ");
			scanf(" %d", &pNode.key);
			printf("\n");
			pTempNode = deleteBSTNode(pBST, pNode.key);
			if (pTempNode != NULL)
				printf("%s[%d] node is deleted. The node address was %p%s\n\n", ANSI_COLOR_BLUE, pNode.key, pTempNode, ANSI_COLOR_RESET);
			else
				printf("%s[%d] node is not found.%s\n\n", ANSI_COLOR_RED, pNode.key, ANSI_COLOR_RESET);
			free(pTempNode);
			printf("%sBST%s\n\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
			printBST(pBST);
			printf("\n");
			break ;

		case 6:
			if (pBST == NULL)
			{
				printf("%sPlease create BST before print it.%s\n\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
				break ;
			}
			printf("\n");
			printf("%sBST%s\n\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
			printBST(pBST);
			printf("\n");
			printf("\n");
			printf("%s[Preorder]%s\n", ANSI_COLOR_MAGENTA, ANSI_COLOR_RESET);
			preorderTraversalBST(getRootNodeBST(pBST));
			printf("\n");
			printf("\n");
			printf("%s[Inorder]%s\n", ANSI_COLOR_MAGENTA, ANSI_COLOR_RESET);
			inorderTraversalBST(getRootNodeBST(pBST));
			printf("\n");
			printf("\n");
			printf("%s[Postorder]%s\n", ANSI_COLOR_MAGENTA, ANSI_COLOR_RESET);
			postorderTraversalBST(getRootNodeBST(pBST));
			printf("\n");
			printf("\n");
			break ;

		case 7:
			if (pBST == NULL)
			{
				printf("%sPlease create BST before print it.%s\n\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
				break ;
			}
			printf("\n");
			printf("%sBST%s\n\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
			printBST(pBST);
			printf("\n");
			printf("\n");
			printf("%s[Preorder]%s\n", ANSI_COLOR_CYAN, ANSI_COLOR_RESET);
			preorderTraversalBSTIter(getRootNodeBST(pBST));
			printf("\n");
			printf("\n");
			printf("%s[Inorder]%s\n", ANSI_COLOR_CYAN, ANSI_COLOR_RESET);
			inorderTraversalBSTIter(getRootNodeBST(pBST));
			printf("\n");
			printf("\n");
			printf("%s[Postorder]%s\n", ANSI_COLOR_CYAN, ANSI_COLOR_RESET);
			postorderTraversalBSTIter(getRootNodeBST(pBST));
			printf("\n");
			printf("\n");
			break ;

		case 8:
			if (pBST == NULL)
			{
				printf("%sPlease create BST before print it.%s\n\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
				break ;
			}
			printf("\n");
			printf("%sBST%s\n\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
			printBST(pBST);
			printf("\n");
			break ;

		case 9:
			printf("%sDelete BST%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
			printf("\n");
			deleteBST(pBST);
			pBST = NULL;
			break ;

		case 0:
			return (0);
		}
	}
	return (0);
}
