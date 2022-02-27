#include "arraygraph.h"


static void freeGraph(ArrayGraph *graph, int n)
{
	if (n == -1)
		n = graph->maxVertexCount;
	for (int i = 0; i < n; i++)
	{
		free(graph->ppAdjEdge[i]);
		graph->ppAdjEdge[i] = NULL;
	}
	free(graph->ppAdjEdge);
	graph->ppAdjEdge = NULL;
	free(graph);
}

static void initTwoDimension(ArrayGraph *graph)
{
	for (int i = 0; i < graph->maxVertexCount; i++)
		for (int j = 0; j < graph->maxVertexCount; j++)
			graph->ppAdjEdge[i][j] = 0;
}

// 그래프 생성
ArrayGraph* createArrayGraph(int maxVertexCount)
{
	ArrayGraph *graph = NULL;

	graph = (ArrayGraph *)malloc(sizeof(ArrayGraph));
	if (graph == NULL)
		return (NULL);
	graph->maxVertexCount = maxVertexCount;
	graph->currentVertexCount = 0;
	graph->graphType = UNDIRECTED;
	// 간선 저장 2차원 array
	graph->ppAdjEdge = (int **)malloc(sizeof(int *) * maxVertexCount);
	if (graph->ppAdjEdge == NULL)
	{
		free(graph);
		graph = NULL;
		return (NULL);
	}
	for (int i = 0; i < maxVertexCount; i++)
	{
		graph->ppAdjEdge[i] = (int *)malloc(sizeof(int) * maxVertexCount);
		if (graph->ppAdjEdge[i] == NULL)
		{
			freeGraph(graph, i);
			graph = NULL;
			return (NULL);
		}
	}
	initTwoDimension(graph);
	// vertex 저장 1차원 array
	graph->pVertex = (int *)malloc(sizeof(int) * maxVertexCount);
	if (graph->pVertex == NULL)
	{
		freeGraph(graph, -1);
		graph = NULL;
		return (NULL);
	}
	return (graph);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{

}


// 그래프 삭제
void deleteArrayGraph(ArrayGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		free(pGraph->ppAdjEdge[i]);
		pGraph->ppAdjEdge[i] = NULL;
	}
	free(pGraph->ppAdjEdge);
	pGraph->ppAdjEdge = NULL;
	free(pGraph->pVertex);
	pGraph->pVertex = NULL;
	free(pGraph);
}


// 공백 그래프 여부 판단
int isEmptyAG(ArrayGraph* pGraph)
{

}


// 노드 추가
int addVertexAG(ArrayGraph* pGraph, int vertexID)
{

}


// 간선 추가
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{

}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{

}


// 노드의 유효성 점검.
int checkVertexValid(ArrayGraph* pGraph, int vertexID)
{

}


// 노드 제거
int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{

}


// 간선 제거
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{

}


// 그래프 정보 출력
void displayArrayGraph(ArrayGraph* pGraph)
{
	// maxVertexCount -> currentVertexCount
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		for (int j = 0; j < pGraph->maxVertexCount; j++)
		{
			printf("%d ", pGraph->ppAdjEdge[i][j]);
		}
		printf("\n");
	}
}
