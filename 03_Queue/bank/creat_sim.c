#include "bank_test.h"

/* sim이 하나씩 생성 */

int creat_time(queue_node_t* node, SimCustomer_t* new_sim)
{
	size_t count = 0;

	new_sim->arrival_time.hour = node->tail->arrival_time.hour;
	new_sim->arrival_time.minute = (rand() % 20) + 10;
	new_sim->arrival_time.minute += node->tail->arrival_time.minute;

	if (new_sim->arrival_time.minute >= 60) {
		new_sim->arrival_time.minute -= 60;
		++count;
		new_sim->arrival_time.hour += count;
	}
	if (new_sim->arrival_time.hour >= 15 && new_sim->arrival_time.minute > 30) {
		return FALSE;
	}
	return TRUE;
}

SimCustomer_t* creat_sim(queue_node_t* node)
{
	SimCustomer_t* new = NULL;
	size_t size = size;

	new = (SimCustomer_t*)malloc(sizeof(SimCustomer_t));
	if (new == NULL) {
		return NULL;
	}
	new->servise_time.hour = 0;
	new->servise_time.minute = 0;
	new->next = NULL;
	new->prev = NULL;
	if(arrival_en_queue(node, new) == FALSE) {
		free(new);
		new = NULL;
		return (NULL);
	}
	node->sim_count++;
	return new;
}
