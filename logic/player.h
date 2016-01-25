#ifndef PLAYER_H
#define PLAYER_H

#include "movingobject.h"

class Player : public MovingObject
{
public:
    Player(GPoint* pnt);

    virtual string ToString() const;
    virtual string DeepToString() const;

};


#endif // PLAYER_H
