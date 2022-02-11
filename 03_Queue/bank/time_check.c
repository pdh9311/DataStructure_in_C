/* 현재 창구에 sim이 업무를 보고 있는지 체크. 만약 있다면 기다렸다가 업무 진행 */
#include "bank_test.h"

int time_check(SimCustomer_t* node, SimCustomer_t* servise)
{
	if (node->arrival_time.hour > servise->servise_time.hour) {
		return TRUE;
	}
	else if (node->arrival_time.hour == servise->servise_time.hour || \
			node->arrival_time.minute >= servise->servise_time.minute) {
		// node->arrivalarrival_time.hour >= servise->head->servise_time.hour &&\
		// 	servise->tail->arrival_time.minute > servise->head->servise_time.minute) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int print_check(hour_minute_t* count, queue_node_t* servise)
{
	if (count->hour == servise->head->servise_time.hour \
		&& count->minute >= servise->head->servise_time.minute) {
			 return TRUE;
	 }
	else
		return FALSE;
}
