#ifndef HEAP_H
# define HEAP_H

# include <stdio.h>
# include <stdlib.h>

# define SIZE 30
# define UP_SORT 1
# define DONW_SORT 2

typedef struct HeapElementType {
	int key;
}	HeapElement;

typedef struct HeapType {
	HeapElement *element;
	int heap_size;
}	Heap;

Heap *createHeap(void);
void deleteHeap(Heap *heap);
void insertElement(Heap *heap, int key);
HeapElement deleteElement(Heap *heap);
void displayHeap(Heap *heap);

void heapSort(Heap *heap, int sortType);

#endif
