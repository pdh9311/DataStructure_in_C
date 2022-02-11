#ifndef _SIMLINKED_DEQUE_
#define _SIMLINKED_DEQUE_

# include <stdio.h>
# include <stdlib.h>
# include "color.h"

typedef enum SimStatusType { arrival, start, end } SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime;	// 도착 시각.
	int serviceTime;	// 서비스 시간.
	int startTime;		// 시작 시간.
	int endTime;		// 종료 시각: 시작 시각 + 서비스 시간.
} SimCustomer;

typedef struct DequeNodeType
{
	SimCustomer customer;
	struct DequeNodeType* pRLink;
	struct DequeNodeType* pLLink;
} DequeNode;

typedef struct LinkedDequeType
{
	int currentElementCount;	// 현재 원소의 개수
	DequeNode* pFrontNode;		// Front 노드의 포인터
	DequeNode* pRearNode;		// Rear 노드의 포인터
} LinkedDeque;

/* linkeddeque */
LinkedDeque* createLinkedDeque();
int insertFrontLD(LinkedDeque* pDeque, DequeNode element);
int insertRearLD(LinkedDeque* pDeque, DequeNode element);
DequeNode* deleteFrontLD(LinkedDeque* pDeque);
DequeNode* deleteRearLD(LinkedDeque* pDeque);
DequeNode* peekFrontLD(LinkedDeque* pDeque);
DequeNode* peekRearLD(LinkedDeque* pDeque);
void deleteLinkedDeque(LinkedDeque* pDeque);
// int isLinkedDequeFull(LinkedDeque* pDeque);
int isLinkedDequeEmpty(LinkedDeque* pDeque);
void displayLinkedDeque(LinkedDeque* pDeque);

/* simulation */
void insertCustomer(int arrivalTime, int serviceTime, LinkedDeque *pDeque);
void insertWaitQueue(LinkedDeque *pArrivalQueue, LinkedDeque *pWaitQueue);
/*
void insertCustomer(int arrivalTime, int processTime, LinkedDeque *pDeque);
void processArrival(int currentTime, LinkedDeque *pArrivalQueue, LinkedDeque *pWaitQueue);
DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitQueue);
DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime);
void printSimCustomer(int currentTime, SimCustomer customer);
void printWaitQueueStatus(int currentTime, LinkedDeque *pWaitQueue);
void printReport(LinkedDeque *pWaitQueue, int serviceUserCount, int totalWaitTime);
*/
#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif
