#include "simlinkeddeque.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void displayArrivalServiceTime(LinkedDeque* pDeque)
{
	DequeNode *tmp;

	if (pDeque == NULL) {
		printf("%screate deque!!!%s\n", C_RED, C_NC);
		return ;
	}
	tmp = pDeque->pFrontNode;
	printf("Front ");
	while (tmp != NULL) {
		printf("%d_%d ", tmp->customer.arrivalTime, tmp->customer.serviceTime);
		// printf("[%d, %d] ", tmp->customer.arrivalTime, tmp->customer.serviceTime);
		// printf("[%d, %d] ", tmp->customer.startTime, tmp->customer.endTime);
		// printf("[%d, %d, %d, %d] ", tmp->customer.arrivalTime, tmp->customer.serviceTime \
		// 		, tmp->customer.startTime, tmp->customer.endTime);
		tmp = tmp->pRLink;
	}
	printf(" Rear");
	// printf("⇄ Rear%s", C_NC);
	printf("\n");
}

void displayStartEndTime(LinkedDeque* pDeque)
{
	DequeNode *tmp;

	if (pDeque == NULL) {
		printf("%screate deque!!!%s\n", C_RED, C_NC);
		return ;
	}
	tmp = pDeque->pFrontNode;
	// printf("Front ⇄ ");
	printf("Front ");
	while (tmp != NULL) {
		printf("%d_%d ", tmp->customer.startTime, tmp->customer.endTime);
		// printf("[%d, %d] ", tmp->customer.startTime, tmp->customer.endTime);
		tmp = tmp->pRLink;
	}
	printf(" Rear");
	// printf("⇄ Rear");
	// printf("\n");
}

/* [ 가정 ]
 * 1초에 한명씩 들어온다.
 */
int main(void)
{
	LinkedDeque *arrival_queue = createLinkedDeque();
	LinkedDeque *wait_queue = createLinkedDeque();
	int cur_time = 0;
	int end_time = 10;
	SimCustomer customer;
	int processTime = 1;
	// int random;
	// srand(time(NULL));


	while (1)
	{
		if (cur_time == end_time)
			break ;

		processTime = ((double)rand() / RAND_MAX) * (6 - 1) + 1; // 서비스 시간 최소 1초 ~ 최대 5초
		insertCustomer(cur_time, processTime, arrival_queue);
// displayArrivalServiceTime(arrival_queue);
		processArrival(cur_time, arrival_queue, wait_queue);

// displayStartEndTime(arrival_queue);
// printf("          ");
// displayStartEndTime(wait_queue);
		cur_time++;
		sleep(1);
		printf("\n\n");
	}
	return (0);
}