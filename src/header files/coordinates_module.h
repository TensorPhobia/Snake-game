#pragma once
#include <stdbool.h>

typedef struct
{
    int x, y;
} point;

point pointCreate(int x, int y);
point pointCreateRandom();
point pointCreateRandomWithinBounds(int limX, int limY);
void pointMoveX(point *p, int velocity);
void pointMoveY(point *p, int velocity);
bool pointCheckEquality(point p1, point p2);