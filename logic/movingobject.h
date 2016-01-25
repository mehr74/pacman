#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H

#include "logic/worldobject.h"

class MovingObject : public WorldObject
{
public:
        MovingObject(GPoint* pnt, GTexture texture, double nSpeed, double aSpeed);

        virtual string ToString() const = 0;
        virtual string DeepToString() const = 0;

protected:


private:
        double normalSpeed;
        double activeSpeed;
};


#endif // MOVING_OBJECT_H
