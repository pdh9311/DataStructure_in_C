/* 큐를 삭제하는 함수 (심이 업무 다보고 출발하는 경우) */
#include "bank_test.h"

SimCustomer_t* de_queue(queue_node_t* node)
{
	SimCustomer_t* de = NULL;

	de = node->head;

	node->head = de->next;
	if (node->head != NULL)
		node->head->prev = NULL;

	de->prev = NULL;
	de->next = NULL;
	node->sim_count--;
	return (de);
}