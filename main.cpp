#include "Game.hpp"

int main(int argc, char *argv[])
{
    Game game;
    srand(time(NULL)); // time(NULL) function returns the current time in seconds so this line of code is to
                       //  ensure that we have unique random number generated at every time.
    if (!game.init()) // If our Game fail to initialize
    {
        printf("Failed to initialize!\n");
        return 0;
    }
    // Load media
    if (!game.loadMedia())
    {
        printf("Failed to load media!\n");
        return 0;
    }

    game.run();
    game.close();

    return 0;
}