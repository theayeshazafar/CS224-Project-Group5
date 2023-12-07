#include "RockObstacle.hpp"
#include "drawing.hpp"

//This function is used to move the rocks on the screen and it is overriden from the Unit class
void RockObstacle::move()
{
    moverRect.y += (4*DifficultyLevel::getSpeed());
    if (moverRect.y > 650)
    {
        moverRect.y = -200;
    }
}

//This is the default constructor for the RockObstacle class
RockObstacle::RockObstacle()
{
    srcRect = {28,221,95,76}; 
    moverRect = {405, -20, 120, 40};
}

//This is the overloaded constructor for the RockObstacle class which takes in the x and y coordinates of the rocks
RockObstacle::RockObstacle(int x, int y)
{      
    srcRect = {28,221,95,76};    
    moverRect = {x , y, 120, 40};      
}

//This is the destructor for the RockObstacle class
RockObstacle::~RockObstacle()
{}



