#ifndef KRUSKAL_H
# define KRUSKAL_H

# include "linkedgraph.h"

#define MAX_VERTEX 100

typedef struct EdgeType {
	int	fromVertex;
	int	toVertex;
	int	weight;
}	Edge;

typedef struct GraphType {
	int n;	// 간선의 개수
	struct EdgeType *edges;
}	Graph;

// 부모노드 배열 생성.
int parent[MAX_VERTEX];

// 부모노드 초기화
void initParent(int vertexCount);

// 부모노드를 찾는다.
int getParent(int parent[], int x);

// 최상위 부모노드로 합친다.
void unionParent(int parent[], int a, int b);

// 같은 부모노드를 가지고 있는지 확인
int findParent(int parent[], int a, int b);
#endif
