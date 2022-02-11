/* sim이 서비스 선택을 하는 경우와, arrival한 심들의 경우 일단 먼저 en_queue */
#include "bank_test.h"

int arrival_en_queue(queue_node_t* arrival_node, SimCustomer_t* sim)
{
	if (arrival_node->sim_count == 0) {
		arrival_node->head = sim;
		arrival_node->tail = sim;
		sim->next = NULL;
		sim->prev = NULL;
		sim->order_count = 1;
		sim->arrival_time.hour = 9;
		sim->arrival_time.minute = (rand() % 20) + 10;
		sim->servise_time.hour = sim->arrival_time.hour;
		sim->servise_time.minute = sim->arrival_time.minute;
	}
	else {
		if (creat_time(arrival_node, sim) == FALSE) {
			return FALSE;
		}
		sim->prev = arrival_node->tail;
		// sim->next = arrival_node->tail->next;
		sim->next = NULL;
		sim->order_count = arrival_node->tail->order_count + 1;
		arrival_node->tail->next = sim;
		arrival_node->tail = sim;
		sim->servise_time.hour = sim->arrival_time.hour;
		sim->servise_time.minute = sim->arrival_time.minute;
	}
	return TRUE;
}

void servise_en_queue(queue_node_t* arrival_node, queue_node_t* servise)
{
	SimCustomer_t* temp = NULL;
	SimCustomer_t* add = NULL;
	SimCustomer_t* tmp = NULL;
	size_t count = 0;

	if (servise->sim_count == 0) {
		temp = arrival_node->head->next;


		servise->head = arrival_node->head;
		servise->tail = servise->head;

		arrival_node->head = temp;
		servise->head->next = NULL;
		servise->head->prev = NULL;
		servise->sim_count = 1;

		servise->head->servise_time.minute += 30;
		if (servise->head->servise_time.minute % 60 >= 0) {
			servise->head->servise_time.minute %= 60;
			++count;
			servise->head->servise_time.hour += count;
		}
		arrival_node->sim_count -= 1;
	}
	else {

		if (arrival_node->sim_count > 0)
			tmp = arrival_node->head->next;
		else
			tmp = NULL;
		temp = servise->tail;

		add = arrival_node->head;
		add->prev = temp;
		add->next = temp->next;
		temp->next = add;
		servise->tail = add;
		servise->sim_count += 1;

		arrival_node->head = tmp;

		add->servise_time.hour = temp->servise_time.hour;
		add->servise_time.minute = temp->servise_time.minute;

		add->servise_time.minute += 30;
		if (add->servise_time.minute % 60 >= 0) {
			add->servise_time.minute %= 60;
			++count;
			add->servise_time.hour += count;
		}
		arrival_node->sim_count -= 1;
	}
}
