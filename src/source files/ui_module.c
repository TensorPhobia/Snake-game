#include <ncurses.h>
#include "../header files/ui_module.h"
#include "../header files/settings_module.h"

void UICreate()
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, true);
    nodelay(stdscr, true);
    timeout(0);
    cbreak();
    refresh();
}

void UIHighlightBorder(){
    border(CHAR_UNIFORM_BORDER, CHAR_UNIFORM_BORDER, CHAR_UNIFORM_BORDER, CHAR_UNIFORM_BORDER, CHAR_UNIFORM_BORDER, CHAR_UNIFORM_BORDER, CHAR_UNIFORM_BORDER, CHAR_UNIFORM_BORDER);
}

void UIDestroy()
{
    endwin();
}

void UIClear()
{
    clear();
}

void UIPaint()
{
    refresh();
}