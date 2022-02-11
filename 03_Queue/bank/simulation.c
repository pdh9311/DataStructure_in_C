#include "simlinkeddeque.h"

void insertCustomer(int arrivalTime, int processTime, LinkedDeque *pDeque)
{
	DequeNode node;

	node.customer.status = arrival;
	node.customer.arrivalTime = arrivalTime;
	node.customer.serviceTime = processTime;
	node.customer.startTime = 0;
	node.customer.endTime = 0;
	insertFrontLD(pDeque, node);
}

void processArrival(int currentTime, LinkedDeque *pArrivalQueue, LinkedDeque *pWaitQueue)
{
	DequeNode *move_to_waitqueue = deleteRearLD(pArrivalQueue);
	DequeNode *last = peekFrontLD(pWaitQueue);	// 마지막 대기자
	DequeNode *first;	// 첫번째 대기자
	DequeNode *banking;

	printf("currentTime: %d\n", currentTime);

	// wait의 마지막 대기자의 endTime을 보고 대기자의 startTime과 endTime을 다시 설정하여 waitqueue에 넣어준다.
	if (last == NULL) {
		move_to_waitqueue->customer.startTime = move_to_waitqueue->customer.arrivalTime;
		move_to_waitqueue->customer.endTime = move_to_waitqueue->customer.startTime + move_to_waitqueue->customer.serviceTime;
		insertFrontLD(pWaitQueue, *move_to_waitqueue);
		free(move_to_waitqueue);
		move_to_waitqueue = NULL;

		// first = peekRearLD(pWaitQueue);
		// if (first->customer.startTime == currentTime) {
		// 	banking = deleteRearLD(pWaitQueue);
		// 	printf("banking .... %d\t ", banking->customer.arrivalTime);
		// 	free(banking);
		// 	banking = NULL;
		// }

		return ;
	}
	move_to_waitqueue->customer.startTime = last->customer.endTime;
	move_to_waitqueue->customer.endTime = move_to_waitqueue->customer.startTime + move_to_waitqueue->customer.serviceTime;
	insertFrontLD(pWaitQueue, *move_to_waitqueue);
	free(move_to_waitqueue);
	move_to_waitqueue = NULL;

	// wait의 첫번째 대기자의 시작 시간이 현재시간과 같으면 waitqueue에서 빼낸다.
	// first = peekRearLD(pWaitQueue);
	// printf("%sfirst %d%s\n", C_AQUA, first->customer.startTime, C_NC);
	// if (first->customer.startTime == currentTime) {
	// 	banking = peekRearLD(pWaitQueue);
	// 	printf("banking .... %d\t ", banking->customer.arrivalTime);
	// 	free(banking);
	// 	banking = NULL;
	// }
}

DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitQueue)
{

}

DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{

}

void printSimCustomer(int currentTime, SimCustomer customer)
{

}

void printWaitQueueStatus(int currentTime, LinkedDeque *pWaitQueue)
{

}

void printReport(LinkedDeque *pWaitQueue, int serviceUserCount, int totalWaitTime)
{

}
