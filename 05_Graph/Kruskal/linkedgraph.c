#include "linkedgraph.h"

// 그래프 생성
LinkedGraph* createLinkedGraph(int maxVertexCount)
{
	LinkedGraph *graph;

	graph = malloc(sizeof(LinkedGraph));
	if (graph == NULL)
		return (NULL);
	graph->maxVertexCount = maxVertexCount;
	graph->currentVertexCount = 0;
	graph->currentEdgeCount = 0;
	graph->graphType = GRAPH_UNDIRECTED;
	graph->pVertex = malloc(sizeof(int) * maxVertexCount);
	if (graph->pVertex == NULL)
	{
		free(graph);
		return (NULL);
	}
	graph->ppAdjEdge = malloc(sizeof(LinkedList *) * maxVertexCount);
	if (graph->ppAdjEdge == NULL)
	{
		free(graph->pVertex);
		free(graph);
		return (NULL);
	}
	for (int i = 0; i < maxVertexCount; i++)
	{
		(graph->ppAdjEdge)[i] = createLinkedList();
		if ((graph->ppAdjEdge)[i] == NULL)
		{
			for (int j = 0; j < i; j++)
				deleteLinkedList((graph->ppAdjEdge)[i]);
			free(graph->pVertex);
			free(graph->ppAdjEdge);
			free(graph);
			return (NULL);
		}
	}
	// USED, NOT_USED
	for (int i = 0; i < maxVertexCount; i++)
		(graph->pVertex)[i] = NOT_USED;
	return (graph);
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph *graph;

	graph = malloc(sizeof(LinkedGraph));
	if (graph == NULL)
		return (NULL);
	graph->maxVertexCount = maxVertexCount;
	graph->currentVertexCount = 0;
	graph->currentEdgeCount = 0;
	graph->graphType = GRAPH_DIRECTED;
	graph->pVertex = malloc(sizeof(int) * maxVertexCount);
	if (graph->pVertex == NULL)
	{
		free(graph);
		return (NULL);
	}
	graph->ppAdjEdge = malloc(sizeof(LinkedList *) * maxVertexCount);
	if (graph->ppAdjEdge == NULL)
	{
		free(graph->pVertex);
		free(graph);
		return (NULL);
	}
	for (int i = 0; i < maxVertexCount; i++)
	{
		(graph->ppAdjEdge)[i] = createLinkedList();
		if ((graph->ppAdjEdge)[i] == NULL)
		{
			for (int j = 0; j < i; j++)
				deleteLinkedList((graph->ppAdjEdge)[i]);
			free(graph->pVertex);
			free(graph->ppAdjEdge);
			free(graph);
			return (NULL);
		}
	}
	// USED, NOT_USED
	for (int i = 0; i < maxVertexCount; i++)
		(graph->pVertex)[i] = NOT_USED;
	return (graph);
}

// 그래프 삭제
void deleteLinkedGraph(LinkedGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		deleteLinkedList((pGraph->ppAdjEdge)[i]);
	free(pGraph->ppAdjEdge);
	free(pGraph->pVertex);
	free(pGraph);
}

// 공백 그래프 여부 판단
int isEmptyLG(LinkedGraph* pGraph)
{
	return (pGraph->currentVertexCount == 0);
}

// 노드 추가
int addVertexLG(LinkedGraph* pGraph, int vertexID)
{
	if (checkVertexValid(pGraph, vertexID) && (pGraph->pVertex)[vertexID] == NOT_USED)
	{
		(pGraph->pVertex)[vertexID] = USED;
		(pGraph->currentVertexCount)++;
		return (SUCCESS);
	}
	return (FAIL);
}

