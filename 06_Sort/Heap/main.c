#include "heap.h"
#include <time.h>

/*
	/////////////////////////
	            1
	       4         2
	    7     5   3     3
	   7 8   9
	/////////////////////////
	insertElement(heap, 1);
	insertElement(heap, 4);
	insertElement(heap, 2);
	insertElement(heap, 7);
	insertElement(heap, 5);
	insertElement(heap, 3);
	insertElement(heap, 3);
	insertElement(heap, 7);
	insertElement(heap, 8);
	insertElement(heap, 9);
	/////////////////////////
*/
int main(void)
{
	Heap *heap;

	srand(time(NULL));
	heap = createHeap();

	printf("========= init ascending =========\n");
	for (int i = 0; i < 10; i++)
		insertElement(heap, rand() % 100);
	displayHeap(heap);
	printf("========= ascending sort =========\n");
	heapSort(heap, UP_SORT);

	printf("\n");

	printf("========= init descending =========\n");
	for (int i = 0; i < 10; i++)
		insertElement(heap, -(rand() % 100));
	displayHeap(heap);
	printf("========= descending sort =========\n");
	heapSort(heap, DONW_SORT);
	return (0);
}
