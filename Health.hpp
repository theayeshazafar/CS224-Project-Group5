#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
#pragma once;

//Health class inherting from Unit class and drawing the Health on the screen.
// The Health symbols will be an static picture on screen and does not move.
class Health : public Unit
{
    public:
        Health(); 
        Health(int x);
        ~Health();
};
