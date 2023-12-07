#include "drawing.hpp"
#include "Unit.hpp"
#pragma once

//Class BlueCar inherting from Unit class and drawing the BlueCar on the screen and moving it through its move function
//The move function is overriden from the Unit class
class BlueCar : public Unit
{
    public:
        void move();
        BlueCar(); 
        BlueCar(int x, int y);
        ~BlueCar();
};