#include "linkeddeque.h"

void testcode(LinkedDeque *deque)
{
	if (deque == NULL)
		return ;
	printf("---------------------------------------\n");
	printf("cur: %d\n", deque->currentElementCount);
	displayLinkedDeque(deque);
	printf("---------------------------------------\n");
}

int main(void)
{
	LinkedDeque *deque = NULL;
	DequeNode node;
	int select;
	char data;
	DequeNode *tmp = NULL;

	while (1) {
		printf("%s0: EXIT | 1: create | 2: insertFront | 3: insertRear | 4: deleteFront | 5: deleteRear | 6: peekFront | 7: peekRear | 8: delete | 9: display%s\n%s> %s", C_AQUA, C_NC, C_GREEN, C_NC);
		scanf("%d", &select); fflush(stdin);
		switch (select) {
			case 0:	// exit
				exit(0);
				break ;
			case 1:	// create
				if (deque == NULL) {
					deque = createLinkedDeque();
				} else {
					printf("%salready created%s\n", C_RED, C_NC);
				}
				break ;
testcode(deque);
			case 2:	// insertFront
				printf("Front ADD data: ");
				scanf("%c", &data); fflush(stdin);
				node.data = data;
				insertFrontLD(deque, node);
testcode(deque);
				break ;
			case 3:	// insertRear
				printf("Rear ADD data: ");
				scanf("%c", &data); fflush(stdin);
				node.data = data;
				insertRearLD(deque, node);
testcode(deque);
				break ;
			case 4:	// deleteFront
				tmp = deleteFrontLD(deque);
				if (tmp != NULL) {
					printf("deque front del data: %c\n", tmp->data);
					free(tmp);
				}
testcode(deque);
				break ;
			case 5:	// deleteRear
				tmp = deleteRearLD(deque);
				if (tmp != NULL) {
					printf("deque rear del data: %c\n", tmp->data);
					free(tmp);
				}
testcode(deque);
				break ;
			case 6:	// peekFront
				tmp = peekFrontLD(deque);
				if (tmp != NULL)
					printf("peek front data: %c\n", tmp->data);
testcode(deque);
				break ;
			case 7:	// peekRear
				tmp = peekRearLD(deque);
				if (tmp != NULL)
					printf("peek rear data: %c\n", tmp->data);
testcode(deque);
				break ;
			case 8:	// delete
				deleteLinkedDeque(deque);
				deque = NULL;
				break ;
			case 9:	// display
				displayLinkedDeque(deque);
testcode(deque);
				break ;
		}
		printf("\n");
	}

	return (0);
}