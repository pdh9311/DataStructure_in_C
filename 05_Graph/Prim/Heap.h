#ifndef HEAP_H
# define HEAP_H

# include <stdio.h>
# include <stdlib.h>

# define SIZE 30

typedef struct HeapElementType {
	int	weight;
	int toVertex;
}	HeapElement;

typedef struct HeapType {
	HeapElement *element;
	int heap_size;
}	Heap;

Heap *createHeap(void);
void deleteHeap(Heap *heap);
void insertElement(Heap *heap, int weight, int toVertex);
HeapElement deleteElement(Heap *heap);

void displayHeap(Heap *heap);

#endif
