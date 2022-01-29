#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_

# include <stdio.h>
# include <stdlib.h>

typedef struct ArrayStackNodeType {
	char	data;
} ArrayStackNode;

typedef struct ArrayStackType {
	int				maxElementCount;		// 최대 노드 개수
	int				currentElementCount;	// 현재 노드 개수
	ArrayStackNode	*pElement;				// 원소 저장을 위한 배열 포인터
} ArrayStack;

ArrayStack*		createArrayStack(int maxElementCount);				// stack 생성
int				pushAS(ArrayStack* pStack, ArrayStackNode element);	// push (stack에 추가)
ArrayStackNode*	popAS(ArrayStack* pStack);							// pop (stack에서 제거)
ArrayStackNode*	peekAS(ArrayStack* pStack);							// peek (stack의 top에 있는 노드 확인)
void			deleteArrayStack(ArrayStack* pStack);				// stack 해제
int				isArrayStackFull(ArrayStack* pStack);				// stack 가득찼는지 확인
int				isArrayStackEmpty(ArrayStack* pStack);				// stack 비었는지 확인

void			displayArrayStack(ArrayStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif