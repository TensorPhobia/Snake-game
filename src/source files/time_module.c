#include <unistd.h>
#include "../header files/time_module.h"
#include "../header files/settings_module.h"

gTime gTimeCreate()
{
    gTime t = {
        .deltaTime = 0.0,
        .tick1 = 0,
        .tick2 = 0,
    };
    return t;
}

void gTimeCalcTick1(gTime *t)
{
    t->tick1 = clock();
}

void gTimeCalcTick2(gTime *t)
{
    t->tick2 = clock();
}

void gTimeCalcDeltaTime(gTime *t)
{
    t->deltaTime = (double)(t->tick2 - t->tick1) / CLOCKS_PER_SEC;
}

bool gTimeFrameUpdate(gTime *t)
{
    gTimeCalcDeltaTime(t);
    usleep(((1 - t->deltaTime) * 1000000) / FRAME_RATE);
    return true;
};
