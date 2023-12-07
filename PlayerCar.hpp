#include<SDL.h>
#include "Drawing.hpp"
//This class is responsible for drawing the Player Car on the screen..
//Car_Logic has been made a friend class of this class 

class PlayerCar
{

    SDL_Rect srcRect, moverRect;

public:
    void draw();
    PlayerCar(); 
    friend class Car_Logic;
    ~PlayerCar();
    void operator++(); //This is the overloaded ++ operator to move the PlayerCar to the right.
    void operator--(); //This is the overloaded -- operator to move the PlayerCar to the left.
    void operator+(); //This is the overloaded + operator to move the PlayerCar to the up.
    void operator-(); //This is the overloaded - operator to move the PlayerCar to the down.
};
