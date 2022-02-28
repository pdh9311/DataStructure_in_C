#include "arraygraph.h"

int main(void)
{
	ArrayGraph *graph = NULL;

	graph = createArrayGraph(1000);

	displayArrayGraph(graph);
	return (0);
}
