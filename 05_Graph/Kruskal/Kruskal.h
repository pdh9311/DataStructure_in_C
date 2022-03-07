#ifndef KRUSKAL_H
# define KRUSKAL_H

# include "linkedgraph.h"

typedef struct EdgeType {
	int	fromVertex;
	int	toVertex;
	int	weight;
}	Edge;

typedef struct KruskalType {
	int				graphEdgeCount;		// 간선의 개수
	int				graphVertexCount;
	int				kruskalEdgeCount;
	struct EdgeType	**edges;
	int				*parent;
}	KruskalMST;

KruskalMST *createKruskalLG(LinkedGraph * graph);
void displayKruskalMST(KruskalMST *kMST);
void quicksortEdge(Edge **edgeList, int left, int right);
int kruskal(KruskalMST *kMST);

#endif
