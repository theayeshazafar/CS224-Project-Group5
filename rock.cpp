#include "rock.hpp"
#include "drawing.hpp"


//This function is used to move the Barrier on the screen and it is overriden from the Unit class
void rock::move()
{
    moverRect.y += (4*DifficultyLevel::getSpeed());
    if (moverRect.y > 650)
    {
        moverRect.y = -200;
    }
}

//This is the default constructor for the Barrier class
rock::rock()
{
    srcRect = {28,221,95,76};
    moverRect = {250, -15, 50, 50};
}

//This is the overloaded constructor for the Barrier class which takes in the x and y coordinates of the Barrier
rock::rock(int x, int y)
{       
    srcRect = {28,221,95,76};     
    moverRect = {x , y, 50, 50};       
}

//This is the destructor for the Barrier class
rock::~rock()
{}