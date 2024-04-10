#include <ncurses.h>
#include "../header files/theme_module.h"


typedef enum{
    BACKGROUND_CLR = 1,
    BOUNDARY_CLR = 2,
    SCORE_CLR = 3,
    FOOD_CLR = 4,
    SNAKE_CLR = 5,
}theme_components;

void EXPEND_COLOR_DEFINITION(themes t){
    /*--BEGIN FALL OUT THEME--*/
    init_color(COLOR_PHOSPHOR_GREEN,105,996,5);
    init_color(COLOR_ABSOLUTE_BLACK,0,0,0);
    /*--END FALL OUT THEME--*/

    /*--BEGIN OUT RUN THEME--*/
    init_color(COLOR_OUTRUN_BACKGROUND,46,39,125);
    init_color(COLOR_OUTRUN_YELLOW,996,828,0);
    init_color(COLOR_OUTRUN_RED,996,179,589);
    init_color(COLOR_OUTRUN_CYAN,0,996,941);
    init_color(COLOR_OUTRUN_VIOLET,670,0,996);
    init_color(COLOR_OUTRUN_PINKY,996,164,984);
    /*--END OUT RUN THEME--*/
    switch (t)
    {
    case fallout:
        for (int i = BACKGROUND_CLR; i <= SNAKE_CLR; i++)
        {
            init_pair(i,COLOR_PHOSPHOR_GREEN,COLOR_ABSOLUTE_BLACK);
        }    
        break;
    case outrun:
        init_pair(BACKGROUND_CLR,COLOR_OUTRUN_BACKGROUND,COLOR_OUTRUN_BACKGROUND);
        init_pair(BOUNDARY_CLR,COLOR_OUTRUN_RED,COLOR_OUTRUN_BACKGROUND);
        init_pair(SCORE_CLR,COLOR_OUTRUN_CYAN,COLOR_OUTRUN_BACKGROUND);
        init_pair(FOOD_CLR,COLOR_OUTRUN_YELLOW,COLOR_OUTRUN_BACKGROUND);
        init_pair(SNAKE_CLR,COLOR_OUTRUN_PINKY,COLOR_OUTRUN_BACKGROUND); 
        break;
    case regular:
    default:
        init_pair(BACKGROUND_CLR,COLOR_YELLOW,-1);
        init_pair(BOUNDARY_CLR,COLOR_RED,-1);
        init_pair(SCORE_CLR,COLOR_CYAN,-1);
        init_pair(FOOD_CLR,COLOR_YELLOW,-1);
        init_pair(SNAKE_CLR,COLOR_MAGENTA,-1);
        break;
    }
}


void ENABLE_FOOD_COLOR(){
    attron(COLOR_PAIR(FOOD_CLR));
}

void DISABLE_FOOD_COLOR(){
    attroff(COLOR_PAIR(FOOD_CLR));
}

void ENABLE_SNAKE_COLOR(){
    attron(COLOR_PAIR(SNAKE_CLR));
}
void DISABLE_SNAKE_COLOR(){
    attroff(COLOR_PAIR(SNAKE_CLR));
}

void ENABLE_BOUNDARY_COLOR(){
    attron(COLOR_PAIR(BOUNDARY_CLR));
}

void DISABLE_BOUNDARY_COLOR(){
    attroff(COLOR_PAIR(BOUNDARY_CLR));
}

void ENABLE_SCORE_COLOR(){
    attron(COLOR_PAIR(SCORE_CLR));
}

void DISABLE_SCORE_COLOR(){
    attron(COLOR_PAIR(SCORE_CLR));
}

void COLOR_BACKGROUND(){
    bkgd(COLOR_PAIR(BACKGROUND_CLR));
}