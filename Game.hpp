#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <SDL_mixer.h>
#include "Car_Logic.hpp"
#include "drawing.hpp"
#include "DifficultyLevel.hpp"
//This is the main class of the game responsible for the game loop.
//It loads the main game screen, Game Over screen, the instructions screen, etc.
class Game
{
    //Screen dimension constants
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;
    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    //Pointer to Background Music
    Mix_Music* music = NULL;
    /* State variable will hold the information in the form of integers for each corresponding screen, 
    such as Start Game Screen, */ 
    int state = 0;
public:
    //This function will initialize the SDL videosystem, texture, audio, creates window and finally return flag of success of initilazing
    bool init();  
    bool loadMedia();
    bool loadGame();
    bool loadInstructions();
    bool loadLevel();
    bool loadvenues();
    void close();
    bool loadendscreen();
    SDL_Texture* loadTexture( std::string path );
    void run();
};