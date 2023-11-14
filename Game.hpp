#include <SDL.h>
#include <iostream>
#include <SDL_mixer.h>
class Game
{
    const int SCREEN_HEIGHT = 600;
    const int SCREEN_WIDTH = 800;
    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    
    Mix_Music* music = NULL;

    public:
        SDL_Texture Texture_Loading(); 
        SDL_Window Rendering_of_window();
        void loadsound();
        void playsound();
        void Loading_of_Texture();
};