#include "CatCrossingRoad.hpp"
#include "drawing.hpp"

//This function is used to move the Cat on the screen and it is overriden from the Unit class
//additionally it inherits animation variable from the Unit class to animate the Cat based on the srcRect values.
void CatCrossingRoad::move()
{
    switch (animation)
    {
    case 0:                         
        srcRect = {184,455,72,31};     
        animation = 1;                  
        break;
    case 1:                             
        srcRect = {259,454,73,33};        
        animation = 2;                          
        break;  
    case 2:                                
        srcRect = {333,459,73,31};          
        animation = 3;                     
    case 3:
        srcRect = {408,456,76,32};
        animation = 0;
    default:
        animation = 0;              
        break;
    }
    moverRect.x += (8*DifficultyLevel::getSpeed());
    if (moverRect.x > 850)
    {
        moverRect.x = -200;
    }
}

//This is the default constructor for the CatCrossingRoad class
CatCrossingRoad::CatCrossingRoad()
{
   
    srcRect = {184,455,72,31};
    moverRect = {0, 290, 70, 30};
}

//This is the overloaded constructor for the CatCrossingRoad class which takes in the x and y coordinates of the Cat 
//and dynamically creates the Cat on the screen at the specified co-ordinates from the factory class
CatCrossingRoad::CatCrossingRoad(int x, int y)
{      
    srcRect = {184,455,72,31};        
    moverRect = {x , y, 70, 30};       
}

//This is the destructor for the class
CatCrossingRoad::~CatCrossingRoad()
{}

