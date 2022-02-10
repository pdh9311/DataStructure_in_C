#include "arrayqueue.h"

void testcode(ArrayQueue *queue)
{
	if (queue == NULL)
		return ;
	printf("---------------------------------------\n");
	printf("front: %d, rear: %d, cur: %d, max: %d\n",
					queue->front, queue->rear, queue->currentElementCount, queue->maxElementCount);
	displayArrayQueue(queue);
	printf("---------------------------------------\n");
}

int main(void)
{
	ArrayQueue *queue = NULL;
	ArrayQueueNode node;
	int	select;
	int max;
	char data;
	ArrayQueueNode *tmp = NULL;

	while (1) {
		printf("%s0: EXIT | 1: create | 2: enqueue | 3: dequeue | 4: peek | 5: delete | 6: display\n%s%sinput > %s", C_AQUA, C_NC, C_GREEN, C_NC);
		scanf("%d", &select);	fflush(stdin);

		switch(select) {
			case 0 :	// exit
				exit(0);
				break;
			case 1 :	// create
				if (queue != NULL) {
					printf("%salready created%s\n", C_RED, C_NC);
					break ;
				}
				printf("maxElementCount: ");
				scanf("%d", &max);	fflush(stdin);
				queue = createArrayQueue(max);
testcode(queue);
				break;
			case 2 :	// enqueue
				printf("ADD data: ");
				scanf("%c", &data);	fflush(stdin);
				node.data = data;
				enqueueAQ(queue, node);
testcode(queue);
				break;
			case 3 :	// dequeue
				tmp = dequeueAQ(queue);
				if (tmp != NULL)
					printf("dequeue data: %c\n", tmp->data);
testcode(queue);
				break;
			case 4 :	// peek
				tmp = peekAQ(queue);
				if (tmp != NULL)
					printf("peek data: %c\n", tmp->data);
testcode(queue);
				break;
			case 5 :	// delete
				deleteArrayQueue(queue);
				queue = NULL;
				break;
			case 6 :	// display
				displayArrayQueue(queue);
testcode(queue);
				break;
		}
		printf("\n");
	}
	return (0);
}