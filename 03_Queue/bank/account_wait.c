#include "bank_test.h"
/* 계좌 이체 창구 */
void	account_wait(queue_node_t* add_queue, queue_node_t* arrival, int service_time)
{
	SimCustomer_t* temp = NULL;

	if (add_queue->sim_count == 0){
		temp = de_queue(arrival);
		temp->service_start_time.minute = temp->arrival_time.minute;
		temp->service_start_time.hour = temp->arrival_time.hour;
		temp->service_end_time.minute = temp->service_start_time.minute + service_time;
		temp->service_end_time.hour = temp->service_start_time.hour;
		if (temp->service_end_time.minute / 60 > 0) {
			temp->service_end_time.hour += 1;
			temp->service_end_time.minute %= 60;
		}
		temp->wait_time.minute = 0;
		temp->wait_time.hour = 0;
		en_queue(add_queue, temp);
	}
	else {
		temp = de_queue(arrival);
		if ((temp->arrival_time.hour == add_queue->tail->service_end_time.hour \
			&& temp->arrival_time.minute >= add_queue->tail->service_end_time.minute) \
			|| temp->arrival_time.hour > add_queue->tail->service_start_time.hour)
		{
			temp->service_start_time.hour = temp->arrival_time.hour;
			temp->service_start_time.minute = temp->arrival_time.minute;
		}
		else {
			temp->service_start_time.hour = add_queue->tail->service_end_time.hour;
			temp->service_start_time.minute = add_queue->tail->service_end_time.minute;
		}
		temp->service_end_time.minute = temp->service_start_time.minute + service_time;
		temp->service_end_time.hour = temp->service_start_time.hour;
		if (temp->service_end_time.minute / 60 > 0) {
			temp->service_end_time.hour += 1;
			temp->service_end_time.minute %= 60;
		}
		temp->wait_time.minute = temp->service_start_time.minute - temp->arrival_time.minute;
		temp->wait_time.hour = temp->service_start_time.hour - temp->arrival_time.hour;
		if (temp->wait_time.minute < 0) {
			temp->wait_time.minute += 60;
			temp->wait_time.hour -= 1;
		}
		en_queue(add_queue, temp);
	}
	add_queue->sim_total_wait += ((temp->wait_time.hour * 60) + temp->wait_time.minute);
}