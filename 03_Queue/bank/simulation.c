#include "linkeddeque.h"

void insertCustomer(int arrivalTime, int serviceTime, LinkedDeque *pDeque)
{
	DequeNode node;

	node.customer.status = arrival;
	node.customer.arrivalTime = arrivalTime;
	node.customer.serviceTime = serviceTime;
	node.customer.startTime = 0;
	node.customer.endTime = 0;
	insertFrontLD(pDeque, node);
}

void insertWaitQueue(LinkedDeque *pArrivalQueue, LinkedDeque *pWaitQueue)
{
	DequeNode *tmp;
	DequeNode *move;
	DequeNode *last;

	tmp = pArrivalQueue->pRearNode;
	while (tmp != NULL) {
		last = peekFrontLD(pWaitQueue);			// 마지막 대기자
		move = deleteRearLD(pArrivalQueue);
		if (last == NULL) {
			move->customer.startTime = move->customer.arrivalTime;	// 시작시간을 도착시간으로 설정
			move->customer.endTime = move->customer.startTime + move->customer.serviceTime;	// 종료시간을 시작시간 + 서비스시간으로 설정
		} else {
			move->customer.startTime = last->customer.endTime;	// 시작시간을 대기큐의 마지막 고객의 종료시간으로 설정
			move->customer.endTime = move->customer.startTime + move->customer.serviceTime;	// 종료시간을 재설정된 시작시간 + 서비스시간으로 설정
		}
		insertFrontLD(pWaitQueue, *move);
		free(move);
		move = NULL;
		tmp = tmp->pLLink;
	}
}
