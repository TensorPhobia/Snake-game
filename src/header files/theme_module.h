#pragma once

/*---[FALL OUT THEME]---*/
#define COLOR_ABSOLUTE_BLACK 8
#define COLOR_PHOSPHOR_GREEN 9
/*---[FALL OUT THEME]---*/

/*---[OUT RUN THEME]---*/
#define COLOR_OUTRUN_BACKGROUND 10
#define COLOR_OUTRUN_RED 11
#define COLOR_OUTRUN_YELLOW 12
#define COLOR_OUTRUN_CYAN 13
#define COLOR_OUTRUN_PINKY 14
#define COLOR_OUTRUN_VIOLET 15
/*---[OUT RUN THEME]---*/

typedef enum{
    regular,
    fallout,
    outrun,
}themes;

/*Other themes goes here*/


/*this functions are not mandatory in order for the game to run thats
 *why they follow other naming convention PASCAL CASE
 */

void EXPEND_COLOR_DEFINITION(themes t);

void ENABLE_FOOD_COLOR();
void DISABLE_FOOD_COLOR();

void ENABLE_SNAKE_COLOR();
void DISABLE_SNAKE_COLOR();

void ENABLE_BOUNDARY_COLOR();
void DISABLE_BOUNDARY_COLOR();

void ENABLE_SCORE_COLOR();
void DISABLE_SCORE_COLOR();

void COLOR_BACKGROUND();/*no need to disable as it only impact the background*/