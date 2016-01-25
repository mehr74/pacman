#ifndef BRICK_H
#define BRICK_H

#include "cocos2d.h"
#include "logic/gpoint.h"
#include "logic/worldobject.h"
using namespace std;

class Brick : public WorldObject
{
    public:
        Brick(GPoint* pnt, GTexture texture, int width = 30, int height = 30);

        virtual string ToString() const;
        virtual string DeepToString() const;
};

#endif // BRICK_H
