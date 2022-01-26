#ifndef _CIRCULARL_LINKEDLIST_
# define _CIRCULARL_LINKEDLIST_

# include <stdio.h>
# include <stdlib.h>

typedef struct CListNodeType
{
	int						data;
	struct CListNodeType*	pLink;
} CListNode;

typedef struct CLinkedListType
{
	int			currentElementCount;	// 현재 저장된 원소의 개수
	CListNode	headerNode;				// 헤더 노드(Header Node)
} CLinkedList;

CLinkedList*	createLinkedList();												// linkedlist 생성
int				addLLElement(CLinkedList* pList, int position, CListNode element);	// 노드 추가
int				removeLLElement(CLinkedList* pList, int position);					// 노드 제거
CListNode*		getLLElement(CLinkedList* pList, int position);						// 노드 가져오기
void			clearLinkedList(CLinkedList* pList);								// linkedlist 초기화
int				getLinkedListLength(CLinkedList* pList);							// linkedlist 노드의 개수 확인
void			deleteLinkedList(CLinkedList* pList);								// linkedlist free

int				moveHeaderNode(CLinkedList *pList, int position);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
