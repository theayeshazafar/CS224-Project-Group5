#include "BlueCar.hpp"
#include "drawing.hpp"
#include "DifficultyLevel.hpp"

//The move function is overriden from the Unit class
void BlueCar::move()
{
    moverRect.y += (10*DifficultyLevel::getSpeed());
    if (moverRect.y > 680)
    {
        moverRect.y = -50;
    }
}

//This is the default constructor for the BlueCar class
BlueCar::BlueCar()
{
    srcRect = {8,7,74,179}; 
    moverRect = {540, 0, 60, 140};
}

//This is the overloaded constructor for the BlueCar class which takes in the x and y coordinates of the BlueCar
//and dynamically creates the BlueCar on the screen at the specified co-ordinates from the factory class
BlueCar::BlueCar(int x, int y)
{       
    srcRect = {8,7,74,179};       
    moverRect = {x , y, 60, 140};      
}

//This is the destructor for the BlueCar class
BlueCar::~BlueCar()
{}