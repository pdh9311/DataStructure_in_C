#include"arraygraph.h"

ArrayGraph* createArrayGraph(int maxVertexCount)
{
	ArrayGraph *pGraph;

	pGraph = malloc(sizeof (ArrayGraph));
	if (pGraph == NULL)
		return (NULL);
	pGraph->maxVertexCount = maxVertexCount;
	pGraph->currentVertexCount = 0;
	pGraph->graphType = GRAPH_UNDIRECTED;
	pGraph->pVertex = malloc(sizeof (int) * maxVertexCount);
	if (pGraph->pVertex == NULL)
	{
		free(pGraph);
		return (NULL);
	}
	pGraph->ppAdjEdge = malloc(sizeof (int *) * (maxVertexCount));
	if (pGraph->ppAdjEdge == NULL)
	{
		free(pGraph->pVertex);
		free(pGraph);
		return (NULL);
	}
	for (int i = 0; i < maxVertexCount; i++)
	{
		(pGraph->ppAdjEdge)[i] = malloc(sizeof (int) * (maxVertexCount));
		if ((pGraph->ppAdjEdge)[i] == NULL)
		{
			for (int j = 0; j < i; j++)
				free((pGraph->ppAdjEdge)[j]);
			free(pGraph->ppAdjEdge);
			free(pGraph->pVertex);
			free(pGraph);
			return (NULL);
		}
	}
	// 정점 사용 여부 초기화
	for (int i = 0; i < maxVertexCount; i++)
		(pGraph->pVertex)[i] = NOT_USED;
	// 간선 그래프 초기화
	for (int i = 0; i < maxVertexCount; i++)
		for (int j = 0; j < maxVertexCount; j++)
			(pGraph->ppAdjEdge)[i][j] = 0;
	return (pGraph);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph *pGraph;

	pGraph = malloc(sizeof (ArrayGraph));
	if (pGraph == NULL)
		return (NULL);
	pGraph->maxVertexCount = maxVertexCount;
	pGraph->currentVertexCount = 0;
	pGraph->graphType = GRAPH_DIRECTED;
	pGraph->pVertex = malloc(sizeof (int) * maxVertexCount);
	if (pGraph->pVertex == NULL)
	{
		free(pGraph);
		return (NULL);
	}
	pGraph->ppAdjEdge = malloc(sizeof (int *) * (maxVertexCount));
	if (pGraph->ppAdjEdge == NULL)
	{
		free(pGraph->pVertex);
		free(pGraph);
		return (NULL);
	}
	for (int i = 0; i < maxVertexCount; i++)
	{
		(pGraph->ppAdjEdge)[i] = malloc(sizeof (int) * (maxVertexCount));
		if ((pGraph->ppAdjEdge)[i] == NULL)
		{
			for (int j = 0; j < i; j++)
				free((pGraph->ppAdjEdge)[j]);
			free(pGraph->ppAdjEdge);
			free(pGraph->pVertex);
			free(pGraph);
			return (NULL);
		}
	}
	for (int i = 0; i < maxVertexCount; i++)
		(pGraph->pVertex)[i] = NOT_USED;
	for (int i = 0; i < maxVertexCount; i++)
		for (int j = 0; j < maxVertexCount; j++)
			(pGraph->ppAdjEdge)[i][j] = 0;
	return (pGraph);
}

// 그래프 삭제
void deleteArrayGraph(ArrayGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		free((pGraph->ppAdjEdge)[i]);
	free(pGraph->ppAdjEdge);
	free(pGraph->pVertex);
	free(pGraph);
}

// 공백 그래프 여부 판단
int isEmptyAG(ArrayGraph* pGraph)
{
	return (pGraph->currentVertexCount == 0);
}

// 노드 추가
int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (checkVertexValid(pGraph, vertexID) && (pGraph->pVertex)[vertexID] == NOT_USED)
	{
		(pGraph->currentVertexCount)++;
		(pGraph->pVertex)[vertexID] = USED;
		return (SUCCESS);
	}
	return (FAIL);
}

// 간선 추가
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (checkVertexValid(pGraph, fromVertexID) && checkVertexValid(pGraph, toVertexID)
		&& (pGraph->pVertex)[fromVertexID] == USED && (pGraph->pVertex)[toVertexID] == USED)
	{
		(pGraph->ppAdjEdge)[fromVertexID][toVertexID] = 1;
		if (pGraph->graphType == GRAPH_UNDIRECTED)
			(pGraph->ppAdjEdge)[toVertexID][fromVertexID] = 1;
		return (SUCCESS);
	}
	return (FAIL);

}
int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (checkVertexValid(pGraph, fromVertexID) && checkVertexValid(pGraph, toVertexID)
		&& (pGraph->pVertex)[fromVertexID] == USED && (pGraph->pVertex)[toVertexID] == USED)
	{
		(pGraph->ppAdjEdge)[fromVertexID][toVertexID] = weight;
		if (pGraph->graphType == GRAPH_UNDIRECTED)
			(pGraph->ppAdjEdge)[toVertexID][fromVertexID] = weight;
		return (SUCCESS);
	}
	return (FAIL);
}

// 노드의 유효성 점검.
int checkVertexValid(ArrayGraph* pGraph, int vertexID)
{
	if (0 <= vertexID && vertexID < pGraph->maxVertexCount)
		return (TRUE);
	return (FALSE);
}

// 노드 제거
int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (checkVertexValid(pGraph, vertexID) && (pGraph->pVertex)[vertexID] == USED)
	{
		(pGraph->currentVertexCount)--;
		(pGraph->pVertex)[vertexID] = NOT_USED;
		for (int i = 0; i < pGraph->maxVertexCount; i++)
		{
			(pGraph->ppAdjEdge)[vertexID][i] = 0;
			(pGraph->ppAdjEdge)[i][vertexID] = 0;
		}
		return (SUCCESS);
	}
	return (FAIL);
}

// 간선 제거
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (checkVertexValid(pGraph, fromVertexID) && checkVertexValid(pGraph, toVertexID)
		&& (pGraph->pVertex)[fromVertexID] == USED && (pGraph->pVertex)[toVertexID] == USED)
	{
		(pGraph->ppAdjEdge)[fromVertexID][toVertexID] = 0;
		if (pGraph->graphType == GRAPH_UNDIRECTED)
			(pGraph->ppAdjEdge)[toVertexID][fromVertexID] = 0;
		return (SUCCESS);
	}
	return (FAIL);
}

// 그래프 정보 출력
void displayArrayGraph(ArrayGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		for (int j = 0; j < pGraph->maxVertexCount; j++)
			printf("%d ", (pGraph->ppAdjEdge)[i][j]);
		printf("\n");
	}
}
