#ifndef BANK_TEST_H
# define BANK_TEST_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define TRUE (1)
# define FALSE (0)

typedef enum{
	DEPOSIT_E,
	WITHDRAW_E,
	TRANSFE_E,
	CONSULT_E
} servise_e;

typedef struct hour_minute_Type
{
	int hour;
	int minute;
} hour_minute_t;

typedef struct SimCustomerType
{
	struct SimCustomerType* next;
	struct SimCustomerType* prev;
	hour_minute_t arrival_time; // 도착 시간
	hour_minute_t servise_time; // 서비스 시간
	int order_count; // 들어온 순서
} SimCustomer_t;

typedef struct queue_node_Type
{
	int sim_count;			// node 개수
	SimCustomer_t* head;
	SimCustomer_t* tail;
} queue_node_t;

SimCustomer_t* creat_sim(queue_node_t* node);
int creat_time(queue_node_t* node, SimCustomer_t* new_sim);

int arrival_en_queue(queue_node_t* node, SimCustomer_t* sim);
void servise_en_queue(queue_node_t* arrival, queue_node_t* servise);

void de_queue(queue_node_t* node);

int time_check(SimCustomer_t* node, SimCustomer_t* servise);
int print_check(hour_minute_t* count, queue_node_t* servise);


void print_lst(queue_node_t *node);
#endif
