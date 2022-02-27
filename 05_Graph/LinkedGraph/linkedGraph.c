#include "linkedgraph.h"

// 그래프 생성
LinkedGraph* createLinkedGraph(int maxVertexCount);
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount);

// 그래프 삭제
void deleteLinkedGraph(LinkedGraph* pGraph);

// 공백 그래프 여부 판단
int isEmptyLG(LinkedGraph* pGraph);

// 노드 추가
int addVertexLG(LinkedGraph* pGraph, int vertexID);

// 간선 추가
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);

// 노드의 유효성 점검.
int checkVertexValid(LinkedGraph* pGraph, int vertexID);

// 노드 제거
int removeVertexLG(LinkedGraph* pGraph, int vertexID);

// 간선 제거
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
void deleteGraphNode(LinkedList* pList, int delVertexID);
int findGraphNodePosition(LinkedList* pList, int vertexID);

// 간선 개수 반환
int getEdgeCountLG(LinkedGraph* pGraph);

// 노드 개수 반환
int getVertexCountLG(LinkedGraph* pGraph);

// 최대 노드 개수 반환
int getMaxVertexCountLG(LinkedGraph* pGraph);

// 그래프 종류 반환.
int getGraphTypeLG(LinkedGraph* pGraph);

// 그래프 정보 출력
void displayLinkedGraph(LinkedGraph* pGraph);
