#include "RedCar.hpp"
#include "drawing.hpp"
#include "DifficultyLevel.hpp"

//The move function is overriden from the Unit class
void RedCar::move()
{
    moverRect.y += (10*DifficultyLevel::getSpeed());
    if (moverRect.y > 680)
    {
        moverRect.y = -50;
    }
}

//This is the default constructor for the RedCar class
RedCar::RedCar()
{
    srcRect = {105,14,67,188}; 
    moverRect = {540, 0, 60, 140};
}

//This is the overloaded constructor for the RedCar class which takes in the x and y coordinates of the RedCar
//and dynamically creates the RedCar on the screen at the specified co-ordinates from the factory class
RedCar::RedCar(int x, int y)
{       
    srcRect = {105,14,67,188};       
    moverRect = {x , y, 60, 140};      
}

//This is the destructor for the RedCar class
RedCar::~RedCar()
{}