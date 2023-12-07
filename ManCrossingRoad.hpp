#include "drawing.hpp"
#include "Unit.hpp"

// ManCrossingRoad class inherting from Unit class and drawing the ManCrossingRoad on the screen and moving it through its move function
// The move function is overriden from the Unit class

class ManCrossingRoad : public Unit
{
public:
    void move();
    ManCrossingRoad();
    ManCrossingRoad(int x, int y);
    ~ManCrossingRoad();
};