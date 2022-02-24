#include "bintree.h"

/*
		        A
		   /         \
		  B           C
		/   \       /   \
	   D     E     F     G
	  / \   /       \   / \
	 H   I j         K L   M
*/
int main(void) {
	BinTree *binTree = NULL;
	BinTreeNode rootNode;
	BinTreeNode node;

	rootNode.data = 'A';
	binTree = makeBinTree(rootNode);

	node.data = 'B';
	BinTreeNode *tmpB = insertLeftChildNodeBT(binTree->pRootNode, node);
		node.data = 'D';
		BinTreeNode *tmpD = insertLeftChildNodeBT(tmpB, node);
			node.data = 'H';
			BinTreeNode *tmpH = insertLeftChildNodeBT(tmpD, node);
			node.data = 'I';
			BinTreeNode *tmpI = insertRightChildNodeBT(tmpD, node);

		node.data = 'E';
		BinTreeNode *tmpE = insertRightChildNodeBT(tmpB, node);
			node.data = 'J';
			BinTreeNode *tmpJ = insertLeftChildNodeBT(tmpE, node);

	node.data = 'C';
	BinTreeNode *tmpC = insertRightChildNodeBT(binTree->pRootNode, node);
		node.data = 'F';
		BinTreeNode *tmpF = insertLeftChildNodeBT(tmpC, node);
			node.data = 'K';
			BinTreeNode *tmpK = insertRightChildNodeBT(tmpF, node);
		node.data = 'G';
		BinTreeNode *tmpG = insertRightChildNodeBT(tmpC, node);
			node.data = 'L';
			BinTreeNode *tmpL = insertLeftChildNodeBT(tmpG, node);
			node.data = 'M';
			BinTreeNode *tmpM = insertRightChildNodeBT(tmpG, node);

	preorderTraversal(binTree->pRootNode);	// A B D H I E J C F K G L M
	printf("\n");
	inorderTraversal(binTree->pRootNode);	// H D I B J E A F K C L G M
	printf("\n");
	postorderTraversal(binTree->pRootNode);	// H I D J E B K F L M G C A
	printf("\n");
	deleteBinTree(binTree);
	return (0);
}
/*
		        A
		   /         \
		  B           C
		/   \       /   \
	   D     E     F     G
	  / \   /       \   / \
	 H   I j         K L   M
*/
