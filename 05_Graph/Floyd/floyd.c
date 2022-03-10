#include "floyd.h"

long long **floyd(LinkedGraph *graph) {
	long long **dist;
	ListNode *node;

	dist = malloc(sizeof(long long *) * (graph->currentVertexCount));
	for (int i = 0; i < graph->currentVertexCount; i++) {
		dist[i] = malloc(sizeof(long long) * graph->currentVertexCount);
	}
	for (int i = 0; i < graph->currentVertexCount; i++) {
		for (int j = 0; j < graph->currentVertexCount; ++j) {
			dist[i][j] = INT_MAX;
		}
		dist[i][i] = 0;
	}

	for (int i = 0; i < graph->currentVertexCount; i++) {
		node = graph->ppAdjEdge[i]->headerNode.pLink;
		while (node != NULL) {
			dist[i][node->vertexID] = node->edgeWeight;
			node = node->pLink;
		}
	}

	for (int k = 0; k < graph->currentVertexCount; k++) {
		for (int i = 0; i < graph->currentVertexCount; i++) {
			for (int j = 0; j < graph->currentVertexCount; j++) {
				if (dist[i][j] > (dist[i][k] + dist[k][j]))
					dist[i][j] = (dist[i][k] + dist[k][j]);
			}
		}
	}


	return dist;
}

int main(void) {
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

	long long **dist = floyd(lGraph);
	for (int i = 0; i < lGraph->currentVertexCount; i++) {
		for (int j = 0; j < lGraph->currentVertexCount; ++j) {
			if (dist[i][j] == INT_MAX)
				printf("%2c ", 'a');
			else
				printf("%2lld ", dist[i][j]);
		}
		printf("\n");
	}
	return 0;
}
