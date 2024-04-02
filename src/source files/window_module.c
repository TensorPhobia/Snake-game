#include <ncurses.h>
#include "../header files/window_module.h"

window windowCreate(char *title, char *copyRight, float version)
{
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);
    window win = {
        .title = title,
        .version = version,
        .screenSize.x = xMax,
        .screenSize.y = yMax,
        .copyRight = copyRight,
    };

    return win;
}