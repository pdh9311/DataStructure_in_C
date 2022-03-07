#include "Kruskal.h"


/* union-find */

void initParent(int vertexCount)
{
	for (int i = 0; i < vertexCount; i++)
		parent[i] = i;
}

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
