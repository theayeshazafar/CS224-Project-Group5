#include "DifficultyLevel.hpp"

int DifficultyLevel::currentLevel = 0;
int DifficultyLevel::Speed = 1; // By Default Game will be start at Easy Mode so speed is 1. For Medium its 2 and for Hard its 3.

void DifficultyLevel::setLevel(int level)
{
    currentLevel = level;
    switch (currentLevel)
        {
        case 0:
            Speed = 1;
            break;
        case 1:
            Speed = 2;
            break;
        case 2:
            Speed = 3;
            break;
        default:
            break;
    }
}
int DifficultyLevel::getCurrentLevel()
{
    return currentLevel;
}
int DifficultyLevel::getSpeed()
{
    return Speed;
}