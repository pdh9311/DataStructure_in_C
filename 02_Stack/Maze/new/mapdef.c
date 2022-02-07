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

enum rdlu { RIGHT, DOWN, LEFT, UP};

int check(int mazeArray[HEIGHT][WIDTH], int x, int y, int dir)
{
    if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
        return (FALSE);
    if (dir == RIGHT && x + 1 < WIDTH && mazeArray[y][x + 1] == NOT_VISIT)
        return (TRUE);
    if (dir == DOWN && y + 1 < HEIGHT && mazeArray[y + 1][x] == NOT_VISIT)
        return (TRUE);
    if (dir == LEFT && x - 1 >= 0 && mazeArray[y][x - 1] == NOT_VISIT)
        return (TRUE);
    if (dir == UP && y - 1 >= 0 && mazeArray[y - 1][x] == NOT_VISIT)
        return (TRUE);
    return (FALSE);
}

void dfs(int mazeArray[HEIGHT][WIDTH], LinkedStack *pStack)
{
    MapPosition pos;
    pos.x = pStack->pTopElement->data.x;
    pos.y = pStack->pTopElement->data.y;

    
    if (pos.x == HEIGHT - 1 && pos.y == WIDTH - 1)
    {
        mazeArray[pos.y][pos.x] = 2;
        return ;
    }
    else if (pos.x < 0 || pos.y < 0 || pos.x >= WIDTH || pos.y >= HEIGHT)
    {
       return ;
    }
    else if(check(mazeArray, pos.x, pos.y, RIGHT)) //오른쪽
    {
        mazeArray[pos.y][pos.x] = 2;
        pos.x += 1;
        pushLSMapPosition(pStack, pos);
        dfs(mazeArray, pStack);
    }
    else if(check(mazeArray, pos.x, pos.y, DOWN)) //아래쪽
    {
        mazeArray[pos.y][pos.x] = 2;
        pos.y += 1;
        pushLSMapPosition(pStack, pos);
        dfs(mazeArray, pStack);
    }
    else if(check(mazeArray, pos.x, pos.y, LEFT)) //왼쪽
    {
        mazeArray[pos.y][pos.x] = 2;
        pos.x -= 1;
        pushLSMapPosition(pStack, pos);
        dfs(mazeArray, pStack);
    }
    else if(check(mazeArray, pos.x, pos.y, UP)) //위쪽
    {
        mazeArray[pos.y][pos.x] = 2;
        pos.y -= 1;
        pushLSMapPosition(pStack, pos);
        dfs(mazeArray, pStack);
    }
    else
    {
        StackNode* pop = popLS(pStack);
        if (pop->data.x == 0 && pop->data.y == 0)
        {
            printf("Can not Escape!!\n");
            free(pop);
            return ;
        }
        mazeArray[pos.y][pos.x] = 2;
        free(pop);
        dfs(mazeArray, pStack);
    }
}

void findPath(int mazeArray[HEIGHT][WIDTH],
		MapPosition startPos, MapPosition endPos, LinkedStack *pStack)
{
    pushLSMapPosition(pStack, startPos);
    dfs(mazeArray, pStack);
    foot_print(mazeArray, pStack);
}
