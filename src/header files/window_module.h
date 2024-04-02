#pragma once
#include "./coordinates_module.h"

typedef struct
{
    char *title;
    float version;
    char *copyRight;
    point screenSize;
} window;

window windowCreate(char *title, char *copyRight, float version);