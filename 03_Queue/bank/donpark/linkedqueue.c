#include "linkedqueue.h"

LinkedQueue_t *createLinkedQueue(void)
{
	LinkedQueue_t *queue = (LinkedQueue_t *)malloc(sizeof(LinkedQueue_t));
	if (queue == NULL)
		return (NULL);
	queue->node_count = 0;
	queue->head = NULL;
	queue->tail = NULL;
}