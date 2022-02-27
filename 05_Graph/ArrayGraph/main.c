#include "arraygraph.h"

int main(void)
{
	ArrayGraph *graph = NULL;

	graph = createArrayGraph(10);

	displayArrayGraph(graph);
	return (0);
}
