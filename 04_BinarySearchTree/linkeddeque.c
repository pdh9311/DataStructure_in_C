/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkeddeque.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seseo <seseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:33:09 by seseo             #+#    #+#             */
/*   Updated: 2022/02/21 02:07:01 by seseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkeddeque.h"

LinkedDeque	*createLinkedDeque()
{
	LinkedDeque	*pDeque;

	pDeque = malloc(sizeof(LinkedDeque));
	if (!pDeque)
		return (NULL);
	pDeque->currentElementCount = 0;
	pDeque->pFrontNode = NULL;
	pDeque->pRearNode = NULL;
	return (pDeque);
}

int	insertFrontLD(LinkedDeque *pDeque, DequeNode element)
{
	DequeNode	*pNode;

	if (!pDeque)
		return (FALSE);
	pNode = malloc(sizeof(DequeNode));
	if (!pNode)
		return (FALSE);
	*pNode = element;
	pNode->pLLink = NULL;
	if (isLinkedDequeEmpty(pDeque))
	{
		pNode->pRLink = NULL;
		pDeque->pFrontNode = pNode;
		pDeque->pRearNode = pNode;
	}
	else
	{
		pDeque->pFrontNode->pLLink = pNode;
		pNode->pRLink = pDeque->pFrontNode;
		pDeque->pFrontNode = pNode;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

int	insertRearLD(LinkedDeque *pDeque, DequeNode element)
{
	DequeNode	*pNode;

	if (!pDeque)
		return (FALSE);
	pNode = malloc(sizeof(DequeNode));
	if (!pNode)
		return(FALSE);
	*pNode = element;
	pNode->pRLink = NULL;
	if (isLinkedDequeEmpty(pDeque))
	{
		pNode->pLLink = NULL;
		pDeque->pRearNode = pNode;
		pDeque->pFrontNode = pNode;
	}
	else
	{
		pDeque->pRearNode->pRLink = pNode;
		pNode->pLLink = pDeque->pRearNode;
		pDeque->pRearNode = pNode;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

DequeNode	*deleteFrontLD(LinkedDeque *pDeque)
{
	DequeNode	*pReturn;

	if (!pDeque || isLinkedDequeEmpty(pDeque))
		return (NULL);
	pReturn = pDeque->pFrontNode;
	pDeque->pFrontNode = pReturn->pRLink;
	pReturn->pRLink = NULL;
	if (pDeque->currentElementCount != 1)
		pDeque->pFrontNode->pLLink = NULL;
	else
		pDeque->pRearNode = NULL;
	pDeque->currentElementCount--;
	return (pReturn);
}

DequeNode	*deleteRearLD(LinkedDeque *pDeque)
{
	DequeNode	*pReturn;

	if (!pDeque || isLinkedDequeEmpty(pDeque))
		return (NULL);
	pReturn = pDeque->pRearNode;
	pDeque->pRearNode = pReturn->pLLink;
	pReturn->pLLink = NULL;
	if (pDeque->currentElementCount != 1)
		pDeque->pRearNode->pRLink = NULL;
	else
		pDeque->pFrontNode = NULL;
	pDeque->currentElementCount--;
	return (pReturn);
}

DequeNode	*peekFrontLD(LinkedDeque *pDeque)
{
	if (!pDeque)
		return (NULL);
	return (pDeque->pFrontNode);
}
DequeNode	*peekRearLD(LinkedDeque *pDeque)
{
	if (!pDeque)
		return (NULL);
	return (pDeque->pRearNode);
}

void	deleteLinkedDeque(LinkedDeque *pDeque)
{
	DequeNode	*pDelNode;
	DequeNode	*pNextNode;

	pNextNode = pDeque->pFrontNode;
	while (pNextNode)
	{
		pDelNode = pNextNode;
		pNextNode = pNextNode->pRLink;
		free(pDelNode);
	}
	free(pDeque);
}

// heap 메모리 할당 실패시..?
int	isLinkedDequeFull(LinkedDeque *pDeque)
{
	DequeNode	*pNode;

	if (!pDeque)
		return (FALSE);
	pNode = malloc(sizeof(DequeNode));
	if (!pNode)
		return (TRUE);
	free(pNode);
	return (FALSE);
}

int	isLinkedDequeEmpty(LinkedDeque *pDeque)
{
	if (pDeque->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

// void	displayLinkedDeque(LinkedDeque *pDeque)
// {
// 	DequeNode	*tmpNode;

// 	printf("[");
// 	if (isLinkedDequeEmpty(pDeque))
// 		printf("]");
// 	else
// 	{
// 		tmpNode = pDeque->pFrontNode;
// 		while (tmpNode->pRLink)
// 		{
// 			printf("%c, ", tmpNode->data);
// 			tmpNode = tmpNode->pRLink;
// 		}
// 		printf("%c]", tmpNode->data);
// 	}
// }
