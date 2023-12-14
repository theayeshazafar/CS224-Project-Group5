#include "BlueCar.hpp"
#include "RedCar.hpp"
#include "Ambulance.hpp"
#include "Cat.hpp"
#include "Barrier.hpp"
#include "ManCrossingRoad.hpp"
#include "Unit.hpp"
#include "Health.hpp"
#include "PoliceCar.hpp"
#include<vector>
#include<list>
#include<SDL.h>
using namespace std;

/*This class is the core class that creates all objects dynmically and pushes them into a Unit* type list 
which is used in the GameLogic class.*/
class FactoryClass : public Unit
{
    list<Unit*> objects;
    friend class Car_Logic;
    friend class Game;
    int number_of_collisions=0;
    public:
        list<Unit*> CreateObjects();
        ~FactoryClass();
};
