#include "Kruskal.h"

KruskalMST *createKruskalLG(LinkedGraph *graph)
{
	KruskalMST	*kMST;
	LinkedList	*lst;
	ListNode	*node;
	Edge		*edge;

	kMST = (KruskalMST *)malloc(sizeof(KruskalMST));
	if (kMST == NULL)
		return (NULL);
	kMST->graphEdgeCount = 0;
	kMST->graphVertexCount = graph->currentVertexCount;
	kMST->kruskalEdgeCount = kMST->graphVertexCount - 1;
	kMST->edges = (Edge **)malloc(sizeof(Edge) * graph->currentEdgeCount);
	for (int i = 0; i < graph->currentEdgeCount; i++)
		kMST->edges[i] = (Edge *)malloc(sizeof(Edge));
	if (kMST->edges == NULL)
	{
		free(kMST);
		return (NULL);
	}
	for (int i = 0; i < graph->currentVertexCount; i++)
	{
		lst = graph->ppAdjEdge[i];
		node = lst->headerNode.pLink;
		while (node != NULL)
		{
			if (node->vertexID > i) {
				kMST->edges[kMST->graphEdgeCount]->fromVertex = i;
				kMST->edges[kMST->graphEdgeCount]->toVertex = node->vertexID;
				kMST->edges[kMST->graphEdgeCount]->weight = node->edgeWeight;
				(kMST->graphEdgeCount)++;
			}
			node = node->pLink;
		}
	}
	if (kMST->graphEdgeCount != graph->currentEdgeCount)
	{
		free(kMST->edges);
		free(kMST);
		return (NULL);
	}
	return (kMST);
}

static void swap(Edge **edgeList, int left, int right)
{
	int fromTmp;
	int toTmp;
	int weightTmp;

	fromTmp = edgeList[left]->fromVertex;
	toTmp = edgeList[left]->toVertex;
	weightTmp = edgeList[left]->weight;
	edgeList[left]->fromVertex = edgeList[right]->fromVertex;
	edgeList[left]->toVertex = edgeList[right]->toVertex;
	edgeList[left]->weight = edgeList[right]->weight;
	edgeList[right]->fromVertex = fromTmp;
	edgeList[right]->toVertex = toTmp;
	edgeList[right]->weight = weightTmp;
}

static int partition(Edge **edgeList, int left, int right)
{
	Edge *pivot = edgeList[(left + right) / 2];
	int front = left;
	int end = right;

	while (edgeList[left]->weight <= edgeList[right]->weight)
	{
		while (left <= end && edgeList[left]->weight < pivot->weight)
			left++;
		while (right >= front && edgeList[right]->weight > pivot->weight)
			right--;
		if (left <= right)
			swap(edgeList, left++, right--);
	}
	return (left);
}

void quicksortEdge(Edge **edgeList, int left, int right)
{
	if (edgeList[left]->weight >= edgeList[right]->weight)
		return ;
	int mid = partition(edgeList, left, right);
	quicksortEdge(edgeList, left, mid - 1);
	quicksortEdge(edgeList, mid, right);
}

void displayKruskalMST(KruskalMST *kMST)
{
	Edge *edge;

	for (int i = 0; i < kMST->graphEdgeCount; i++)
	{
		edge = kMST->edges[i];
		printf("from: %d, to: %d, weight: %d\n", \
			edge->fromVertex, edge->toVertex, edge->weight);
	}
	printf("\n");
}

static void set_init(KruskalMST *kMST)
{
	kMST->parent = (int *)malloc(sizeof(int) * (kMST->graphVertexCount));
	if (kMST->parent == NULL)
		return ;
	for (int i = 0; i < kMST->graphVertexCount; i++)
		kMST->parent[i] = i;
}
// 부모노드를 찾는다.
static int set_find(KruskalMST *kMST, int curVertex)
{
	if ((kMST->parent)[curVertex] == curVertex)
		return (curVertex);
	return (set_find(kMST, (kMST->parent)[curVertex]));
}
// 최상위 부모노드를로 합친다. (여기서는 가장 장은 노드를 최상위노드로 가정한다.)
static void set_union(KruskalMST *kMST, int u, int v)
{
	int uParent = set_find(kMST, u);
	int vParent = set_find(kMST, v);
	if (uParent < vParent)
		(kMST->parent)[v] = uParent;
	else
		(kMST->parent)[u] = vParent;
}

int kruskal(KruskalMST *kMST)
{
	int edgeCount;
	int i;
	int u, v;
	int distance;
	Edge *e;

	set_init(kMST);
	edgeCount = 0;
	i = 0;
	distance = 0;
	while (edgeCount < kMST->kruskalEdgeCount)
	{
		e = kMST->edges[i];
		u = set_find(kMST, e->fromVertex);
		v = set_find(kMST, e->toVertex);
		if (u != v)
		{
			printf("edge(%d, %d)-(%d)\n", e->fromVertex, e->toVertex, e->weight);
			distance += e->weight;
			edgeCount++;
			set_union(kMST, u, v);
		}
		i++;
	}
	return (distance);
}

/* union-find */
/*

// 부모노드를 찾는다.
int getParent(int parent[], int curVertex)
{
	if (parent[curVertex] == curVertex)
		return (curVertex);
	return getParent(parent, parent[curVertex]);
}

// 최상위 부모노드로 합친다.
void unionParent(int parent[], int a, int b)
{
	int aParent = getParent(parent, a);
	int bParent = getParent(parent, b);
	if (aParent < bParent)
		parent[b] = aParent;
	else
		parent[a] = bParent;
}

// 같은 부모노드를 가지고 있는지 확인
int findParent(int parent[], int a, int b)
{
	int aParent = getParent(parent, a);
	int bParent = getParent(parent, b);
	if (aParent == bParent)
		return (TRUE);
	else
		return (FALSE);
}

void Kruskal(LinkedGraph *graph)
{
	int *parent;	// 정점이 같은 집합에 속해있는지 판단.
	int n;			// 간선의 수

	// 각 정점이 같은 집합에 있는지 판단
	parent = malloc(sizeof(int) * graph->currentVertexCount);
	if (parent == NULL)
		return ;
	for (int i = 0; i < graph->currentVertexCount; i++)
		parent[i] = i;

}
*/