// 간선 추가
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	ListNode listNode;
	ListNode	*head;
	int	insertPos;
	int	val;

	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	listNode.vertexID = toVertexID;
	listNode.edgeWeight = 1;
	listNode.pLink = NULL;
	head = (((pGraph->ppAdjEdge)[fromVertexID])->headerNode).pLink;
	insertPos = 0;
	while (head != NULL && head->vertexID < toVertexID)
	{
		insertPos++;
		head = head->pLink;
	}
	val = addLLElement((pGraph->ppAdjEdge)[fromVertexID], insertPos, listNode);
	if (val == FAIL)
		return (FAIL);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		pGraph->graphType = GRAPH_DIRECTED;
		val = addEdgeLG(pGraph, toVertexID, fromVertexID);
		if (val == FAIL)
			return (FAIL);
		(pGraph->currentEdgeCount)--;
		pGraph->graphType = GRAPH_UNDIRECTED;
	}
	(pGraph->currentEdgeCount)++;
	return (SUCCESS);
}
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	ListNode	listNode;
	ListNode	*head;
	int			insertPos;
	int			val;

	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	listNode.vertexID = toVertexID;
	listNode.edgeWeight = weight;
	listNode.pLink = NULL;
	head = (((pGraph->ppAdjEdge)[fromVertexID])->headerNode).pLink;
	insertPos = 0;
	while (head != NULL && head->vertexID < toVertexID)
	{
		insertPos++;
		head = head->pLink;
	}
	val = addLLElement((pGraph->ppAdjEdge)[fromVertexID], insertPos, listNode);
	if (val == FAIL)
		return (FAIL);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		pGraph->graphType = GRAPH_DIRECTED;
		val = addEdgeLG(pGraph, toVertexID, fromVertexID);
		if (val == FAIL)
			return (FAIL);
		(pGraph->currentEdgeCount)--;
		pGraph->graphType = GRAPH_UNDIRECTED;
	}
	(pGraph->currentEdgeCount)++;
	return (SUCCESS);
}

// 노드의 유효성 점검.
int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
	if (0 <= vertexID && vertexID < pGraph->maxVertexCount)
		return (TRUE);
	return (FALSE);
}

// 노드 제거
int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
	ListNode	*node;
	ListNode	*del;

	if (!checkVertexValid(pGraph, vertexID) || (pGraph->pVertex)[vertexID] == NOT_USED)
		return (FAIL);
	node = (((pGraph->ppAdjEdge)[vertexID])->headerNode).pLink;
	while (node != NULL)
	{
		del = node;
		node = node->pLink;
		removeEdgeLG(pGraph, vertexID, del->vertexID);
	}
	(((pGraph->ppAdjEdge)[vertexID])->headerNode).pLink = NULL;
	(pGraph->currentVertexCount)--;
	(pGraph->pVertex)[vertexID] = NOT_USED;
	return (SUCCESS);
}

// 간선 제거
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	int	delPos;
	int	val;

	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	delPos = findGraphNodePosition((pGraph->ppAdjEdge)[fromVertexID], toVertexID);
	val = removeLLElement((pGraph->ppAdjEdge)[fromVertexID], delPos);
	if (val == FAIL)
		return (FAIL);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		delPos = findGraphNodePosition((pGraph->ppAdjEdge)[toVertexID], fromVertexID);
		val = removeLLElement((pGraph->ppAdjEdge)[toVertexID], delPos);
		if (val == FAIL)
			return (FAIL);
	}
	(pGraph->currentEdgeCount)--;
	return (SUCCESS);
}

// void deleteGraphNode(LinkedList* pList, int delVertexID)
// {

// }

int findGraphNodePosition(LinkedList* pList, int vertexID)
{
	ListNode	*node;
	int			pos;

	node = pList->headerNode.pLink;
	pos = 0;
	while (node != NULL)
	{
		if (node->vertexID == vertexID)
			break ;
		pos++;
		node = node->pLink;
	}
	return (pos);
}

// 간선 개수 반환
int getEdgeCountLG(LinkedGraph* pGraph)
{
	return (pGraph->currentEdgeCount);
}

// 노드 개수 반환
int getVertexCountLG(LinkedGraph* pGraph)
{
	return (pGraph->currentVertexCount);
}

// 최대 노드 개수 반환
int getMaxVertexCountLG(LinkedGraph* pGraph)
{
	return (pGraph->maxVertexCount);
}

// 그래프 종류 반환.
int getGraphTypeLG(LinkedGraph* pGraph)
{
	return (pGraph->graphType);
}

// 그래프 정보 출력
void displayLinkedGraph(LinkedGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		printf("%6s| %d : ", (pGraph->pVertex)[i] == USED ? "Used" : "Unused", i);
		displayLinkedList(pGraph->ppAdjEdge[i]);
		printf("\n");
	}
	printf("[vertexCnt: %d, edgeCnt: %d]\n", pGraph->currentVertexCount, pGraph->currentEdgeCount);
}
