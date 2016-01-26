#include "definitions.h"
#include <time.h>
#include <cstdlib>
#include "ghost.h"


Ghost::Ghost(GPoint *pnt, GTexture texture, GPoint *origin)
    : MovingObject(pnt,texture, GHOST_NORMAL_SPEED, GHOST_ACTIVE_SPEED, origin)
{
    srand(time(NULL));
}

void Ghost::randomMove()
{
    if(this->isActionDone() == false)
        return;
    vector<int> possibleDirection = findPossibleDirections();
    if(possibleDirection.empty())
        return;
    int direction = rand() % possibleDirection.size();
    this->setDirection(possibleDirection[direction]);
    this->Move();
}
