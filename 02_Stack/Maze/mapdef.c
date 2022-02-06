#include "mapdef.h"

void move(MapPosition *pos, int **maze)
{
	int tmp_x;
	int tmp_y;
	int *dir;

	dir = DIRECTION_OFFSETS[pos->direction];	// 다음 이동할 위치

	// 다음 위치로 이동될 값만큼 계산해준다.
	tmp_x = pos->x + dir[0];
	tmp_y = pos->y + dir[1];


	if (maze[tmp_y][tmp_x] == NOT_VISIT)	// 다음 위치에서 방문이 가능하면 pos값을 수정한다.
	{
		pos->x = tmp_x;
		pos->y = tmp_y;
	}
	else if (maze[tmp_y][tmp_x] == WALL)	// 다음 위치가 벽이면 다른 방향을 확인할 수 있도록 바꿔준다.
	{
		if (pos->direction == 1)
			pos->direction = 2;
		else if (pos->direction == 2)
			pos->direction = 3;
		else if (pos->direction = 3)
			pos->direction = 0;
		else if (pos->direction = 0)
			pos->direction = 1;
	}

}
