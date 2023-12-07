#include "PlayerCar.hpp"

//This function is responsible for drawing the PLayerCar on the screen
void PlayerCar::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

//This is the default constructor for the PlayerCar class
PlayerCar::PlayerCar()
{
    srcRect = {22,320,80,172};
    moverRect = {350, 350, 50, 92};  // The rendering information of PLayer Car on Window
}

//This is the overloaded ++ operator to move the PlayerCar to the right.
void PlayerCar :: operator++()
{
    moverRect.x += 65;
}

//This is the overloaded -- operator to move the PlayerCar to the left.
void PlayerCar :: operator--()
{
    moverRect.x -= 65;
}

//This is the overloaded + operator to move the PlayerCar up.
void PlayerCar :: operator+()
{
    moverRect.y += 40;
}

//This is the overloaded - operator to move the PlayerCar down.
void PlayerCar :: operator-()
{
    moverRect.y -= 40;
}

//This is the destructor for the PlayerCar class
PlayerCar::~PlayerCar()
{}
