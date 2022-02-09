#include "arrayqueue.h"

ArrayQueue* createArrayQueue(int maxElementCount)
{
	ArrayQueue *queue = (ArrayQueue *)malloc(sizeof(ArrayQueue));
	if (queue == NULL)
		return (NULL);
	queue->maxElementCount = maxElementCount;
	queue->currentElementCount = 0;
	queue->front = 0;
	queue->rear = -1;
	queue->pElement = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode) * maxElementCount);
	if (queue->pElement == NULL)
	{
		free(queue);
		queue = NULL;
		return (NULL);
	}
	return (queue);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	int idx;

	if (pQueue == NULL) {
		printf("%screate queue!!!%s\n", C_RED, C_NC);
		return (FALSE);
	}
	if (pQueue->currentElementCount == pQueue->maxElementCount) {
		printf("%sfull queue!!!%s\n", C_RED, C_NC);
		return (FALSE);
	}
	idx = (pQueue->rear + 1) % pQueue->maxElementCount;
	pQueue->pElement[idx] = element;
	pQueue->rear++;
	pQueue->currentElementCount++;
	return (TRUE);
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
	int idx;

	if (pQueue == NULL) {
		printf("%screate queue!!!%s\n", C_RED, C_NC);
		return (NULL);
	}
	if (pQueue->currentElementCount == 0) {
		printf("%scurrentElementCount is zero!!%s\n", C_RED, C_NC);
		return (NULL);
	}
	idx = pQueue->front % pQueue->maxElementCount;
	pQueue->front++;
	pQueue->currentElementCount--;
	return (&pQueue->pElement[idx]);
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
	if (pQueue == NULL) {
		printf("%screate queue!!!%s\n", C_RED, C_NC);
		return (NULL);
	}
	if (pQueue->currentElementCount == 0) {
		printf("%scurrentElementCount is zero!!%s\n", C_RED, C_NC);
		return (NULL);
	}
	return (&pQueue->pElement[pQueue->front % pQueue->maxElementCount]);
}

void deleteArrayQueue(ArrayQueue* pQueue)
{
	if (pQueue == NULL) {
		printf("%screate queue!!!%s\n", C_RED, C_NC);
		return ;
	}
	free(pQueue->pElement);
	pQueue->pElement = NULL;
	free(pQueue);
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
	if (pQueue == NULL) {
		printf("%screate queue!!!%s\n", C_RED, C_NC);
		return (FALSE);
	}
	if (pQueue->currentElementCount == pQueue->maxElementCount)
		return (TRUE);
	return (FALSE);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	if (pQueue == NULL) {
		printf("%screate queue!!!%s\n", C_RED, C_NC);
		return (FALSE);
	}
	if (pQueue->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

void displayArrayQueue(ArrayQueue* pQueue)
{
	int	i;

	if (pQueue == NULL) {
		printf("%screate queue!!!%s\n", C_RED, C_NC);
		return ;
	}
	printf("out ← ");
	for (i = pQueue->front; i < pQueue->front + pQueue->currentElementCount; i++) {
		printf(" %c ", pQueue->pElement[i % pQueue->maxElementCount].data);
	}
	printf(" ← in\n");
}
