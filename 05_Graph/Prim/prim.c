#include "prim.h"

static int prim(int start, LinkedGraph *graph)
{
	int		 	dist;
	int 		*visit;
	int 		visit_count;
	Heap 		*heap;
	HeapElement	element;
	ListNode	*node;

	dist = 0;
	visit_count = 1;
	visit = malloc(sizeof(int) * graph->currentVertexCount);
	for (int i = 0; i < graph->currentVertexCount; ++i) {
		visit[i] = FALSE;
	}
	visit[start] = TRUE;
	heap = createHeap();
	node = graph->ppAdjEdge[start]->headerNode.pLink;
	while (node != NULL)
	{
		insertElement(heap, -(node->edgeWeight), node->vertexID);
		node = node->pLink;
	}
	while (visit_count != graph->currentVertexCount) {
		element = deleteElement(heap);
		while (visit[element.toVertex] == TRUE)
			element = deleteElement(heap);
		node = graph->ppAdjEdge[element.toVertex]->headerNode.pLink;
		while (node != NULL)
		{
			if (visit[node->vertexID] == FALSE)
				insertElement(heap, -(node->edgeWeight), node->vertexID);
			node = node->pLink;
		}
		printf("weight: %d, toVertex: %d\n", -(element.weight), element.toVertex);
		dist += -(element.weight);
		visit_count++;
		visit[element.toVertex] = TRUE;
	}
	return (dist);
}

int	main(void) {
	LinkedGraph *lGraph;
	lGraph = createLinkedGraph(6);
	// displayLinkedGraph(lGraph);	printf("\n");

	addVertexLG(lGraph, 0);
	addVertexLG(lGraph, 1);
	addVertexLG(lGraph, 2);
	addVertexLG(lGraph, 3);
	addVertexLG(lGraph, 4);
	addVertexLG(lGraph, 5);

//	addEdgewithWeightLG(lGraph, 0, 1, 4);
//	addEdgewithWeightLG(lGraph, 0, 2, 3);
//	addEdgewithWeightLG(lGraph, 1, 2, 2);
//	addEdgewithWeightLG(lGraph, 2, 3, 1);
//	addEdgewithWeightLG(lGraph, 3, 4, 1);
//	addEdgewithWeightLG(lGraph, 3, 5, 5);
//	addEdgewithWeightLG(lGraph, 4, 5, 6);

	addEdgewithWeightLG(lGraph, 0, 1, 7);
	addEdgewithWeightLG(lGraph, 0, 2, 9);
	addEdgewithWeightLG(lGraph, 0, 5, 14);
	addEdgewithWeightLG(lGraph, 1, 2, 10);
	addEdgewithWeightLG(lGraph, 1, 3, 15);
	addEdgewithWeightLG(lGraph, 2, 3, 11);
	addEdgewithWeightLG(lGraph, 2, 5, 2);
	addEdgewithWeightLG(lGraph, 3, 4, 6);
	addEdgewithWeightLG(lGraph, 4, 5, 8);

	displayLinkedGraph(lGraph);
	printf("\n");

	int dist = prim(0, lGraph);
	printf("min_dist: %d\n", dist);
}