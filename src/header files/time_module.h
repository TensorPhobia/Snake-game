#pragma once
#include <stdbool.h>
#include <time.h>

typedef struct
{
    clock_t tick1, tick2;
    double deltaTime;
} gTime;

gTime gTimeCreate();
void gTimeCalcTick1(gTime *t);
void gTimeCalcTick2(gTime *t);
void gTimeCalcDeltaTime(gTime *t);
bool gTimeFrameUpdate(gTime *t);