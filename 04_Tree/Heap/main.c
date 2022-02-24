#include "Heap.h"

/*
	/////////////////////////
	            9
	       7         6
	    5     4   3     2
	   2 1   3
	/////////////////////////
	            9
	       7         6
	    5     4   3     2
	   2 1   3 8
	/////////////////////////
	            9
	       7         6
	    5     8   3     2
	   2 1   3 4
	/////////////////////////
	            9
	       8         6
	    5     7   3     2
	   2 1   3 4
	/////////////////////////
*/
int main(void)
{
	Heap *heap;

	heap = createHeap();

	insertElement(heap, 9);
	insertElement(heap, 7);
	insertElement(heap, 6);
	insertElement(heap, 5);
	insertElement(heap, 4);
	insertElement(heap, 3);
	insertElement(heap, 2);
	insertElement(heap, 2);
	insertElement(heap, 1);
	insertElement(heap, 3);
	insertElement(heap, 8);
	displayHeap(heap);

	deleteElement(heap);
	displayHeap(heap);

	deleteHeap(heap);
	return (0);
}
