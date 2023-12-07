#include "drawing.hpp"
#include "Unit.hpp"
#include "DifficultyLevel.hpp"
//StopObstacle class is inherting from Unit class and drawing the STOP SIGN on the screen and moving it through its move function
//The move function is overriden from the Unit class
class StopObstacle : public Unit
{
    public:
    StopObstacle();
    StopObstacle(int x, int y);
    void move();
    ~StopObstacle();
};