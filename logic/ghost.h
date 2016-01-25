#ifndef GHOST_H
#define GHOST_H

#include "logic/movingobject.h"

class GPoint;
class Ghost : public MovingObject
{
public:
    Ghost(GPoint* pnt, GTexture texture);

    virtual string ToString() const = 0;
    virtual string DeepToString() const = 0;

protected:


private:


};

#endif
