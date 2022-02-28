#include "arraygraph.h"
#include "linkeddeque.h"

static void	dfs(ArrayGraph *graph, int root)
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
		for (int i = graph->maxVertexCount - 1; i >= 0; i--)
		{
			// 간선이 연결되어 있는지 확인하는 조건문
			if ((graph->ppAdjEdge)[node->data][i] == 1)
			{
				insert.data = i;
				if (check[insert.data] == 0)
				{
					check[insert.data] = 1;
					insertFrontLD(stack, insert);
				}
			}
		}
	}
	printf("end\n");
}

static void	bfs(ArrayGraph *graph, int	root)
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
		for (int i = 0; i < graph->maxVertexCount; i++)
		{
			if ((graph->ppAdjEdge)[node->data][i] == 1)
			{
				insert.data = i;
				if (check[insert.data] == 0)
				{
					check[insert.data] = 1;
					insertRearLD(queue, insert);
				}
			}
		}
	}
	printf("end!\n");
}

int main(void)
{
	ArrayGraph	*graph;
	graph = createArrayGraph(8);
	displayArrayGraph(graph);	printf("\n");

	addVertexAG(graph, 0);
	addVertexAG(graph, 1);
	addVertexAG(graph, 2);
	addVertexAG(graph, 3);
	addVertexAG(graph, 4);
	addVertexAG(graph, 5);
	addVertexAG(graph, 6);
	addVertexAG(graph, 7);
	addEdgeAG(graph, 0, 1);
	addEdgeAG(graph, 0, 2);
	addEdgeAG(graph, 1, 3);
	addEdgeAG(graph, 1, 4);
	addEdgeAG(graph, 2, 5);
	addEdgeAG(graph, 2, 6);
	addEdgeAG(graph, 3, 7);
	addEdgeAG(graph, 4, 5);
	displayArrayGraph(graph);	printf("\n");

	printf("===== BFS RESULT =====\n");
	bfs(graph, 0);

	printf("\n===== DFS RESULT =====\n");
	dfs(graph, 0);

	// displayLinkedGraph(graph);	printf("\n");

	// // removeEdgeLG(graph, 4, 0);
	// // displayLinkedGraph(graph);	printf("\n");

	// removeVertexLG(graph, 1);
	// displayLinkedGraph(graph);	printf("\n");

	return (0);
}