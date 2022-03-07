#ifndef PRIM_H
# define PRIM_H

# include "linkedgraph.h"

typedef struct VertexType {
	int *selected;
	int *distance;
	LinkedGraph *lGraph;
}	VertexMST;

VertexMST	*createVertexLG(LinkedGraph *graph)
{
	VertexMST *vMST;

	vMST = (VertexMST *)malloc(sizeof(VertexMST));
	if (vMST == NULL)
		return (NULL);
	vMST->lGraph = graph;
	vMST->selected = (int *)malloc(sizeof(int) * graph->currentVertexCount);
}

#endif
