#include "Factory.hpp"
// This function dynamically creates all assets on the screen through the constructors
// of the assets and pushes them into Unit* type list which is then returned in the CarLogic class.
list<Unit *> Factory::CreateObjects()
{
        if (objects.size() <= 0)
        {
                Ambulance *y1 = new Ambulance();
                objects.push_back(y1);
        }
        if (objects.size() <= 1)
        {
                PoliceCar *w1 = new PoliceCar();
                objects.push_back(w1);
        }
        if (objects.size() <= 2)
        {
                BlueCar *w1 = new BlueCar();
                objects.push_back(w1);
        }
        if (objects.size() <= 3)
        {
                RedCar *tr1 = new RedCar();
                objects.push_back(tr1);
        }
        if (objects.size() <= 4)
        {
                CatCrossingRoad *tu1 = new CatCrossingRoad();
                CatCrossingRoad *tu2 = new CatCrossingRoad(40, 240);
                objects.push_back(tu1), objects.push_back(tu2);
        }
        if (objects.size() <= 5)
        {
                ManCrossingRoad *s1 = new ManCrossingRoad();
                objects.push_back(s1);
        }
        if (objects.size() <= 6)
        {
                LogObstacle *c1 = new LogObstacle();
                objects.push_back(c1);
        }
        if (objects.size() <= 7)
        {
                StopObstacle *c1 = new StopObstacle();
                objects.push_back(c1);
        }
        if (objects.size() <= 8)
        {
                RockObstacle *c1 = new RockObstacle();
                objects.push_back(c1);
        }
        if (objects.size() <= 9)
        {
                if (number_of_collisions == 3)
                {
                }
                if (number_of_collisions == 2)
                {
                        Health *h1 = new Health(771);
                        objects.push_back(h1);
                }
                if (number_of_collisions == 1)
                {
                        Health *h1 = new Health(740);
                        Health *h2 = new Health(771);
                        objects.push_back(h1), objects.push_back(h2);
                }
                if (number_of_collisions == 0)
                {
                        Health *h1 = new Health();
                        Health *h2 = new Health(740);
                        Health *h3 = new Health(771);
                        objects.push_back(h1), objects.push_back(h2), objects.push_back(h3);
                }
        }
        return objects;
}
// This is the destructor which deletes all the assets on the screen.
Factory::~Factory()
{
        for (auto &&i : objects)
        {
                delete i;
        }
        objects.clear();
}