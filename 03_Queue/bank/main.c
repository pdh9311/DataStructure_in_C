#include "linkeddeque.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

/* [ 가정 ]
 * 1초에 한명씩 들어왔다고 가정한다.
 */
int main(void)
{
	LinkedDeque *arrival_queue = createLinkedDeque();
	LinkedDeque *wait_queue = createLinkedDeque();
	int serviceTime = 1;

	for (int i = 0; i < 10; i++) {
		serviceTime = ((double)rand() / RAND_MAX) * (6 - 1) + 1; // 서비스 시간 최소 1초 ~ 최대 5초
		insertCustomer(i, serviceTime, arrival_queue);
	}
	displayLinkedDeque(arrival_queue);
	insertWaitQueue(arrival_queue, wait_queue);
	displayLinkedDeque(arrival_queue);
	displayLinkedDeque(wait_queue);

	int cur_time = 0;
	int end_time = wait_queue->pFrontNode->customer.endTime;
	// end_time = 20;
	DequeNode *node = NULL;
	printf("cur_time: %d, end_time: %d\n\n", cur_time, end_time);
	while (1) {
		if (cur_time - 1 == end_time) {
			printf("은행 업무시간이 다 되어 문을 닫았습니다.\n");
			break ;
		}
		if (node != NULL && node->customer.endTime == cur_time)
			node->customer.status = end;
		if (node != NULL && node->customer.status == end) {
			printf("cur_time: %d\t", cur_time);
			printf("%d 고객의 은행업무를 완료했습니다.\n\n", node->customer.arrivalTime);
			free(node);
			node = NULL;
		} else if (node != NULL && node->customer.endTime == cur_time) {
			node->customer.status = end;
		} else if (node != NULL && node->customer.status == start) {
			printf("cur_time: %d\t", cur_time);
			printf("%d 고객이 은행업무를 보는 중입니다.\n", node->customer.arrivalTime);
		}
		if (node == NULL) {
			node = deleteRearLD(wait_queue);
			if (node == NULL)
				break ;
			node->customer.status = start;
			printf("cur_time: %d\t", cur_time);
			printf("%d 고객이 은행업무를 보길 시작했습니다.\n", node->customer.arrivalTime);
		}
		cur_time++;
		usleep(100 * 1000);
	}
	deleteLinkedDeque(arrival_queue);
	arrival_queue = NULL;
	deleteLinkedDeque(wait_queue);
	wait_queue = NULL;
	return (0);
}
