#ifndef LINKEDQUEUE_H
# define LINKEDQUEUE_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define TRUE 1
# define FALSE 0

typedef enum service_Type { DEPOSIT, WITHDRAW, TRANSFE, CONSULT } service_e;
typedef enum status_Type { ARRIVAL, WAIT, START, END } status_e;

typedef struct hour_minute_Type
{
	int hour;
	int minute;
} HourMinute_t;

typedef struct customer_Type
{
	int id;
	HourMinute_t arrival_time;
	HourMinute_t service_time;
	HourMinute_t start_time;
	HourMinute_t end_time;
	struct customer_Type *prev;
	struct customer_Type *next;
} Customer_t;

typedef struct queue_node_Type
{
	int node_count;
	SimCustomer *head;
	SimCustomer *tail;
} LinkedQueue_t;

LinkedQueue_t *createLinkedQueue(void);

#endif