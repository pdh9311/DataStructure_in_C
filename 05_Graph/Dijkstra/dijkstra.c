#include "dijkstra.h"
#include <limits.h>

int	*dijkstra(int start, LinkedGraph *graph)
{
//	start vertex 에서 출발하는 노드들에 대한 가중치와 도착 vertex를 저장한다.
	Heap 		*heap;
	HeapElement min;

	int *dist;
	int *visit;

	dist = malloc(sizeof(int) * graph->currentVertexCount);
	visit = malloc(sizeof(int) * graph->currentVertexCount);
	for (int i = 0; i < graph->currentVertexCount; i++) {
		dist[i] = INT_MAX;
	}
	for (int i = 0; i < graph->currentVertexCount; ++i) {
		visit[i] = NOT_VISIT;
	}

	ListNode *node;
	heap = createHeap();
	insertElement(heap, 0, start);
	while (heap->heap_size > 0) {
		min = deleteElement(heap);
		if (visit[min.toVertex] == VISIT)
			continue ;
		visit[min.toVertex] = VISIT;
		if (-min.weight < dist[min.toVertex])
			dist[min.toVertex] = -min.weight;
		node = graph->ppAdjEdge[min.toVertex]->headerNode.pLink;
		while (node != NULL) {
			if (visit[node->vertexID] == NOT_VISIT)
				insertElement(heap, -(dist[min.toVertex] + node->edgeWeight), node->vertexID);
			node = node->pLink;
		}
	}
	free(visit);
	return (dist);
}

int	main(void)
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

	displayLinkedGraph(lGraph);	printf("\n");

	for (int i = 0; i < lGraph->currentVertexCount; ++i) {
		int *dist = dijkstra(i, lGraph);
		printf("==== FROM Vertex%d ====\n", i);
		for (int j = 0; j < lGraph->currentVertexCount; j++) {
			printf("%d: %d\n", j, dist[j]);
		}
		free(dist);
	}

	deleteLinkedGraph(lGraph);
	return (0);
}