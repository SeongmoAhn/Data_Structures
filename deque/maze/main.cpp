#include <cstdio>
#include "Location2D.h"
#include <queue>
using namespace std;
const int MAZE_SIZE = 6;
char map[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '1'}, 
    {'1', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '0', '0', 'x'},
    {'1', '1', '1', '1', '1', '1'}};

// (r, c)가 갈 수 있는 위치인지 검사하는 함수
// (r, c)가 배열 안에 있고, 값이 갈 수 있는 위치 '0'이거나 출구 'x'여야 함
bool isValidLoc(int r, int c)
{
    if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE)
        return false;
    else
        return map[r][c] == '0' || map[r][c] == 'x';
}

int main(void)
{
    queue<Location2D> locQueue;
    Location2D entry(1, 0);
    locQueue.push(entry);

    while (!locQueue.empty())
    {
        Location2D here = locQueue.front();
        locQueue.pop();
        int r = here.row;
        int c = here.col;
        printf("(%d, %d) ", r, c);
        if (map[r][c] == 'x')
        {
            printf("\nMaze Clear!\n");
            return 0;
        }

        else
        {
            map[r][c] = '.';
            if (isValidLoc(r - 1, c)) locQueue.push(Location2D(r - 1, c));
            if (isValidLoc(r + 1, c)) locQueue.push(Location2D(r + 1, c));
            if (isValidLoc(r, c - 1)) locQueue.push(Location2D(r, c - 1));
            if (isValidLoc(r, c + 1)) locQueue.push(Location2D(r, c + 1));
        }
    }
    printf("\nMaze Fail...\n");
}