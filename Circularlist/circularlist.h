#ifndef _CIRCULARLIST_
#define _CIRCULARLIST_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct CircularNodeType
{
	int							data;
	struct CircularNodeType*	pLink;
} CircularNode;

typedef struct CircularListType
{
	int				currentElementCount;	// 현재 저장된 원소의 개수
	CircularNode	headerNode;				// 헤더 노드(Header Node)
} CircularList;

CircularList*	createCircularList();													// Circularlist 생성
int				addCLElement(CircularList* pList, int position, CircularNode element);	// 노드 추가
int				removeCLElement(CircularList* pList, int position);						// 노드 제거
CircularNode*	getCLElement(CircularList* pList, int position);						// 노드 가져오기
void			clearCircularList(CircularList* pList);									// Circularlist 초기화
int				getCircularListLength(CircularList* pList);								// Circularlist 노드의 개수 확인
void			deleteCircularList(CircularList* pList);								// Circularlist free

CircularNode*	getLastCLElement(CircularList* pList);
void			displayCircularList(CircularList *pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
