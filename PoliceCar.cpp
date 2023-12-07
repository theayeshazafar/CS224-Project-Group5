#include "PoliceCar.hpp"
#include "drawing.hpp"
#include "DifficultyLevel.hpp"
//This function is used to move the PoliceCar on the screen and it is overriden from the Unit class
//additionally it inherits animation variable from the Unit class to animate the PoliceCar based on the srcRect values.
void PoliceCar::move()
{
    moverRect.y += (10 * DifficultyLevel::getSpeed());
    if (moverRect.y > 650)
    {
        moverRect.y = -50;
    }
}
//This is the default constructor for the PoliceCar class
PoliceCar::PoliceCar()
{
    srcRect = {390,125,93,184};
    moverRect = {298, -390, 40, 90};
}
//This is the overloaded constructor for the PoliceCar class which takes in the x and y coordinates of the PoliceCar
//and dynamically creates the PoliceCar on the screen at the specified co-ordinates from the factory class
PoliceCar::PoliceCar(int x, int y)
{      
    srcRect = {390,125,93,184};          
    moverRect = {x , y, 40, 90};
}
//This is the destructor for the PoliceCar class
PoliceCar::~PoliceCar()
{
}

