#include "Kruskal.h"

/* [union-find test]
int main(void)
{
	int parent[10];

	for (int i = 0; i < 10; i++)
		parent[i] = i;
	unionParent(parent, 0, 1);
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);

	unionParent(parent, 4, 5);
	unionParent(parent, 5, 6);
	printf("%d과 %d는 같은 부모를 가지고 있나? %d\n", 1, 2, findParent(parent, 1, 2));
	printf("%d과 %d는 같은 부모를 가지고 있나? %d\n", 1, 4, findParent(parent, 1, 4));
	return (0);
}
*/
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
	graph = createLinkedGraph(6);
	// displayLinkedGraph(graph);	printf("\n");

	addVertexLG(graph, 0);
	addVertexLG(graph, 1);
	addVertexLG(graph, 2);
	addVertexLG(graph, 3);
	addVertexLG(graph, 4);
	addVertexLG(graph, 5);

	addEdgeLG(graph, 0, 1);
	addEdgeLG(graph, 0, 2);
	addEdgeLG(graph, 1, 2);
	addEdgeLG(graph, 2, 3);
	addEdgeLG(graph, 3, 4);
	addEdgeLG(graph, 3, 5);
	addEdgeLG(graph, 4, 5);
	displayLinkedGraph(graph);	printf("\n");

	// bfs(graph, 0);
	// dfs(graph, 0);

	// displayLinkedGraph(graph);	printf("\n");

	// // removeEdgeLG(graph, 4, 0);
	// // displayLinkedGraph(graph);	printf("\n");

	// removeVertexLG(graph, 1);
	// displayLinkedGraph(graph);	printf("\n");

	return (0);
}
