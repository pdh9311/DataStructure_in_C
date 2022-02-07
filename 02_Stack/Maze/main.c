#include "linkedstack.h"
#include "mapdef.h"

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

int moveable(MapPosition pos)
{

}


int main(void)
{
	LinkedStack *stack = createLinkedStack();
	MapPosition pos;
	pos.x = 0;
	pos.y = 0;
	pos.direction = 0;

	while (1) {
		maze[pos.y][pos.x] = VISIT;
		if (pos.y == HEIGHT - 1 && pos.x == WIDTH - 1) {
			printf("Escaped from the maze!!!!\n");
			break ;
		}
		int forwarded = FALSE;
		for (int i = 0; i < 4; i++) {
			if (moveable(pos))
		}



	}
	return (0);
}

