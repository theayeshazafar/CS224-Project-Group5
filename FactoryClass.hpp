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

/*Polymorphism is done here as it allows us to treat objects of different classes through a common interface. 
Here the list<Unit *> objects achieves polymorphism by storing pointers to objects 
of various derived classes in a list, where all these classes inherit from the common base class Unit. And the objects are iteratively
drawn in CarLogic Class*/

// FactoryClass focuses on the dynamic creation and management of instances of game assets.

/*This class is the core class that creates all objects dynmically and pushes them into a Unit* type list 
which is used in the GameLogic class.*/
class FactoryClass : public Unit
{
    list<Unit*> objects; /* helps in encapsulating objects so that they can be iterated for collision and drawing, 
    achieves runtime dynamic creation */
    friend class Car_Logic;
    friend class Game;
    int number_of_collisions=0;
    public:
        list<Unit*> CreateObjects();
        ~FactoryClass();
};
