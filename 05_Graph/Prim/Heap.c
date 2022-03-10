#include "Heap.h"

Heap *createHeap(void) {
	Heap *heap = NULL;

	heap = (Heap *)malloc(sizeof(Heap));
	if (heap == NULL)
		return (NULL);
	heap->element = (HeapElement *)malloc(sizeof(HeapElement) * SIZE);
	if (heap->element == NULL) {
		free(heap);
		heap = NULL;
		return (NULL);
	}
	heap->heap_size = 0;
	return (heap);
}

void deleteHeap(Heap *heap) {
	if (heap == NULL) {
		printf("please create!\n");
		return ;
	}
	free(heap->element);
	heap->element = NULL;
	free(heap);
}

static HeapElement *newElementArray(Heap *heap) {
	HeapElement *tmp;
	int i;

	tmp = (HeapElement *)malloc(sizeof(HeapElement) * (heap->heap_size + SIZE));
	if (tmp == NULL)
		return (NULL);
	for (i = 1; i < heap->heap_size; i++)
		tmp[i] = heap->element[i];
	free(heap->element);
	return (tmp);
}

void insertElement(Heap *heap, int weight, int toVertex) {
	int i;
	HeapElement element;
	HeapElement tmp;

	(heap->heap_size)++;
	if (heap->heap_size % 30 == 0)
		heap->element = newElementArray(heap);
	i = heap->heap_size;
	element.weight = weight;
	element.toVertex = toVertex;
	heap->element[i] = element;
	while (i != 1  && heap->element[i].weight > heap->element[i / 2].weight) {	// 루트노드가 아니고 부모노드의 값보다 크면 반복
		tmp = heap->element[i];
		heap->element[i] = heap->element[i / 2];
		heap->element[i / 2] = tmp;
		i /= 2;
	}
}

HeapElement deleteElement(Heap *heap) {
	HeapElement del;
	HeapElement tmp;
	int parent;
	int child;

	del = heap->element[1];
	tmp = heap->element[(heap->heap_size)--];
	parent = 1;
	child = parent * 2;
	while (child <= heap->heap_size) {
		if ((child < heap->heap_size) && \
			(heap->element[child].weight < heap->element[child + 1].weight))
			child++;
		if (tmp.weight >= heap->element[child].weight)
			break ;
		heap->element[parent] = heap->element[child];
		parent = child;
		child = parent * 2;
	}
	heap->element[parent] = tmp;
	return (del);
}

void displayHeap(Heap *heap) {
	int i;

	printf("(%d) ", heap->heap_size);
	for (i = 1; i <= heap->heap_size; i++)
		printf("%d ", heap->element[i].weight);
	printf("\n");
}
