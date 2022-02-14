#include "bank_test.h"


void print_lst(queue_node_t *node)
{
	SimCustomer_t *cur;

	cur = node->head;
	if (node->head != NULL) {
		if (node->head->service == DEPOSIT_E)
			printf("deposit");
		else if (node->head->service == WITHDRAW_E)
			printf("withdraw");
		else if (node->head->service == TRANSFE_E)
			printf("transfe");
		else if (node->head->service == CONSULT_E)
			printf("consult");
	}
	printf(" ----------------------------------\n");
	while (cur != NULL) {
		printf("%2d ", cur->order_count);
		printf("[%d] ", cur->service);
		printf("(arrival %2d : %2d) ", cur->arrival_time.hour, cur->arrival_time.minute);
		printf("(start %2d : %2d) ", cur->service_start_time.hour, cur->service_start_time.minute);
		printf("(end %2d : %2d) ", cur->service_end_time.hour, cur->service_end_time.minute);
		printf("(wait %2d : %2d)\n", cur->wait_time.hour, cur->wait_time.minute);
		cur = cur->next;
	}
	printf("------------------------------------------\n\n");
}

void print_avg(queue_node_t *node)
{
	double avg = (double)node->sim_total_wait / node->sim_count;
	printf("wait time : %f", avg);
	if (avg > 30) {
		printf("\n불만족\n");
	}
	else {
		printf("\n만족\n");
	}
}

int main(void)
{
	srand(time(NULL));

	queue_node_t* arrival_queue = NULL;
	queue_node_t* deposit_queue= NULL;
	queue_node_t* withdraw_queue = NULL;
	queue_node_t* transfe_queue = NULL;
	queue_node_t* consult_queue = NULL;

	SimCustomer_t* sim = NULL;
	hour_minute_t time_t;

	SimCustomer_t* cur;
	SimCustomer_t* tmp;
	int order = 0;
	arrival_queue = creat_simqueue();

	// arrival

	time_t.hour = 9;
	time_t.minute = 0;
	while (1)
	{
		time_t.minute += ((rand() % 11) + 10);
		if (time_t.minute / 60 > 0) {
			time_t.hour += 1;
			time_t.minute %= 60;
		}
		if (time_t.hour == 15 && time_t.minute > 30){
			break;
		}
		order += 1;
		sim = creat_sim(time_t, order, rand() % 4);
		en_queue(arrival_queue, sim);
	}
	print_lst(arrival_queue);
	printf("\n");

	// wait and service


	deposit_queue = creat_simqueue();
	withdraw_queue = creat_simqueue();
	transfe_queue = creat_simqueue();
	consult_queue = creat_simqueue();


	cur = arrival_queue->head;
	while (cur != NULL) {
		tmp = cur->next;
		if (arrival_queue->head->service == DEPOSIT_E) {
			account_wait(deposit_queue, arrival_queue, (rand() % 28) + 20);
		} else if (arrival_queue->head->service == WITHDRAW_E) {
			account_wait(withdraw_queue, arrival_queue, (rand() % 31) + 30);
		} else if (arrival_queue->head->service == TRANSFE_E) {
			account_wait(transfe_queue, arrival_queue, (rand() % 33) + 20);
		} else if (arrival_queue->head->service == CONSULT_E) {
			account_wait(consult_queue, arrival_queue, (rand() % 45) + 40);
		}
		cur = tmp;
	}
	print_lst(arrival_queue);
	print_lst(deposit_queue);
	print_lst(withdraw_queue);
	print_lst(transfe_queue);
	print_lst(consult_queue);

	printf("deposit ");
	print_avg(deposit_queue);
	printf("withdraw ");
	print_avg(withdraw_queue);
	printf("transfe ");
	print_avg(transfe_queue);
	printf("consult ");
	print_avg(consult_queue);

}