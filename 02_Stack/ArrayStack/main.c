#include "arraystack.h"

int main(void)
{
	ArrayStack*		stack = NULL;
	ArrayStackNode	node_add;
	int				input;

	while (1)
	{
		printf("\n1. create | 2. push | 3. pop | 4. display | 5. delete | 0. exit\n");
		printf("command : ");
		scanf("%d", &input);	fflush(stdin);
		if (input == 1)
		{
			if (stack != NULL)
			{
				printf("already stack\n");
			}
			else
			{
				int input_size;	
				printf("input_stack size ! : ");
				scanf("%d", &input_size);	fflush(stdin);
				stack = createArrayStack(input_size);
				if (!stack)
				{
					printf("stack is empty!\n");
					return 0;
				}
			}
		}
		else if (input == 2)
		{
			printf("input_node (char): ");
			node_add.data = getchar();
			pushAS(stack, node_add);
			displayArrayStack(stack);
		}
		else if (input == 3)
		{
			printf("pop_node (char): \n");
			popAS(stack);
			displayArrayStack(stack);
		}
		else if (input == 4)
		{
			displayArrayStack(stack);
		}
		else if (input == 5)
		{
			printf("delete\n");
			deleteArrayStack(stack);
		}
		else if (input == 0)
		{
			deleteArrayStack(stack);
			exit(0);
		}
	}
	return (0);
}