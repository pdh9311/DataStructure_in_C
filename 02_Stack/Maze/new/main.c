#include "mapdef.h"

int mazeArray[HEIGHT][WIDTH] = {
	{0, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 1, 1, 1, 0},
	{1, 1, 1, 0, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 0},
};

int main()
{
	MapPosition startPos = {0, 0};
	MapPosition endPos = {7, 7};
	LinkedStack *pStack = createLinkedStack();

	findPath(mazeArray, startPos, endPos, pStack);
	showPath(pStack, mazeArray);
	deleteLinkedStack(pStack);
	// system("leaks a.out");
}