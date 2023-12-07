#include "drawing.hpp"
#include "Unit.hpp"
#pragma once

//Class RedCar inherting from Unit class and drawing the RedCar on the screen and moving it through its move function
//The move function is overriden from the Unit class
class RedCar : public Unit
{
    public:
        void move();
        RedCar(); 
        RedCar(int x, int y);
        ~RedCar();
};

