#include "drawing.hpp"
#include "Unit.hpp"
#include "DifficultyLevel.hpp"
#pragma once

//Cat class inherting from Unit class and drawing the Cat on the screen and moving it through its move function 
//The move function is overriden from the Unit class
class Cat : public Unit
{

public:
    void move();
    Cat(); 
    Cat(int x, int y);
    ~Cat();
};