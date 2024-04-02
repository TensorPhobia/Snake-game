#pragma once
#include <stdbool.h>
#include "./coordinates_module.h"
#include "./window_module.h"

typedef enum
{
    BOUNDARY_COLLISION,
    SNAKE_COLLISION,
    FOOD_COLLISION,
    NO_COLLISION,
} collision;

bool detectBoundaryCollision(window *win, point p);
bool detectPointCollision(point p1, point p2);
bool detectPointCharCollision(point p1, int ch);