#include "bank_test.h"

void print_service(queue_node_t *node)
{
	SimCustomer_t *cur;

	cur = node->head;
	while (cur != NULL) {
		printf("order_count: %d\t", cur->order_count);
		printf("arrival_time: %d:%d\t", cur->arrival_time.hour, cur->arrival_time.minute);
		printf("service_time: %d:%d\n", cur->servise_time.hour, cur->servise_time.minute);
		cur = cur->next;
	}
}

void print_lst(queue_node_t *node)
{
	SimCustomer_t *cur;

	cur = node->head;
	printf("------------------------------------------\n");
	printf("| ");
	while (cur != NULL) {
		printf("%d ", cur->order_count);
		cur = cur->next;
	}
	printf("|\n");
	printf("------------------------------------------\n");
}

int main(void)
{
	srand(time(NULL));

	queue_node_t arrival;
	queue_node_t deposit;
	queue_node_t transfe;
	queue_node_t consult;
	queue_node_t withdraw;
	hour_minute_t count;
	SimCustomer_t* node;
	int servise_num = 0;
	int print_temp[256] = {0, };
	int selec_next = 0;
	int sum = 0;
	size_t i = 0;
	// size_t j = 0;
	size_t action = 0;


	arrival.head = NULL;
	arrival.tail = NULL;
	arrival.sim_count = 0;

	deposit.head = NULL;
	deposit.tail = NULL;
	deposit.sim_count = 0;

	transfe.head = NULL;
	transfe.tail = NULL;
	transfe.sim_count = 0;

	withdraw.head = NULL;
	withdraw.tail = NULL;
	withdraw.sim_count = 0;

	consult.head = NULL;
	consult.tail = NULL;
	consult.sim_count = 0;

	while (1)
	{
		if ((node = creat_sim(&arrival)) == NULL)
		{
			break;
		}
		else {
			arrival.tail = node;
		}
	}
	while (1){
		servise_num = (rand() % 4);
		if (servise_num == DEPOSIT_E) {
			servise_en_queue(&arrival, &deposit);
			if (arrival.sim_count == 0) {
				break;
			}
		}
		else if (servise_num == WITHDRAW_E) {
			servise_en_queue(&arrival, &withdraw);
			if (arrival.sim_count == 0) {
				break;
			}
		}
		else if (servise_num == TRANSFE_E) {
			servise_en_queue(&arrival, &transfe);
			if (arrival.sim_count == 0) {
				break;
			}
		}
		else if (servise_num == CONSULT_E) {
			servise_en_queue(&arrival, &consult);
			if (arrival.sim_count == 0) {
				break;
			}
		}
	}
print_lst(&deposit);
print_service(&deposit);

print_lst(&withdraw);
print_service(&withdraw);

print_lst(&transfe);
print_service(&transfe);

print_lst(&consult);
print_service(&consult);
	count.hour = 9;
	count.minute = 0;
	while (1) {
		i = 0;
		scanf("%d", &selec_next);
		system("clear");

		if (selec_next == 1) {
			action = 0;
			sum = 0;
			while (action < 30) {
				if (print_check(&count, &deposit) == TRUE) {
					print_temp[0] = deposit.head->order_count;
				}
				if (print_check(&count, &withdraw) == TRUE) {
					print_temp[1] = withdraw.head->order_count;
				}
				if (print_check(&count, &transfe) == TRUE) {
					print_temp[2] = transfe.head->order_count;
				}
				if (print_check(&count, &consult) == TRUE) {
					print_temp[3] = consult.head->order_count;
				}
				++count.minute;
				if (count.minute % 60 == 0) {
					count.minute = 0;
					++sum;
					count.hour += sum;
				}
				++action;
			}
			printf("                       %d : %d\n", count.hour, count.minute);
			printf("  -------------------------------------------------\n");
			printf("  |   입금   |   출금   |  계좌이체  |  금융상담  |\n");
			printf("  -------------------------------------------------\n");
			printf("      %d번        %d번           %d번        %d번\n", print_temp[0], print_temp[1], print_temp[2], print_temp[3]);
			printf("  -------------------------------------------------\n");
			printf("\n");
			if (count.hour == 16 && count.minute == 0) {
				break;
			}
		}

	}

}
