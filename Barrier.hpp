#include "drawing.hpp"
#include "Unit.hpp"
#include "DifficultyLevel.hpp"
//Barrier class is inherting from Unit class and drawing the Barrier on the screen and moving it through its move function
//The move function is overriden from the Unit class
class Barrier : public Unit
{
    public:
    Barrier(); 
    Barrier(int x, int y);
    void move();
    ~Barrier(); 
};