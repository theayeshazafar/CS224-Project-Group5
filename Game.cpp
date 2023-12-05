#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* image1;
SDL_Texture* image2;
SDL_Texture* image3;
SDL_Texture* image4;
SDL_Texture* image5;
SDL_Texture* image6;  // New texture for the sixth image
SDL_Rect imageRect;
bool isImage1 = true;
bool isImage2 = false;
bool isImage3 = false;
bool isImage4 = false;
bool isImage5 = false;
bool isImage6 = false;  // New flag for the sixth image

// Function to load images
bool loadImages()
{
    SDL_Surface* surface1 = IMG_Load("Start Screen.png");
    SDL_Surface* surface2 = IMG_Load("Instruction.png");
    SDL_Surface* surface3 = IMG_Load("Location.png");
    SDL_Surface* surface4 = IMG_Load("Difficulty.png");
    SDL_Surface* surface5 = IMG_Load("game_depiction.png");
    SDL_Surface* surface6 = IMG_Load("Game_Over_Screen.png");
    
    if (!surface1 || !surface2 || !surface3 || !surface4 || !surface5 || !surface6)
    {
        std::cout << "Failed to load images: " << SDL_GetError() << std::endl;
        return false;
    }

    image1 = SDL_CreateTextureFromSurface(renderer, surface1);
    image2 = SDL_CreateTextureFromSurface(renderer, surface2);
    image3 = SDL_CreateTextureFromSurface(renderer, surface3);
    image4 = SDL_CreateTextureFromSurface(renderer, surface4);
    image5 = SDL_CreateTextureFromSurface(renderer, surface5);
    image6 = SDL_CreateTextureFromSurface(renderer, surface6);  // Create texture for the sixth image

    if (!image1 || !image2 || !image3 || !image4 || !image5 || !image6)
    {
        std::cout << "Failed to create textures: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_FreeSurface(surface1);
    SDL_FreeSurface(surface2);
    SDL_FreeSurface(surface3);
    SDL_FreeSurface(surface4);
    SDL_FreeSurface(surface5);
    SDL_FreeSurface(surface6);
    return true;
}

int main(int argc, char* argv[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create window and renderer
    window = SDL_CreateWindow("Pakistan Drift", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!window || !renderer)
    {
        std::cout << "Failed to create window or renderer: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Load images
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    if (!loadImages())
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Set initial image
    imageRect.x = 0;
    imageRect.y = 0;
    imageRect.w = 800;
    imageRect.h = 600;
    SDL_RenderCopy(renderer, image1, NULL, &imageRect);
    SDL_RenderPresent(renderer);

    // Event loop
    SDL_Event event;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_MOUSEBUTTONUP:
                // Check mouse click
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    int mouseX = event.button.x;
                    int mouseY = event.button.y;
                    if (mouseX >= imageRect.x && mouseX < imageRect.x + imageRect.w &&
                        mouseY >= imageRect.y && mouseY < imageRect.y + imageRect.h)
                    {
                        // Change image
                        if (isImage1)
                        {
                            SDL_RenderCopy(renderer, image2, NULL, &imageRect);
                            isImage1 = false;
                            isImage2 = true;
                        }
                        else if (isImage2)
                        {
                            SDL_RenderCopy(renderer, image3, NULL, &imageRect);
                            isImage2 = false;
                            isImage3 = true;
                        }
                        else if (isImage3)
                        {
                            SDL_RenderCopy(renderer, image4, NULL, &imageRect);
                            isImage3 = false;
                            isImage4 = true;
                        }
                        else if (isImage4)
                        {
                            SDL_RenderCopy(renderer, image5, NULL, &imageRect);
                            isImage4 = false;
                            isImage5 = true;
                        }
                        else if (isImage5)
                        {
                            SDL_RenderCopy(renderer, image6, NULL, &imageRect);  // Render the sixth image
                            isImage5 = false;
                            isImage6 = true;
                        }
                        else if (isImage6)
                        {
                            SDL_RenderCopy(renderer, image1, NULL, &imageRect);
                            isImage6 = false;
                            isImage1 = true;  // Change isImage1 to true to go back to the start screen.
                        }

                        SDL_RenderPresent(renderer);
                    }
                }
                break;
            }
        }
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    return 0;
}
