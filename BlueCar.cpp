#include "BlueCar.hpp"
#include "drawing.hpp"
#include "DifficultyLevel.hpp"
using namespace std;

//This function is used to move the BlueCar on the screen and it is overriden from the Unit class
void BlueCar::move()
{
    moverRect.y +=  7 * (DifficultyLevel::getSpeed());
    if (moverRect.y > 650)
   {
    moverRect.y = -50;
    }
}
//This is the default constructor for the BlueCar class
BlueCar::BlueCar()
{
    srcRect = {8,7,74,179};
    moverRect = {177, 120, 44, 100};
}
//This is the overloaded constructor for the BlueCar class which takes in the x and y coordinates 
//and dynamically creates the WhiteCar on the screen at the specified co-ordinates from the factory class
BlueCar::BlueCar(int x, int y)
{       
    srcRect = {8,7,74,179};        
    moverRect = {x , y, 44, 100};       
}
//This is the destructor for the BlueCar class
BlueCar :: ~BlueCar()
{

}