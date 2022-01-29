#include "arraystack.h"

void func()
{
	ArrayStack*		stack;
	ArrayStackNode	node;
	// ArrayStackNode*	result;

	stack = createArrayStack(10);
	node.data = 'a';
	pushAS(stack, node);
	node.data = 'b';
	pushAS(stack, node);
	node.data = 'c';
	pushAS(stack, node);
	displayArrayStack(stack);

	popAS(stack);
	displayArrayStack(stack);

	popAS(stack);
	displayArrayStack(stack);

	popAS(stack);
	displayArrayStack(stack);

	deleteArrayStack(stack);
}

int	main()
{
	func();
	// system("leaks a.out");
	return (0);
}