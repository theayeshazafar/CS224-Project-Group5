#include "ManCrossingRoad.hpp"
#include "drawing.hpp"
#include "DifficultyLevel.hpp"

// This function is used to move the Man Crossing the Road on the screen and it is overriden from the Unit class
// additionally it inherits animation variable from the Unit class to animate the Man Crossing the Road based on the srcRect values.
void ManCrossingRoad::move()
{
    switch (animation)
    {
    case 0:
        srcRect = {296, 332, 52, 105};
        animation = 1;
        break;
    case 1:
        srcRect = {358, 330, 38, 107};
        animation = 2;
        break;
    case 2:
        srcRect = {407, 329, 33, 108};
        animation = 3;
    case 3:
        srcRect = {451, 332, 37, 105};
        animation = 4;
    case 4:
        srcRect = {296, 332, 52, 105};
        animation = 0;
    default:
        animation = 0;
        break;
    }
    moverRect.x += (7 * DifficultyLevel::getSpeed());
    if (moverRect.x > 850)
    {
        moverRect.x = -500;
    }
}

// This is the default constructor for the Man Crossing the Road class
ManCrossingRoad::ManCrossingRoad()
{

    srcRect = {296, 332, 52, 105};
    moverRect = {70, 115, 40, 80};
}

// This is the overloaded constructor for the Man Crossing the Road class which takes in the x and y coordinates of the Man Crossing the Road
// and dynamically creates the Man Crossing the Road on the screen at the specified co-ordinates from the factory class
ManCrossingRoad::ManCrossingRoad(int x, int y)
{
    srcRect = {296, 332, 52, 105};
    moverRect = {x, y, 40, 80};
}

// This is the destructor for the Man Crossing the Road class
ManCrossingRoad::~ManCrossingRoad()
{
}