#include "drawing.hpp"
#include "Unit.hpp"
#include "DifficultyLevel.hpp"
//RockObstacle class is inherting from Unit class and drawing the rocks on the screen and moving it through its move function
//The move function is overriden from the Unit class
class RockObstacle : public Unit
{
    public:
    RockObstacle();
    RockObstacle(int x, int y);
    void move();
    ~RockObstacle();
};