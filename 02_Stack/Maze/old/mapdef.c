#include "linkedstack.h"
#include "mapdef.h"

void printMaze(int map[HEIGHT][WIDTH])
{
    int y;
    int x;

    for (y = 0; y < HEIGHT; y++)
    {
            for (x = 0; x < WIDTH; x++)
                    printf("%d ", map[y][x]);
            printf("\n");
    }
}

static int moveable(int mazeArray[HEIGHT][WIDTH], int x, int y)
{
    if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT \
        && mazeArray[y][x] != WALL && mazeArray[y][x] != VISIT && mazeArray[y][x] == NOT_VISIT)
        return (TRUE);
    return (FALSE);
}

int pushLSMapPosition(LinkedStack* pStack, MapPosition data)
{
    StackNode element;

    element.data = data;
    return (pushLS(pStack, element));
}

static void foot_print(int mazeArray[HEIGHT][WIDTH], LinkedStack *pStack)
{
    printMaze(mazeArray);
    printf("\n");
    displayLinkedStack(pStack);
    printf("\n");
}

void findPath(int mazeArray[HEIGHT][WIDTH],
		MapPosition startPos, MapPosition endPos, LinkedStack *pStack)
{
    pushLSMapPosition(pStack, startPos);
    foot_print(mazeArray, pStack);

    while(1){
        StackNode* pop = popLS(pStack);
        
        
        mazeArray[pop->data.y][pop->data.x] = VISIT;
        if (pop->data.x == endPos.x && pop->data.y == endPos.y)
        {
            free(pop);
            foot_print(mazeArray, pStack);
            break;
        }
        MapPosition able;
        for (int i = 0; i < 4; i++) {
            // 스택에 있는 x,y값 가져와서 dir offset 한 후의 위치가 이동가능하면 stack에 추가
            able.x = pop->data.x + DIRECTION_OFFSETS[i][0];
            able.y = pop->data.y + DIRECTION_OFFSETS[i][1];
            if (moveable(mazeArray, able.x, able.y))
                pushLSMapPosition(pStack, able);
        }

        free(pop);
        foot_print(mazeArray, pStack);
    }
}
