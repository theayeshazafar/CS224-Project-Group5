#include "Health.hpp"

//Constructor for the Health class
Health :: Health()
{
    srcRect = {400, 20, 70, 60};
    moverRect = {709,0, 30, 30};
}

//This is the overloaded constructor for the Health class which takes in the x and y coordinates of the Health
//and dynamically creates the Health on the screen at the specified co-ordinates from the factory class
Health :: Health(int x)
{
    srcRect = {400, 20, 70, 60};
    moverRect = {x, 0, 30, 30};
}

//This is the destructor for the Health class
Health :: ~Health()
{}