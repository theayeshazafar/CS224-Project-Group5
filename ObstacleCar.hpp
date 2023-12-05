#pragma once
#include "Unit.hpp"
//Obstacle class inherting from Unit class and drawing the obstacle on the screen and moving it through its move function
//The move function is overriden from the Unit class
class ObstacleCar : public Unit{

    int x_coordinate, y_coordinate;
    public:
        void move();
        ObstacleCar(); 
        ObstacleCar(int x, int y);
        ~ObstacleCar();
};