#include "game.hpp"
#include <iostream>
using namespace std;

SDL_Renderer *Drawing::gRenderer = NULL;
SDL_Texture *Drawing::assets = NULL;
int venue_choose = 0;
DifficultyLevel level; // This instance will help us to multiply the speed to objects for differnet Difficulty Level.
bool Game::init()
{
	// Initialization flag
	bool success = true;
	// Initializing SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		// Setting texture scaling quality mode to "linear", with 1 stands for linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}
		// Here the sound sampling frequency is 44100 Hz with 2 representing stereotype sound
		// in third parameter
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		{
			printf("Unable to open audio: %s\n", Mix_GetError());
			success = false;
		}
		// Creating window,which will be rendered at the centre of the screen
		// Initilaizing the window
		gWindow = SDL_CreateWindow("Pakistan Drift", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			// Creating renderer for window
			Drawing::gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (Drawing::gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				// Initialize renderer color. This will draw requested objects of given r,g,b and with
				// full opacity as defined by 0xFF
				SDL_SetRenderDrawColor(Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				// Initialize PNG loading
				int image_check = IMG_INIT_PNG;
				if (!(IMG_Init(image_check) & image_check))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}
	return success;
}

// This function loads the Main Menu Screen of the game.
bool Game::loadMedia()
{
	// Loading success flag
	bool success = true;
	music = Mix_LoadMUS("StartMusic.mp3");
	Mix_PlayMusic(music, -1);
	gTexture = loadTexture("startscreen.jpg");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}

	if (music = NULL)
	{
		printf("Failed to load the theme music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	return success;
}

// This function loads the background screen of the game where the assets appear.
bool Game::loadGame()
{
	// Loading success flag
	bool success = true;
	music = Mix_LoadMUS("GameplayMusic.mp3");
	Mix_PlayMusic(music, -1);
	Drawing::assets = loadTexture("Final_Sprite_Pack-removebg-preview (2)__.png");
	if (venue_choose == 1)
		gTexture = loadTexture("BackgroundDessert.jpg");
	else if (venue_choose == 2)
		gTexture = loadTexture("BackgroundSummer.jpg");
	else if (venue_choose == 3)
		gTexture = loadTexture("BackgroundSnow.png");
	if (Drawing::assets == NULL || gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}
// This function will load the screen where it gives player option to choose between differnet venues.
bool Game::loadvenues()
{
	// Loading success flag
	bool success = true;
	gTexture = loadTexture("locationscreen.jpg");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}
// This function loads the Selection screen of Difficulty Level of the game.
bool Game::loadLevel()
{
	// Loading success flag
	bool success = true;
	gTexture = loadTexture("difficultyscreen.jpg");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}
// This function loads the GameOver Screen of the game.
bool Game::loadendscreen()
{
	// Loading success flag
	bool success = true;
	music = Mix_LoadMUS("StartMusic.mp3");
	Mix_PlayMusic(music, -1);
	gTexture = loadTexture("gameoverscreen.jpg");

	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

// This function loads the Instructions screen of the game.
bool Game::loadInstructions()
{
	// Loading success flag
	bool success = true;
	gTexture = loadTexture("instructionscreen.jpg");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

// checking if the mouse click is in the specified coordinates
bool Game::handleInstructionClick()
{
    int xMouse, yMouse;
    SDL_GetMouseState(&xMouse, &yMouse);

    // Check if the click falls within the specified coordinates
    if (xMouse > 580 && xMouse < 735 && yMouse > 520 && yMouse < 560)
    {
        // Transition to start screen
        state = 0; // Set the desired state for the start screen
        loadMedia(); // Load the start screen
        return true; // Return true to indicate that the click was handled
    }

    return false; // Return false if the click was not handled
}

void Game::close()
{
	// Free loaded images
	SDL_DestroyTexture(Drawing::assets);
	Drawing::assets = NULL;
	SDL_DestroyTexture(gTexture);
	// Destroy window
	SDL_DestroyRenderer(Drawing::gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	Drawing::gRenderer = NULL;
	// Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
SDL_Texture *Game::loadTexture(std::string path)
{
	// The final texture
	SDL_Texture *newTexture = NULL;

	// Load image at specified path
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		// Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(Drawing::gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		// Get rid of old loaded surface and freeing our Resources.
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}
// This function is responsible for the game logic and it creates the Car_Logic object responsible for the running of game.
void Game::run()
{
	bool quit = false;
	SDL_Event e;
	Car_Logic carlogic;
	SDL_Rect bg_SrcRect = {0, 0, 800, 600};
	SDL_Rect bg_MovRect = {0, 0, 800, 600};

	SDL_SetRenderDrawColor(Drawing::gRenderer, 255, 255, 255, 255);
	while (!quit)
	{
		// Once all three healths are lost the game lost screen is loaded.
		if (carlogic.objects.size() < 8 && state == 1)
		{
			state = 3;
			carlogic.objectcheck = false;
			loadendscreen();
		}
		// Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			// User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);
				// Upon tapping the Play button the game starts.
				if (state == 0 && xMouse > 537 && xMouse < 766 && yMouse > 500 && yMouse < 570)
				{
					state = 5;
					loadvenues();
				}
				// Check if in instruction screen and handle the click
                if (state == 2)
                {
                    if (handleInstructionClick())
                    {
                        // The click was handled, continue to the next iteration
                        continue;
                    }
				}
				// Upon Clicking, Venue will be choosen
				if (state == 5 && xMouse > 288 && xMouse < 508 && yMouse > 165 && yMouse < 230)
				{
					state = 1;
					venue_choose = 1;
					loadGame();
				}
				if (state == 5 && xMouse > 557 && xMouse < 770 && yMouse > 165 && yMouse < 230)
				{
					state = 1;
					venue_choose = 2;
					loadGame();
				}
				if (state == 5 && xMouse > 25 && xMouse < 245 && yMouse > 165 && yMouse < 230)
				{
					state = 1;
					venue_choose = 3;
					loadGame();
				}
				// Upon tapping on selection of Difficulty Level, get to Level Selection screen.
				if (state == 0 && xMouse > 30 && xMouse < 316 && yMouse > 559 && yMouse < 578)
				{
					state = 4;
					loadLevel();
				}
				// Upon tapping the instructions button the instructions screen is loaded.
				if (state == 0 && xMouse > 30 && xMouse < 230 && yMouse > 525 && yMouse < 550)
				{
					state = 2;
					loadInstructions();
				}
				// It returns the game back to home screen and when the user taps play the game starts.
				if (state == 2 && xMouse > 264 && xMouse < 567 && yMouse > 396 && yMouse < 439)
				{
					state = 0;
					loadMedia();
				}
				// It returns the user from the Game Over screen to the home screen.
				if (state == 3 && xMouse >= 538 && xMouse <= 770 && yMouse >= 500 && yMouse <= 565)
				{
					state = 0;
					loadMedia();
				}
				// It returns to home screen from Level Choosing Screen.
				if (state == 4 && xMouse >= 538 && xMouse <= 762 && yMouse >= 505 && yMouse <= 575)
				{
					state = 0;
					loadMedia();
				}
				// Following will handle selection of level
				if (state == 4 && xMouse >= 555 && xMouse <= 775 && yMouse >= 175 && yMouse <= 235)
				{
					level.setLevel(2); // This will tell that player want to play in Hard Mode
				}
				if (state == 4 && xMouse >= 288 && xMouse <= 512 && yMouse >= 175 && yMouse <= 235)
				{
					level.setLevel(1); // This will tell that player want to play in Medium Mode
				}
				if (state == 4 && xMouse >= 26 && xMouse <= 242 && yMouse >= 175 && yMouse <= 235)
				{
					level.setLevel(0); // This will tell that player want to play in Easy Mode
				}
			}
			// These are the keyboard events.
			const Uint8 *state = SDL_GetKeyboardState(NULL);
			if (state[SDL_SCANCODE_UP])
			{
				carlogic.checkup = true;
			}
			if (state[SDL_SCANCODE_DOWN])
			{
				carlogic.checkdown = true;
			}
			if (state[SDL_SCANCODE_RIGHT])
			{
				carlogic.checkright = true;
			}
			if (state[SDL_SCANCODE_LEFT])
			{
				carlogic.checkleft = true;
			}
		}
		SDL_RenderClear(Drawing::gRenderer); // removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, &bg_SrcRect, &bg_MovRect);
		if (state == 1)
		{
			bg_MovRect.h = 2000;
			bg_SrcRect.h = 2000;
			carlogic.createObject();
			carlogic.drawObjects();
			carlogic.CheckCollision();

			if (bg_MovRect.y < 0)
				bg_MovRect.y += (4) * level.getSpeed();
			else
				bg_MovRect.y = -1000;
		}
		else
		{
			bg_MovRect.y = 0;
			bg_MovRect.h = 600;
			bg_SrcRect.h = 600;
		}
		SDL_RenderPresent(Drawing::gRenderer); // displays the updated renderer
		SDL_Delay(100);						   // causes sdl engine to delay for specified miliseconds
	}
}