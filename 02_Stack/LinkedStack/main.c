#include "linkedstack.h"

int main(void)
{
	LinkedStack* stack = NULL;
	StackNode temp = {0, 0};
	StackNode* getNode;
	int input;
		
	while(1)
	{
		printf("\n1.create | 2.push | 3.pop | 4.peek | 5.delete | 6.display | 0.exit\n");
		printf("input num : ");
		scanf("%d", &input); fflush(stdin);
		switch(input)
		{
			case 1:
				if (stack != NULL)
				{
					printf("alredy create\n");
					break;
				}
				stack = createLinkedStack();
				if (!stack)
				{
					printf("fail\n");
					return (1);
				}
				break ;
			case 2:
				printf("input char > ");
				scanf("%c", &temp.data); fflush(stdin);
				pushLS(stack, temp);
				displayLinkedStack(stack);
				break ;
			case 3:
				getNode = popLS(stack);
				if (getNode != NULL)
				{
					printf("pop data: %c\n", getNode->data);
					free(getNode);
				}
				displayLinkedStack(stack);
				break ;
			case 4:
				getNode = peekLS(stack);
				if (getNode != NULL)
					printf("peek data: %c\n", getNode->data);
				displayLinkedStack(stack);
				break ;
			case 5:
				deleteLinkedStack(stack);
				stack = NULL;
				displayLinkedStack(stack);
				break ;
			case 6:
				displayLinkedStack(stack);
				break ;
			case 0: 
				deleteLinkedStack(stack);
				exit(0);
				break ;
		}
	}
	return (0);
}
