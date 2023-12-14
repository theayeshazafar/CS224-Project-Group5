#include "drawing.hpp"
#include "Unit.hpp"
#include "DifficultyLevel.hpp"
#pragma once

//The move function is overriden from the Unit class
class CatCrossingRoad : public Unit
{

public:
    void move();
    CatCrossingRoad(); 
    CatCrossingRoad(int x, int y);
    ~CatCrossingRoad();
};