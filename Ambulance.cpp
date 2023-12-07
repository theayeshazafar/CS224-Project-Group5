#include "Ambulance.hpp"
#include "drawing.hpp"
#include "DifficultyLevel.hpp"
//This function is used to move the YellowBus on the screen and it is overriden from the Unit class
//The move function is overriden from the Unit class
void Ambulance::move()
{
    moverRect.y += (10*DifficultyLevel::getSpeed());
    if (moverRect.y > 680)
    {
        moverRect.y = -50;
    }
}

//This is the default constructor for the Ambulance class
Ambulance::Ambulance()
{
    srcRect = {289,14,93,190}; 
    moverRect = {540, 0, 60, 140};
}

//This is the overloaded constructor for the Ambulance class which takes in the x and y coordinates of the Ambulance
//and dynamically creates the Ambulance on the screen at the specified co-ordinates from the factory class
Ambulance::Ambulance(int x, int y)
{       
    srcRect = {289,14,93,190};       
    moverRect = {x , y, 60, 140};      
}

//This is the destructor for the Ambulance class
Ambulance::~Ambulance()
{}