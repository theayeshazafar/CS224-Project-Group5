#include "Ambulance.hpp"
#include "PoliceCar.hpp"
#include "LogObstacle.hpp"
#include "RockObstacle.hpp"
#include "StopObstacle.hpp"
#include "CatCrossingRoad.hpp"
#include "ManCrossingRoad.hpp"
#include "Unit.hpp"
#include "Health.hpp"
#include<vector>
#include<list>
#include<SDL.h>
using namespace std;

/*This class is the core class that creates all objects dynamically and pushes them into a Unit* type list 
which is used in the GameLogic class.*/
class Factory : public Unit
{
    list<Unit*> objects;
    friend class Car_Logic;
    friend class Game;
    int number_of_collisions=0;
    public:
        list<Unit*> CreateObjects();
        ~Factory();
};

