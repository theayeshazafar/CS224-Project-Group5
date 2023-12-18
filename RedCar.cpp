#include "RedCar.hpp"
#include "drawing.hpp"

// This is the default constructor for the RedCar class
RedCar::RedCar()
{
    srcRect = {105, 14, 67, 188};
    moverRect = {360, -10, 40, 90};
}

// Overloaded constructor for the RedCar class which takes in the x and y coordinates 
// and dynamically creates the RedCar on the screen at the specified co-ordinates on the screen.
RedCar::RedCar(int x, int y)
{
    srcRect = {105, 14, 67, 188};
    moverRect = {x, y, 40, 90};
}

// This function is used to move the RedCar on the screen and it is overriden from the Unit class
void RedCar::move()
{
    moverRect.y += (11 * DifficultyLevel::getSpeed());
    if (moverRect.y > 650)
    {
        moverRect.y = -50;
    }
}

//Destructor for RedCar Class
RedCar::~RedCar()
{}