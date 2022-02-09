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

}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{

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

}