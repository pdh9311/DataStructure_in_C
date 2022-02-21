#include "bintree.h"

void	printMode(void)
{
	printf("\n==============================\n");
	printf("[1] Create BinTree\n");
	printf("[2] Insert Left\n");
	printf("[3] Insert Right\n");
	printf("[4] Search Node\n");
	printf("[5] Set Default\n");
	printf("[6] Print BinTree(Recursive)\n");
	printf("[7] Print BinTree(Iterator)\n");
	printf("[8] Print Tree\n");
	printf("[9] Delete BinTree\n");
	printf("[0] End Program\n");
	printf("==============================\n\n");
}

void	binTreeNodeInit(BinTreeNode *pNode)
{
	pNode->pLeftChild = NULL;
	pNode->pRightChild = NULL;
	pNode->visited = 0;
}

BinTree	*setDefault()
{
	BinTree		*pBinTree;
	BinTreeNode	pNode;
	char		*parentNode = "AABBCCDDEFGG";
	char		*dir = "LRLRLRLRLRLR";

	binTreeNodeInit(&pNode);
	pNode.data = 'A';
	pBinTree = makeBinTree(pNode);
	while (*dir)
	{
		pNode.data++;
		if (*dir == 'L')
			insertLeftChildNodeBT(searchBinTreeNode(pBinTree, *parentNode), pNode);
		else
			insertRightChildNodeBT(searchBinTreeNode(pBinTree, *parentNode), pNode);
		dir++;
		parentNode++;
	}
	return (pBinTree);
}

int	main(void)
{
	int			command;
	char		*defaultString;
	BinTree		*pBinTree;
	BinTreeNode	*pTempNode;
	BinTreeNode	pNode;

	pTempNode = NULL;
	pBinTree = NULL;
	binTreeNodeInit(&pNode);
	while (TRUE)
	{
		printMode();
		printf("Select Mode: ");
		scanf("%d", &command);
		switch (command)
		{
		case 1:
			if (pBinTree != NULL)
			{
				printf("Please delete BinTree before create BinTree.\n\n");
				break ;
			}
			printf("Put pRootNode data: ");
			scanf(" %c", &pNode.data);
			pBinTree = makeBinTree(pNode);
			printf("\n");
			printf("BinTree \n");
			printBinTree(pBinTree);
			printf("\n");
			printf("\n");
			break ;

		case 2:
			if (pBinTree == NULL)
			{
				printf("Please create BinTree before insert data.\n\n");
				break ;
			}
			printf("Parent node data: ");
			scanf(" %c", &pNode.data);
			pTempNode = searchBinTreeNode(pBinTree, pNode.data);
			if (pTempNode->pLeftChild)
			{
				printf("Child node is already exist\n");
				break;
			}
			printf("Put pLeftChildNode data: ");
			scanf(" %c", &pNode.data);
			insertLeftChildNodeBT(pTempNode, pNode);
			printf("\n");
			printf("BinTree \n");
			printBinTree(pBinTree);
			printf("\n");
			printf("\n");
			break ;

		case 3:
			if (pBinTree == NULL)
			{
				printf("Please create BinTree before insert data.\n\n");
				break ;
			}
			printf("Parent node data: ");
			scanf(" %c", &pNode.data);
			pTempNode = searchBinTreeNode(pBinTree, pNode.data);
			if (pTempNode->pRightChild)
			{
				printf("Child node is already exist\n");
				break ;
			}
			printf("Put pLeftChildNode data: ");
			scanf(" %c", &pNode.data);
			insertRightChildNodeBT(pTempNode, pNode);
			printf("\n");
			printf("BinTree \n");
			printBinTree(pBinTree);
			printf("\n");
			printf("\n");
			break ;

		case 4:
			if (pBinTree == NULL)
			{
				printf("Please create BinTree before search data.\n\n");
				break ;
			}
			printf("[char type] to search: ");
			scanf(" %c", &pNode.data);
			pTempNode = searchBinTreeNode(pBinTree, pNode.data);
			printf("\n");
			if (pTempNode == NULL)
				printf("There is no [%c] in BinTree\n", pNode.data);
			else
				printf("[%c] node address is %p", pNode.data, pTempNode);
			printf("\n");
			break ;

		case 5:
			if (pBinTree != NULL)
			{
				printf("Please delete BinTree before set default BinTree.\n\n");
				break ;
			}
			pBinTree = setDefault();
			printf("\n");
			printf("BinTree \n");
			printBinTree(pBinTree);
			printf("\n");
			printf("\n");
			break;

		case 6:
			if (pBinTree == NULL)
			{
				printf("Please create BinTree before print it.\n\n");
				break ;
			}
			printf("\n");
			printf("[Preorder]\n");
			preorderTraversalBinTree(getRootNodeBT(pBinTree));
			printf("\n");
			printf("[Inorder]\n");
			inorderTraversalBinTree(getRootNodeBT(pBinTree));
			printf("\n");
			printf("[Postorder]\n");
			postorderTraversalBinTree(getRootNodeBT(pBinTree));
			printf("\n");
			printf("\n");
			break ;

		case 7:
			if (pBinTree == NULL)
			{
				printf("Please create BinTree before print it.\n\n");
				break ;
			}
			printf("\n");
			printf("[Preorder]\n");
			preorderTraversalBinTreeIter(getRootNodeBT(pBinTree));
			printf("\n");
			printf("[Inorder]\n");
			inorderTraversalBinTreeIter(getRootNodeBT(pBinTree));
			printf("\n");
			printf("[Postorder]\n");
			postorderTraversalBinTreeIter(getRootNodeBT(pBinTree));
			printf("\n");
			printf("\n");
			break ;

		case 8:
			// printf("Max Level : %d\n", getMaxLevelRec(pBinTree));
			// printf("Max Level : %d\n", getMaxLevel(pBinTree));
			printBinTree(pBinTree);
			printf("\n");
			break ;

		case 9:
			printf("Delete BinTree\n");
			deleteBinTree(pBinTree);
			pBinTree = NULL;
			break ;

		case 0:
			// system("leaks a.out");
			deleteBinTree(pBinTree);
			return (0);
		}
	}
	return (0);
}
