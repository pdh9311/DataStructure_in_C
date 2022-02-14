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
} service_e;

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
	hour_minute_t service_start_time;
	hour_minute_t service_end_time; // 서비스 시간
	hour_minute_t wait_time; // 대기시간 service_start_time - arrival_time
	int order_count; // 들어온 순서
	int service;
} SimCustomer_t;

typedef struct queue_node_Type
{
	int sim_count;			// node 개수
	int sim_total_wait;
	SimCustomer_t* head;
	SimCustomer_t* tail;
} queue_node_t;

queue_node_t* creat_simqueue();
SimCustomer_t* creat_sim(hour_minute_t time, int order, int service);
void account_wait(queue_node_t* transfe, queue_node_t* arrival, int service_time);

int en_queue(queue_node_t* node, SimCustomer_t* sim);
SimCustomer_t* de_queue(queue_node_t* node);
#endif
