#ifndef PLAYER_H
#define PLAYER_H

#include "movingobject.h"

class Player : public MovingObject
{
public:
    Player(GPoint* pnt, GPoint* = new GPoint(0, 0));

    virtual string ToString() const;
    virtual string DeepToString() const;

    void playerMove(int direction);
};


#endif // PLAYER_H
