#ifndef Displaying_Game_Information_H
#define Displaying_Game_Information_H

#include <SDL.h>
#include <SDL_ttf.h>

class DisplayingGameInformation
{
private:
    SDL_Renderer* Renderer;
    SDL_Texture* scoreTexture; // Showing score of player
    SDL_Texture* SpeedTexture; // Showing speed of players car
    SDL_Texture* LivesTexture;  //Showing remaining lives
    SDL_Rect SpeedRect;
    SDL_Rect LivesRect;
public:
    DisplayingGameInformation();
    ~DisplayingGameInformation();

    void UpdateScore(int score);
    void UpdateSpeed(int speed);
    void UpdateLives(int lives);
    void displayingScore();
    void displayingLives();
    void displayingSpeed();
};

#endif 