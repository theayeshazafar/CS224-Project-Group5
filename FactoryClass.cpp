#include "FactoryClass.hpp"
// This function dynamically creates all assets on the screen through the constructors
// of the assets and pushes them into Unit* type list which is then returned in the Car_Logic class.
list<Unit *> FactoryClass::CreateObjects()
{
        if (objects.size() <= 0)
        {
                BlueCar *y1 = new BlueCar();
                objects.push_back(y1);
        }
        if (objects.size() <= 1)
        {
                PoliceCar *w1 = new PoliceCar();
                objects.push_back(w1);
        }
        if (objects.size() <= 2)
        {
                RedCar *w1 = new RedCar();
                objects.push_back(w1);
        }
        if (objects.size() <= 3)
        {
                Ambulance *tr1 = new Ambulance();
                objects.push_back(tr1);
        }
        if (objects.size() <= 4)
        {
                Cat *tu1 = new Cat();
                objects.push_back(tu1);
        }
        if (objects.size() <= 6)
        {
                Barrier *c1 = new Barrier();
                objects.push_back(c1);
        }
        if (objects.size() <= 7)
        {
                ManCrossingRoad *s1 = new ManCrossingRoad();
                objects.push_back(s1);
        }
        if (objects.size() <= 8)
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
FactoryClass ::~FactoryClass()
{
        for (auto &&i : objects)
        {
                delete i;
        }
        objects.clear();
}