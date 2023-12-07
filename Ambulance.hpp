#include "drawing.hpp"
#include "Unit.hpp"
#pragma once

//Class Ambulance inherting from Unit class and drawing the Ambulance on the screen and moving it through its move function
//The move function is overriden from the Unit class
class Ambulance : public Unit
{
    public:
        void move();
        Ambulance(); 
        Ambulance(int x, int y);
        ~Ambulance();
};