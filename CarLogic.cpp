#include <iostream>
#include "CarLogic.hpp"
#include <SDL.h>
using namespace std;

// This function loops through the type Unit list and call the draw function from Unit class and virtual move function of each class of the asset.
// This function will also draws the PlayerCar on screen.It is also responsible for the movement of the PlayerCar based on the key pressed by the user.
// This function also contains the condtions necessary to make sure that the playercar does not cross the boundary of the road
// Operator overloading have been done(in PlayerCar Class) for the movement of the Car. The overloaded operators are in the PlayerCar class.

void Car_Logic::drawObjects()
{
    /*Iterating over the whole vector containing the obstacles to draw and move them. With the help of this vector
    we will also be checking collision of these obstacles with our Player Car.*/
    for (Unit *x : objects)
    {
        x->draw(); // Drawing the obstacles.
        x->move(); // Moving the obstacles.
    }
    playercar.draw(); // Drawing the PlayerCar.

    // Following condition is for Player Car to move forward only if it is in following range on screen.
    if (checkup == true)
    {
        playercar.srcRect = {22, 320, 80, 172};
        if (((playercar.moverRect.y) > 30 && playercar.moverRect.y <= SCREEN_HEIGHT))
        {
            -playercar;
        }
        checkup = false;
    }
    // Following condition is for Player Car to move backward only if it is in following range on screen.
    if (checkdown == true)
    {
        if ((playercar.moverRect.y >= 0) && (playercar.moverRect.y <= (SCREEN_HEIGHT - playercar.moverRect.h))) //&&(playercar.moverRect.x >= 105  && playercar.moverRect.x <= 420))
        {
            +playercar;
        }
        checkdown = false;
    }
    // Following condition is for Player Car to move left only if it is in following range on screen.
    if (checkleft == true)
    {
        if (playercar.moverRect.x > (140 + playercar.moverRect.w) && playercar.moverRect.x < SCREEN_WIDTH)
        {
            --playercar;
        }
        checkleft = false;
    }
    // Following condition is for Player Car to move right only if it is in following range on screen.
    if (checkright == true)
    {
        if (playercar.moverRect.x > 0 && playercar.moverRect.x < (550))
        {
            ++playercar;
        }
        checkright = false;
    }
}
// This function loops through the Unit type list and compares the x and y coordinates of the playercar with the x and y coordinates of each obstacle to check collision.
// Upon collision the playercar moves back to it's original position and the health is reduced by 1 by popping the last element of the Unit type list
// The last three index of the Unit type list contains the health objects, and which are plus symbols.
void Car_Logic::CheckCollision()
{
    bool passed_obstacle = false;
    for (Unit *x : objects)
    {
        // Following are the conditions for Collision.
        if ((playercar.moverRect.x + playercar.moverRect.w >= x->moverRect.x) &&
            (playercar.moverRect.x <= x->moverRect.x + x->moverRect.w)        && 
            (playercar.moverRect.y + playercar.moverRect.h >= x->moverRect.y) &&
            (playercar.moverRect.y <= x->moverRect.y + x->moverRect.h))
        {
            music = Mix_LoadMUS("Collide.wav");
            Mix_PlayMusic(music, 1);
            SDL_Delay(500);
            music = Mix_LoadMUS("GameplayMusic.mp3");
            Mix_PlayMusic(music, 1);
            playercar.moverRect = {(170 + rand() % (540 - 170)), 250, 50, 92};
            factory.number_of_collisions += 1;
            objects.pop_back();
        }
        else if (((playercar.moverRect.y - x->moverRect.y) < 20) && ((playercar.moverRect.y - x->moverRect.y) > 0))
        {
            passed_obstacle = true;
            break;
        }
    }
    // if (passed_obstacle)
    // {
    //     scores += 1;
    //     // cout<<"The score for the Game is: "<<scores<<endl;
    //     passed_obstacle = false;
    // }
}
// int Car_Logic::getscore()
// {
//     return scores;
// }
// // This function calls the factory function to return a Unit type list to create the assets dynamically and push them to the Unit type list.
// A check is also made to make sure that the objects are created only once or else the factory class will continue
// to return a Unit type list with the same assets as the game is being played.

void Car_Logic::createObject()
{
    if (objectcheck == false)
    {
        objects = factory.CreateObjects();
        objectcheck = true;
    }
}
// Deconcstructor to free the memory allocated to the Unit type list and the pointer vector scores.
Car_Logic ::~Car_Logic()
{
    for (auto &&i : objects) // auto keyword automatically detects the data type of pass element
    {
        delete i;
    }
    objects.clear();
}