/* sim이 서비스 선택을 하는 경우와, arrival한 심들의 경우 일단 먼저 en_queue */
#include "bank_test.h"

int en_queue(queue_node_t* node, SimCustomer_t* sim)
{
	if (node == NULL || sim == NULL)
		return FALSE;
	if (node->sim_count == 0) {
		node->head = sim;
		node->tail = sim;
	}
	else {
		sim->prev = node->tail;
		node->tail->next = sim;
		node->tail = sim;
	}
	node->sim_count++;
	return TRUE;
}