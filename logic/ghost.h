#ifndef GHOST_H
#define GHOST_H

#include "logic/movingobject.h"

class GPoint;
class Ghost : public MovingObject
{
public:
    Ghost(GPoint* pnt, GTexture texture, GPoint* origin = new GPoint(0, 0));

    virtual string ToString() const = 0;
    virtual string DeepToString() const = 0;

    void randomMove(vector<Ghost*> ghosts);

    void decrementDeadTime();
    void setDeadTime(int time);

protected:
    virtual void animate() = 0;

private:
    int deadTimer;


};

#endif
