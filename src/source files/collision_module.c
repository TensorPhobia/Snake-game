#include <ncurses.h>
#include "../header files/collision_module.h"
#include "../header files/settings_module.h"

bool detectBoundaryCollision(window *win, point p)
{
    return p.x < 0 + BOUNDARY_LEFT_MARGIN || p.x > win->screenSize.x - BOUNDARY_RIGHT_MARGIN || p.y < 0 + BOUNDARY_TOP_MARGIN || p.y > win->screenSize.y - BOUNDARY_BOTTOM_MARGIN;
}

bool detectPointCollision(point p1, point p2)
{
    return pointCheckEquality(p1, p2);
}

bool detectPointCharCollision(point p1, int ch)
{
    return (mvinch(p1.y, p1.x) & A_CHARTEXT) == ch;
}