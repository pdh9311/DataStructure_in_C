#include "linkedstack.h"

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

int sw = 0;

void dfs(int i, int j)
{
	if (maze[i][j] == 0)
	{
		if (i == 7 && j == 7)
			sw = 1;
		else if (maze[i][j] == 0)
		{
			maze[i][j] = 1;

			if (sw == 0) dfs(i, j + 1); // 우
			if (sw == 0) dfs(i + 1, j); // 하
			if (sw == 0) dfs(i, j - 1); // 좌
			if (sw == 0) dfs(i - 1, j); // 상

			maze[i][j] = 0;
		}
	}
	if (sw == 1)
		printf("(%d, %d)\n", i, j);

}

void print_maze(int map[8][8])
{
	int y;
	int x;

	for (y = 0; y < 8; y++)
	{
		for (x = 0; x < 8; x++)
			printf("%d ", map[y][x]);
		printf("\n");
	}
}

int main(void)
{
	dfs(0,0);
	if (sw == 0)
		printf("출구없음\n");

	print_maze(maze);
	return (0);
}
