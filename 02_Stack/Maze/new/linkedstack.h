#ifndef _LINKED_STACK_
#define _LINKED_STACK_

#include <stdio.h>
#include <stdlib.h>

typedef struct MapPositionType
{
	int x;				// 현재 위치 x좌표.
	int y;				// 현재 위치 y좌표.
	// int direction;		// 다음 위치로 이동 방향 
} MapPosition;

typedef struct StackNodeType
{
	MapPosition data;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;	// 현재 노드 개수
	StackNode* pTopElement;		// Top 노드에 대한 포인터
} LinkedStack;
 
LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
//int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);
void displayLinkedStack(LinkedStack* pStack);
#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif