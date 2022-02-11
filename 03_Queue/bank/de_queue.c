/* 큐를 삭제하는 함수 (심이 업무 다보고 출발하는 경우) */
#include "bank_test.h"

void de_queue(queue_node_t* node)
{
print_lst(node);
	SimCustomer_t* temp;
	SimCustomer_t* remove_node;

	if (node->sim_count == 0) {
		printf("삭제할 데이터가 없습니다.\n");
		return ;
	}
	printf("%d번째 손님의 종료 시간은: %d : %d 입니다.\n",
	node->head->order_count, node->head->servise_time.hour, node->head->servise_time.minute);

	if (node->sim_count == 1) {
		free(node->head);
		node->head = NULL;
		node->tail = NULL;
		node->sim_count = 0;

		return ;
	}
	else {
		remove_node = node->head;
		temp = node->head->next;
		temp->prev = remove_node->prev;
		node->head = temp;
		if (remove_node != NULL) {
			free(remove_node);
			remove_node = NULL;
		}
		node->sim_count -= 1;
	}
}
