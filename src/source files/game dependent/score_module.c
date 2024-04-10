#include <ncurses.h>
#include "../../header files/game dependent/score_module.h"
#include "../../header files/theme_module.h"

int number_of_digits(int x){
    int accumulator = 0;
    do
    {
        x/=10;
        accumulator++;
    } while (x != 0);
    
    return accumulator;
}


void displayScore(unsigned int score){
    ENABLE_BOUNDARY_COLOR();
    mvaddch(0,4,'(');
    ENABLE_SCORE_COLOR();
    mvaddstr(0,5,"Score: ");
    ENABLE_FOOD_COLOR();
    mvprintw(0,12,"%d",score);
    ENABLE_BOUNDARY_COLOR();
    mvaddch(0,12 + number_of_digits(score),')');
    DISABLE_BOUNDARY_COLOR();
}