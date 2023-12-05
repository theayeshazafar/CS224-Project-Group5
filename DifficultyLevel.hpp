#pragma once
class DifficultyLevel
{
    private:
        static int currentLevel; 
        static int Speed; 
    public:
        static void setLevel(int level);
        static int getCurrentLevel();
        static int getSpeed(); 
};