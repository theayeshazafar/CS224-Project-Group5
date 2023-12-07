#include "drawing.hpp"
#include "Unit.hpp"
#pragma once

//PoliceCar class inherting from Unit class and drawing the PoliceCar on the screen and moving it through its
//move function. The move function is overriden from the Unit class
class PoliceCar : public Unit
{
    public:
        void move();
        PoliceCar(); 
        PoliceCar(int x, int y); 
        ~PoliceCar();
};