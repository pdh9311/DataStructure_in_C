#ifndef _DOUBLYLIST_
#define _DOUBLYLIST_

# include <stdio.h>
# include <stdlib.h>

typedef struct DListNodeType
{
	int							data;
	struct DListNodeType*	pLLink;
	struct DListNodeType*	pRLink;
} DListNode;

typedef struct DLinkedListType
{
	int				currentElementCount;	// 현재 저장된 원소의 개수
	DListNode	headerNode;				// 헤더 노드(Header Node)
} DLinkedList;

DLinkedList*		createDoublyList();
void			deleteDoublyList(DLinkedList* pList);
int				addDLElement(DLinkedList* pList, int position, DListNode element);
int				removeDLElement(DLinkedList* pList, int position);
void			clearDoublyList(DLinkedList* pList);
int				getDoublyListLength(DLinkedList* pList);
DListNode*	getDLElement(DLinkedList* pList, int position);
void			displayDoublyList(DLinkedList* pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
