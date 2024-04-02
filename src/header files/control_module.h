#pragma once
#include <ncurses.h>

typedef enum
{

    // Aliases for ArrowKeys
    UP = KEY_UP,
    DOWN = KEY_DOWN,
    LEFT = KEY_LEFT,
    RIGHT = KEY_RIGHT,
    // End Aliases for ArrowKeys
    
    // Special Implementation
    NO_INPUT = ERR,
    // End Special Implementation

    PAUSE = 'P',
    RESUME = 'R',
    EXIT = 'Q',
    DEBUG = 'D',

} controls;

controls handleKeyboard();
int getKey();