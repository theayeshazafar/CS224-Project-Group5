#include "drawing.hpp"
#include "Unit.hpp"
#include "DifficultyLevel.hpp"
//LogObstacle class is inherting from Unit class and drawing the log on the screen and moving it through its move function
//The move function is overriden from the Unit class
class LogObstacle : public Unit
{
    public:
    LogObstacle();
    LogObstacle(int x, int y);
    void move();
    ~LogObstacle();
};
