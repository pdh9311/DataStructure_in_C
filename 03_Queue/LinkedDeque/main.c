#include "linkeddeque.h"

int main(void)
{
	LinkedDeque *deque = NULL;
	DequeNode node;
	int select;
	char data;

	while (1) {
		printf("%s0: EXIT | 1: create | 2: insertFront | 3: insertRear | 4: deleteFront | 5: deleteRear | 6: peekFront | 7: peekRear | 8: delete | 9: display%s\n%s> %s", C_AQUA, C_NC, C_GREEN, C_NC);
		scanf("%d", &select); fflush(stdin);
		switch (select) {
			case 0:
				exit(0);
				break ;
			case 1:
				if (deque == NULL) {
					deque = createLinkedDeque();
				} else {
					printf("already created deque\n");
				}
				break ;
			case 2:
				printf("ADD data: ");
				scanf("%c", &data); fflush(stdin);
				node.data = data;
				insertFrontLD(deque, node);
				break ;
			case 3:
				break ;
			case 4:
				break ;
			case 5:
				break ;
			case 6:
				break ;
			case 7:
				break ;
			case 8:
				break ;
			case 9:
				displayLinkedDeque(deque);
				break ;
		}
		printf("\n");
	}

	return (0);
}