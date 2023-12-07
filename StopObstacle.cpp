#include "StopObstacle.hpp"
#include "drawing.hpp"

//This function is used to move the stop sign on the screen and it is overriden from the Unit class
void StopObstacle::move()
{
    moverRect.y += (4*DifficultyLevel::getSpeed());
    if (moverRect.y > 650)
    {
        moverRect.y = -200;
    }
}

//This is the default constructor for the StopObstacle class
StopObstacle::StopObstacle()
{
    srcRect = {139,345,119,78}; 
    moverRect = {405, -20, 120, 40};
}

//This is the overloaded constructor for the StopObstacle class which takes in the x and y coordinates of the stop sign
StopObstacle::StopObstacle(int x, int y)
{      
    srcRect = {139,345,119,78};    
    moverRect = {x , y, 120, 40};      
}

//This is the destructor for the StopObstacle class
StopObstacle::~StopObstacle()
{}
