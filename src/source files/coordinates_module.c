#include "../header files/coordinates_module.h"
#include <stdlib.h>

point pointCreate(int x, int y)
{
    point p = {
        .x = x,
        .y = y,
    };
    return p;
}

point pointCreateRandom()
{
    point p = {
        .x = rand(),
        .y = rand(),
    };
    return p;
}

point pointCreateRandomWithinBounds(int limX, int limY)
{
    point p = {
        .x = rand() % limX,
        .y = rand() % limY,
    };
    return p;
}

void pointMoveX(point *p, int velocity)
{
    p->x += velocity;
}

void pointMoveY(point *p, int velocity)
{
    p->y += velocity;
}

bool pointCheckEquality(point p1, point p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}