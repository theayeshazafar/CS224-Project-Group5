#ifndef KEYBOARDINPUT_H
#define KEYBOARDINPUT_H

#include <SDL.h>
#include <vector>

class KeyboardInput {
public:
    void update();
    bool isKeyForward(SDL_Keycode key);
    bool isKeyBackward(SDL_Keycode key);
    bool isKeyRight(SDL_Keycode key);
    bool isKeyLeft(SDL_Keycode key);
private:
    KeyboardInput();
    ~KeyboardInput();
};

#endif
