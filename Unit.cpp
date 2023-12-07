#include<SDL.h>
#include "Unit.hpp"

//This function draws and renders all the objects present in the Unit type list.
void Unit::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

//A virtual move that moves all the objects present in the Unit type list.
void Unit::move()
{}

//This is the destructor for the Unit class.
Unit::~Unit()
{}

