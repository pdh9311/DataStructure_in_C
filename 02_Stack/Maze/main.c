#include "linkedstack.h"

int main(void)
{
	int maze[HEIGHT][WIDTH] = {
		{0, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 0},
	};
	// LinkedStack *stack = createLinkedStack();

	MapPosition	pos = {0, 0, 1};
	int	tmp1, tmp2;

	while (pos.x != 7 && pos.y != 7)
	{
		printf("(%d, %d)\n", pos.x, pos.y);	// 현재 위치
		if (maze[pos.y][pos.x] )
		move(&pos, DIRECTION_OFFSETS[pos.direction]);
	}


	return (0);
}
