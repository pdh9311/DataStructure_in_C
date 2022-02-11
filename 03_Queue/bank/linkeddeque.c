#include "simlinkeddeque.h"

LinkedDeque* createLinkedDeque()
{
	LinkedDeque *deque = (LinkedDeque *)malloc(sizeof(LinkedDeque));
	if (deque == NULL)
		return (NULL);
	deque->currentElementCount = 0;
	deque->pFrontNode = NULL;
	deque->pRearNode = NULL;
	return (deque);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *addnode;
	DequeNode *prevFront;

	if (pDeque == NULL) {
		printf("%screate deque!!!%s\n", C_RED, C_NC);
		return (FALSE);
	}
	addnode = (DequeNode *)malloc(sizeof(DequeNode));
	if (addnode == NULL)
		return (FALSE);
	*addnode = element;
	prevFront = pDeque->pFrontNode;
	addnode->pRLink = prevFront;
	addnode->pLLink = NULL;
	if (prevFront != NULL)
		prevFront->pLLink = addnode;
	pDeque->pFrontNode = addnode;
	if (pDeque->currentElementCount == 0)
		pDeque->pRearNode = addnode;
	pDeque->currentElementCount++;
	return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *addnode;
	DequeNode *prevRear;

	if (pDeque == NULL) {
		printf("%screate deque!!!%s\n", C_RED, C_NC);
		return (FALSE);
	}
	addnode = (DequeNode *)malloc(sizeof(DequeNode));
	if (addnode == NULL)
		return (FALSE);
	*addnode = element;
	prevRear = pDeque->pRearNode;
	addnode->pLLink = prevRear;
	addnode->pRLink = NULL;
	if (prevRear != NULL)
		prevRear->pRLink = addnode;
	pDeque->pRearNode = addnode;
	if (pDeque->currentElementCount == 0)
		pDeque->pFrontNode = addnode;
	pDeque->currentElementCount++;
	return (TRUE);
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode *del;
	DequeNode *newFront = NULL;

	if (pDeque == NULL) {
		printf("%screate deque!!!%s\n", C_RED, C_NC);
		return (FALSE);
	}
	if (pDeque->currentElementCount == 0) {
		printf("%scurrentElementCount is zero!!%s\n", C_RED, C_NC);
		return (NULL);
	}
	del = pDeque->pFrontNode;
	if (del != NULL)
		newFront = del->pRLink;
	pDeque->pFrontNode = newFront;
	if (newFront != NULL)
		newFront->pLLink = NULL;
	pDeque->currentElementCount--;
	if (pDeque->currentElementCount == 0)
		pDeque->pRearNode = NULL;
	return (del);
}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode *del;
	DequeNode *newRear = NULL;

	if (pDeque == NULL) {
		printf("%screate deque!!!%s\n", C_RED, C_NC);
		return (NULL);
	}
	if (pDeque->currentElementCount == 0) {
		printf("%scurrentElementCount is zero!!%s\n", C_RED, C_NC);
		return (NULL);
	}
	del = pDeque->pRearNode;	// q
	if (del != NULL)
		newRear = del->pLLink;	// NULL
	pDeque->pRearNode = newRear;	//null
	if (newRear != NULL)
		newRear->pRLink = NULL;
	pDeque->currentElementCount--;
	if (pDeque->currentElementCount == 0)
		pDeque->pFrontNode = NULL;
	return (del);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
	if (pDeque == NULL) {
		printf("%screate deque!!!%s\n", C_RED, C_NC);
		return (NULL);
	}
	return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	if (pDeque == NULL) {
		printf("%screate deque!!!%s\n", C_RED, C_NC);
		return (NULL);
	}
	return (pDeque->pRearNode);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode *cur;
	DequeNode *tmp;

	if (pDeque == NULL) {
		printf("%screate deque!!!%s\n", C_RED, C_NC);
		return ;
	}
	cur = pDeque->pFrontNode;
	while (cur != NULL) {
		tmp = cur;
		cur = cur->pRLink;
		free(tmp);
		tmp = NULL;
	}
	free(pDeque);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	if (pDeque == NULL) {
		printf("%screate deque!!!%s\n", C_RED, C_NC);
		return (TRUE);
	}
	if (pDeque->currentElementCount == 0) {
		printf("%scurrentElementCount is zero!!%s\n", C_RED, C_NC);
		return (TRUE);
	}
	return (FALSE);
}

void displayLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode *tmp;

	if (pDeque == NULL) {
		printf("%screate deque!!!%s\n", C_RED, C_NC);
		return ;
	}
	tmp = pDeque->pFrontNode;
	printf("Front ⇄ ");
	while (tmp != NULL) {
		printf("[arrival:%d, sevice:%d, start:%d, end:%d] ", \
			tmp->customer.arrivalTime, tmp->customer.serviceTime \
			, tmp->customer.startTime, tmp->customer.endTime);
		tmp = tmp->pRLink;
	}
	printf("⇄ Rear");
	// printf("\n");
}