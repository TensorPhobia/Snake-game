#include <ncurses.h>
#include "../header files/control_module.h"

int getKey()
{
    return getch();
}

controls handleKeyboard()
{
    int key = getKey();

    switch (key)
    {
    case UP:
    case DOWN:
    case LEFT:
    case RIGHT:
    case PAUSE:
    case RESUME:
    case EXIT:
    case DEBUG:
        return key;
        break;

    default:
        return NO_INPUT;
        break;
    }
}