#include "linkeddeque.h"

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
	prevFront->pLLink = addnode;
	pDeque->pFrontNode = addnode;
	if (pDeque->currentElementCount == 0)
		pDeque->pRearNode = addnode;
	pDeque->currentElementCount++;
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *addnode;
	DequeNode *prevRear;

	addnode = (DequeNode *)malloc(sizeof(DequeNode));
	if (addnode == NULL)
		return (FALSE);
	*addnode = element;
	prevRear = pDeque->pRearNode;
	addnode->pLLink = prevRear;
	addnode->pRLink = NULL;
	prevRear->pRLink = addnode;
	pDeque->pRearNode = addnode;


}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{

}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{

}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{

}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{

}

void deleteLinkedDeque(LinkedDeque* pDeque)
{

}

int isLinkedDequeFull(LinkedDeque* pDeque)
{

}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{

}

void displayLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode *tmp;

	if (pDeque == NULL) {
		printf("create deque!!\n");
		return ;
	}
	tmp = pDeque->pFrontNode;
	printf("Front ⇄ ");
	while (tmp != NULL) {
		printf("%c ", tmp->data);
		tmp = tmp->pRLink;
	}
	printf("⇄ Rear\n");
}