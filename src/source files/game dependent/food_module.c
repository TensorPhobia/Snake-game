#include <ncurses.h>
#include "../../header files/game dependent/food_module.h"
#include "../../header files/settings_module.h"
#include "../../header files/collision_module.h"

point foodRandomizePosition(window *win)
{
    point food;
    do
    {
        food = pointCreateRandomWithinBounds(win->screenSize.x, win->screenSize.y);
        /*Keep second condition for fall back safety if border is not present*/
    } while (detectPointCharCollision(food, CHAR_SNAKE_BODY) || detectBoundaryCollision(win , food) || detectPointCharCollision(food , CHAR_UNIFORM_BORDER));
    return food;
}