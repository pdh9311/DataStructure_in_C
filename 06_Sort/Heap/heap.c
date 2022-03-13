#include "heap.h"

Heap *createHeap(void) {
	Heap *heap = NULL;

	heap = (Heap *)malloc(sizeof(Heap));
	if (heap == NULL)
		return (NULL);
	heap->element = (HeapElement *)calloc(sizeof(HeapElement), SIZE);
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

	tmp = (HeapElement *)calloc(sizeof(HeapElement), (heap->heap_size + SIZE));
	if (tmp == NULL)
		return (NULL);
	for (i = 1; i < heap->heap_size; i++)
		tmp[i] = heap->element[i];
	free(heap->element);
	return (tmp);
}

void insertElement(Heap *heap, int key) {
	int child, parent;
	HeapElement element;
	HeapElement tmp;

	// 초기 heap_size가 0 이기때문에 1부터 값을 저장하기 위해서 heap_size를 먼저 증가시켜줌.
	(heap->heap_size)++;
	if (heap->heap_size % 30 == 0)
		heap->element = newElementArray(heap);
	child = heap->heap_size;		// heap의 마지막 인덱스
	element.key = key;
	heap->element[child] = element;	// heap의 마지막에 삽입
	parent = child / 2;				// 삽입된 노드의 '부모노드의 인덱스'
	// 삽입된 값(child)이 부모노드(parent)의 값보다 작으면 교환을 반복 (i가 1이 아닐때 까지)
	while (child != 1  && heap->element[child].key < heap->element[parent].key) {
		tmp = heap->element[child];
		heap->element[child] = heap->element[parent];
		heap->element[parent] = tmp;
		// printf("child: %d, parent: %d\n" ,heap->element[child].key, heap->element[parent].key);
		child /= 2;
		parent = child / 2;
	}
}

HeapElement deleteElement(Heap *heap) {
	HeapElement del;
	HeapElement tmp;
	int parent;
	int child;

	del = heap->element[1];	// 삭제할 루트노드를 임시로 저장해둠.
	tmp = heap->element[(heap->heap_size)--];	// 마지막 노드를 임시저장하고 힙 크기 감소.
	parent = 1;
	child = parent * 2;

	while (child <= heap->heap_size) {
		// 자식 중 더 작은 값이 루트노드가 되어야 하기 때문에
		// 먼저 자식 중 더 작은 값과 교환하기 위해서, 자식 중 더 작은 값을 찾는다.
		if ((child < heap->heap_size) && \
			(heap->element[child].key > heap->element[child + 1].key))
			child++;
		// 부모의 키값이 자식의 키 보다 작거나 같다면 반복을 종료
		if (tmp.key <= heap->element[child].key) break ;
		// 그렇지 않다면 부모와 자식의 값을 교환
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
		printf("%d ", heap->element[i].key);
	printf("\n");
}


void heapSort(Heap *heap, int sortType) {
	HeapElement tmp;

	while (heap->heap_size != 0) {
		tmp = deleteElement(heap);
		if (sortType == DONW_SORT)
			printf("%d ", -tmp.key);
		else
			printf("%d ", tmp.key);
	}
	printf("\n");
}
