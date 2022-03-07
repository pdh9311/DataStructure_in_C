#include "prim.h"

static void	dfs(LinkedGraph *graph, int root)
{
	LinkedDeque	*stack;
	DequeNode	insert;
	DequeNode	*node;
	int			*check;

	check = calloc((graph->maxVertexCount), sizeof (int));
	if (check == NULL)
		return ;
	stack = createLinkedDeque();
	insert.data = root;
	insertFrontLD(stack, insert);
	check[root] = 1;
	while(!isLinkedDequeEmpty(stack))
	{
		node = deleteFrontLD(stack);
		printf("%d -> ", node->data);
		for (int i = ((graph->ppAdjEdge)[node->data])->currentElementCount - 1; i >= 0; i--)
		{
			insert.data = getLLElement((graph->ppAdjEdge)[node->data], i)->vertexID;
			if (check[insert.data] == 0)
			{
				check[insert.data] = 1;
				insertFrontLD(stack, insert);
			}
		}
	}
	printf("end\n");
}

static void	bfs(LinkedGraph *graph, int	root)
{
	LinkedDeque	*queue;
	DequeNode	insert;
	DequeNode	*node;
	int			*check;

	check = calloc((graph->maxVertexCount), sizeof (int));
	if (check == NULL)
		return ;
	queue = createLinkedDeque();
	insert.data = root;
	insertRearLD(queue, insert);
	check[insert.data] = 1;
	while (!isLinkedDequeEmpty(queue))
	{
		node = deleteFrontLD(queue);
		printf("%d -> ", node->data);
		for (int i = 0; i < ((graph->ppAdjEdge)[node->data])->currentElementCount; i++)
		{
			insert.data = getLLElement((graph->ppAdjEdge)[node->data], i)->vertexID;
			if (check[insert.data] == 0)
			{
				check[insert.data] = 1;
				insertRearLD(queue, insert);
			}
		}
	}
	printf("end!\n");
}

int main(void)
{
	LinkedGraph	*lGraph;
	lGraph = createLinkedGraph(6);
	// displayLinkedGraph(lGraph);	printf("\n");

	addVertexLG(lGraph, 0);
	addVertexLG(lGraph, 1);
	addVertexLG(lGraph, 2);
	addVertexLG(lGraph, 3);
	addVertexLG(lGraph, 4);
	addVertexLG(lGraph, 5);

	addEdgewithWeightLG(lGraph, 0, 1, 4);
	addEdgewithWeightLG(lGraph, 0, 2, 3);
	addEdgewithWeightLG(lGraph, 1, 2, 2);
	addEdgewithWeightLG(lGraph, 2, 3, 1);
	addEdgewithWeightLG(lGraph, 3, 4, 1);
	addEdgewithWeightLG(lGraph, 3, 5, 5);
	addEdgewithWeightLG(lGraph, 4, 5, 6);
	displayLinkedGraph(lGraph);	printf("\n");
///////////////////////////////////////////////////////////////////////

	return (0);
}
