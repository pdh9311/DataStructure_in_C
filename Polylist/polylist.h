#ifndef _POLYLIST_
#define _POLYLIST_

#include <stdio.h>
#include <stdlib.h>

typedef struct PolyListNodeType
{
	float						coef;
	int							degree;
	struct PolyListNodeType*	pLink;
} PolyListNode;

typedef struct PolyListType
{
	int				currentElementCount;	// 현재 저장된 원소의 개수
	PolyListNode	headerNode;				// 헤더 노드(Header Node)
} PolyList;

PolyList*		createLinkedList();													// linkedlist 생성
int				addLLElement(PolyList* pList, int position, PolyListNode element);	// 노드 추가
int				removeLLElement(PolyList* pList, int position);						// 노드 제거
PolyListNode*	getLLElement(PolyList* pList, int position);						// 노드 가져오기
void			clearLinkedList(PolyList* pList);									// linkedlist 초기화
int				getLinkedListLength(PolyList* pList);								// linkedlist 노드의 개수 확인
void			deleteLinkedList(PolyList* pList);									// linkedlist free

void			reverseLinkedList(PolyList* pList);									// linkedlist 역순

int				addPolyNode(PolyList* pList, float coef, int degree);				// 계수와 차수를 입력 받아서 앞에서 부터 큰 차수 순서대로 pList에 추가한다.
int				mergePolyList(PolyList* pList, PolyList* temp);						// 새로만들어질 리스트에 temp를 차수에 맞게 넣어준다.
PolyList*		plusPolyList(PolyList* a, PolyList* b);								// 다항식 a, b를 더하여 새로운 리스트를 생성한다.

void			displayLinkedList(PolyList *pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
