#include "LogObstacle.hpp"
#include "drawing.hpp"

//This function is used to move the logs on the screen and it is overriden from the Unit class
void LogObstacle::move()
{
    moverRect.y += (4*DifficultyLevel::getSpeed());
    if (moverRect.y > 650)
    {
        moverRect.y = -200;
    }
}

//This is the default constructor for the LogObstacle class
LogObstacle::LogObstacle()
{
    srcRect = {139,345,119,78}; 
    moverRect = {405, -20, 120, 40};
}

//This is the overloaded constructor for the LogObstacle class which takes in the x and y coordinates of the logs
LogObstacle::LogObstacle(int x, int y)
{      
    srcRect = {139,345,119,78};    
    moverRect = {x , y, 120, 40};      
}

//This is the destructor for the LogObstacle class
LogObstacle::~LogObstacle()
{}
