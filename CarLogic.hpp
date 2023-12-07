#include "PlayerCar.hpp"
#include <vector>
#include <list>
#include <SDL_mixer.h>
#include <SDL.h>
using namespace std;

// The Car_logic class is the main class that contains the logic for PlayerCar, that will be driven by player
// This class is responsible for the collision detection, score calculation, drawing of assets on screen.
// It creates the required objects like PlayerCar and the Obstacles that moves on the screen .
class Car_Logic
{
    // This is the score for our Game.
    //int scores = 0;
    PlayerCar playercar;
    Mix_Music *music = NULL;
    // Screen dimension constants
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

public:
    //int  getscore();
    bool passed_obstacle = false;
    bool checkup = false;
    bool checkdown = false;
    bool checkright = false;
    bool checkleft = false;
    bool objectcheck = false;
    void drawObjects();
    void createObject();
    void CheckCollision();
    /*Game class has been made the friend class of car_Logic class so that it can access the members of 
    CarLogic class.*/
    friend class Game;
    ~Car_Logic();
};
