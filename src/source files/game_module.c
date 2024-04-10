#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#include "../header files/game_module.h"
#include "../header files/time_module.h"
#include "../header files/ui_module.h"
#include "../header files/control_module.h"
#include "../header files/settings_module.h"
#include "../header files/coordinates_module.h"
#include "../header files/collision_module.h"
#include "../header files/game dependent/food_module.h"
#include "../header files/game dependent/snake_module.h"
#include "../header files/window_module.h"
#include "../header files/theme_module.h"
#include "../header files/game dependent/score_module.h"

void Init()
{
    srand(time(NULL));
    UICreate();
    UIEnableColor();
    EXPEND_COLOR_DEFINITION(regular);
    ENABLE_BOUNDARY_COLOR();
    UIHighlightBorder();
    DISABLE_BOUNDARY_COLOR();

    COLOR_BACKGROUND();
}

void GameLoop()
{
    window w = windowCreate("Snakes", "TensorPhobia", 0.5);
    controls user_input,illegal_move,old_user_input = NO_INPUT;
    unsigned int score = 0;
    displayScore(score);
    gTime t = gTimeCreate();
    point p = pointCreate(5, 5);
    point food = foodRandomizePosition(&w);

    ENABLE_FOOD_COLOR();
    mvaddch(food.y, food.x, CHAR_FOOD);

    cBuffer snake = cBufferCreate(SNAKE_DEFAULT_SIZE);

    ENABLE_SNAKE_COLOR();
    for (int i = 0; i < SNAKE_DEFAULT_SIZE; i++)
    {
        p.x = i + BOUNDARY_SPAWN_MARGIN;
        cBufferInsert(&snake, p);
        mvaddch(p.y, p.x, CHAR_SNAKE_BODY);
    }
    
    /*---[Begin Special Implementation]---
    since snake position is scripted and depend on level design 
    if added the feature added, the programmer needs to set manually
    illegal key press to prevent collision issues.
    ---[End Special Implementation]--- */

    illegal_move = LEFT;

    while (true)
    {
        gTimeCalcTick1(&t);
        user_input = handleKeyboard();
        
        if (gTimeFrameUpdate(&t))
        {

            if (user_input == NO_INPUT)
            {
                user_input = old_user_input;
            }

            if(user_input == illegal_move){
                continue;
            }else if (user_input == UP && old_user_input != DOWN)
            {
                old_user_input = UP;
                illegal_move = NO_INPUT;
            }
            else if (user_input == DOWN && old_user_input != UP)
            {
                old_user_input = DOWN;
                illegal_move = NO_INPUT;
            }
            else if (user_input == LEFT && old_user_input != RIGHT)
            {
                old_user_input = LEFT;
                illegal_move = NO_INPUT;
            }
            else if (user_input == RIGHT && old_user_input != LEFT)
            {
                old_user_input = RIGHT;
                illegal_move = NO_INPUT;
            }


            if (old_user_input == UP)
            {
                pointMoveY(&p, -SNAKE_DEFAULT_VELOCITY);
            }
            else if (old_user_input == DOWN)
            {
                pointMoveY(&p, SNAKE_DEFAULT_VELOCITY);
            }
            else if (old_user_input == LEFT)
            {
                pointMoveX(&p, -SNAKE_DEFAULT_VELOCITY);
            }
            else if (old_user_input == RIGHT)
            {
                pointMoveX(&p, SNAKE_DEFAULT_VELOCITY);
            }


            if (detectBoundaryCollision(&w, p) || (detectPointCharCollision(p, CHAR_SNAKE_BODY) && user_input != NO_INPUT) || detectPointCharCollision(p, CHAR_UNIFORM_BORDER))
            {
                sleep(1);
                break;
            }
            else if (detectPointCollision(p, food))
            {
                score++;
                cBufferExpend(&snake);
                mvaddch(food.y, food.x, ' ');
                food = foodRandomizePosition(&w);
                displayScore(score);
                ENABLE_FOOD_COLOR();
                mvaddch(food.y, food.x, CHAR_FOOD);
            }

            cBufferInsert(&snake, p);

            UIPaint();
        }
        gTimeCalcTick2(&t);
    }
}

void Exit()
{
    UIDisableColor();
    UIDestroy();
}
