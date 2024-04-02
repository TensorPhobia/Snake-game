#pragma once
#include "../coordinates_module.h"
#include "../settings_module.h"

typedef struct
{
    unsigned int head;
    unsigned int tail;

    point lastInsert;
    point buff[MAX_SCORE];
} cBuffer;

cBuffer cBufferCreate(unsigned int size);
void cBufferExpend(cBuffer *cBuff);
void cBufferInsert(cBuffer *cBuff, point p);
void cBufferResize(cBuffer *cBuff, int size);/*For future big targets that add 100 to score*/