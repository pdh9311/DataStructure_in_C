#ifndef _POLYLIST_
#define _POLYLIST_

#include <stdio.h>
#include <stdlib.h>

typedef struct PListNodeType
{
	float					coef;
	int						degree;
	struct PListNodeType*	pLink;
} PListNode;

typedef struct PLinkedListType
{
	int			currentElementCount;	// 현재 저장된 원소의 개수
	PListNode	headerNode;				// 헤더 노드(Header Node)
} PLinkedList;

PLinkedList*	createLinkedList();												// linkedlist 생성
int				addLLElement(PLinkedList* pList, int position, PListNode element);	// 노드 추가
int				removeLLElement(PLinkedList* pList, int position);					// 노드 제거
PListNode*		getLLElement(PLinkedList* pList, int position);						// 노드 가져오기
void			clearLinkedList(PLinkedList* pList);								// linkedlist 초기화
int				getLinkedListLength(PLinkedList* pList);							// linkedlist 노드의 개수 확인
void			deleteLinkedList(PLinkedList* pList);								// linkedlist free

void			reverseLinkedList(PLinkedList* pList);								// linkedlist 역순

int				addPolyNodeList(PLinkedList* pList, float coef, int degree);
int				addPolyNode(PLinkedList* pList, PLinkedList* temp);
PLinkedList*	addPolyList(PLinkedList* a, PLinkedList* b);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
