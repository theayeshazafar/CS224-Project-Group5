#include "drawing.hpp"
#include "Unit.hpp"
#include<iostream>
using namespace std;
#pragma once

//WhiteCar class inherting from Unit class and drawing the WhiteCar on the screen and moving it through its move function
//The move function is overriden from the Unit class
class BlueCar : public Unit
{
    public:
    void move();
    BlueCar(); 
    BlueCar(int x, int y);
    ~BlueCar();
};