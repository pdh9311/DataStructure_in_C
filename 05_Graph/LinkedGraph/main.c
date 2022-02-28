#include "linkedgraph.h"

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
			insert.data = getLLElement((graph->ppAdjEdge)[node->data], i)->data;
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
			insert.data = getLLElement((graph->ppAdjEdge)[node->data], i)->data;
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
	LinkedGraph	*graph;
	graph = createLinkedDirectedGraph(8);
	displayLinkedGraph(graph);	printf("\n");

	addVertexLG(graph, 0);
	addVertexLG(graph, 1);
	addVertexLG(graph, 2);
	addVertexLG(graph, 3);
	addVertexLG(graph, 4);
	addVertexLG(graph, 5);
	addVertexLG(graph, 6);
	addVertexLG(graph, 7);
	addEdgeLG(graph, 0, 1);
	addEdgeLG(graph, 0, 2);
	addEdgeLG(graph, 1, 3);
	addEdgeLG(graph, 1, 4);
	addEdgeLG(graph, 2, 5);
	addEdgeLG(graph, 2, 6);
	addEdgeLG(graph, 3, 7);
	addEdgeLG(graph, 4, 5);
	displayLinkedGraph(graph);	printf("\n");

	// bfs(graph, 0);
	dfs(graph, 0);

	// displayLinkedGraph(graph);	printf("\n");

	// // removeEdgeLG(graph, 4, 0);
	// // displayLinkedGraph(graph);	printf("\n");

	// removeVertexLG(graph, 1);
	// displayLinkedGraph(graph);	printf("\n");

	return (0);
}