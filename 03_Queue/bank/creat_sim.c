#include "bank_test.h"

/* sim이 하나씩 생성 */

queue_node_t* creat_simqueue()
{
	queue_node_t* ptr = NULL;

	ptr = malloc(sizeof(queue_node_t));
	if (ptr == NULL)
	{
		return NULL;
	}

	ptr->sim_count = 0;
	ptr->head = NULL;
	ptr->tail = NULL;
	ptr->sim_total_wait = 0;

	return ptr;
}

SimCustomer_t* creat_sim(hour_minute_t time, int order, int service)
{
	SimCustomer_t* ptr = NULL;

	ptr = malloc(sizeof(SimCustomer_t));
	if (ptr == NULL)
	{
		return NULL;
	}

	ptr->arrival_time.hour = time.hour;
	ptr->arrival_time.minute = time.minute;
	ptr->order_count = order;
	ptr->service = service;

	ptr->next = NULL;
	ptr->prev = NULL;

	ptr->service_start_time.hour = 0;
	ptr->service_start_time.minute = 0;
	ptr->service_end_time.hour = 0;
	ptr->service_end_time.minute = 0;
	ptr->wait_time.hour = 0;
	ptr->wait_time.minute = 0;

	return ptr;

}