#include <ncurses.h>
#include <stdbool.h>
#include "../../header files/game dependent/snake_module.h"
#include "../../header files/theme_module.h"

cBuffer cBufferCreate(unsigned int size)
{
    cBuffer cBuff = {
        .head = size,
        .tail = 0,
    };

    point offscreen = pointCreate(-1,-1);
    
    for (unsigned int i = 0; i < MAX_SCORE; i++)
    {
        cBuff.buff[i] = offscreen;
    }

    return cBuff;
}

void cBufferResize(cBuffer *cBuff, int size)
{

}
void cBufferInsert(cBuffer *cBuff, point p)
{
    if (!pointCheckEquality(cBuff->lastInsert, p))
    {
        mvaddch(cBuff->buff[cBuff->tail].y, cBuff->buff[cBuff->tail].x, ' ');
        cBuff->buff[cBuff->tail] = p;
        ENABLE_SNAKE_COLOR();
        mvaddch(cBuff->buff[cBuff->tail].y, cBuff->buff[cBuff->tail].x, CHAR_SNAKE_BODY);
        cBuff->tail++;
        cBuff->tail %= cBuff->head;
        cBuff->lastInsert = p;
    }
}

void cBufferExpend(cBuffer *cBuff)
{
    cBuff->head++;
}