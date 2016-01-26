#include "definitions.h"
#include <time.h>
#include <cstdlib>
#include "ghost.h"


Ghost::Ghost(GPoint *pnt, GTexture texture, GPoint *origin)
    : MovingObject(pnt,texture, GHOST_NORMAL_SPEED, GHOST_ACTIVE_SPEED, origin)
{
    srand(time(NULL));
}

void Ghost::randomMove(vector<Ghost*>ghosts)
{
    if(this->isActionDone() == false)
        return;
    vector<MovingObject*>movingObjects;
    for(int i = 0; i < ghosts.size(); i++)
    {
        movingObjects.push_back(ghosts[i]);
    }
    vector<int> possibleDirection = findPossibleDirections(movingObjects);
    if(possibleDirection.empty())
        return;
    if(possibleDirection.size() > 1)
    {
        for(int i = 0; i < possibleDirection.size(); i++)
        {
            if(possibleDirection[i] == this->getInverseDirection())
                possibleDirection.erase(possibleDirection.begin() + i);
        }
    }

    int direction = rand() % possibleDirection.size();
    this->setDirection(possibleDirection[direction]);
    this->Move();
//    this->animate();
}
