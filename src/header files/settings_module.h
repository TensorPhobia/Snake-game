#pragma once

#define FRAME_RATE 15.0
#define MAX_SCORE 9999 /*will set also the size of the circular buffer*/
#define CHAR_SNAKE_BODY '#'
#define CHAR_FOOD '*'
#define CHAR_UNIFORM_BORDER '+'
#define SNAKE_DEFAULT_SIZE 8
#define SNAKE_DEFAULT_VELOCITY 1

/* Boundaries section*/

typedef enum{
    BOUNDARY_TOP_MARGIN = 1,/*Might be terminal specific*/
    BOUNDARY_BOTTOM_MARGIN = 0,
    BOUNDARY_LEFT_MARGIN = 0,
    BOUNDARY_RIGHT_MARGIN = 0,
    BOUNDARY_SPAWN_MARGIN =4,
}boundaries_margin;