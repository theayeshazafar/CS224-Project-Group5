#include "Barrier.hpp"
#include "drawing.hpp"


//This function is used to move the Barrier on the screen and it is overriden from the Unit class
void Barrier::move()
{
    moverRect.y += (4*DifficultyLevel::getSpeed());
    if (moverRect.y > 650)
    {
        moverRect.y = -200;
    }
}

//This is the default constructor for the Barrier class
Barrier::Barrier()
{
    srcRect = {139,345,119,78};
    moverRect = {405, -20, 120, 40};
}

//This is the overloaded constructor for the Barrier class which takes in the x and y coordinates of the Barrier
Barrier::Barrier(int x, int y)
{       
    srcRect = {139,345,119,78};     
    moverRect = {x , y, 120, 40};       
}

//This is the destructor for the Barrier class
Barrier::~Barrier()
{}