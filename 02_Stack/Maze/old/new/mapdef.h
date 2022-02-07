#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 4

#include "linkedstack.h"

// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1},		// 위쪽으로 이동	0	
	{-1, 0},			// 왼쪽으로 이동	3
	{0, 1},			// 아래쪽으로 이동	2
	{1, 0}			// 오른쪽으로 이동	1
};

enum PosStatus { NOT_VISIT = 0, WALL = 1 , VISIT = 2  };

void findPath(int mazeArray[HEIGHT][WIDTH],
		MapPosition startPos, MapPosition endPos, LinkedStack *pStack);
int pushLSMapPosition(LinkedStack* pStack, MapPosition data);
void printMaze(int mazeArray[HEIGHT][WIDTH]);

// void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]);

#endif