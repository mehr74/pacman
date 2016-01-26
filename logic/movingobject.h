#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H

#include "logic/worldobject.h"
#include "cocos2d.h"

USING_NS_CC;

class MovingObject : public WorldObject
{
public:
    MovingObject(GPoint* pnt, GTexture texture, double normalSpeed, double activeSpeed, GPoint* = new GPoint(0, 0));

    virtual string ToString() const = 0;
    virtual string DeepToString() const = 0;
    void Move();

    int getSpeed();

    void setSprite(Sprite *sprite);
    Sprite* getSprite() const;

protected:


private:
    void setToNextPosition(int speedX, int speedY);
    int myNormalSpeed;
    int myActiveSpeed;
    GDirection myDirection;
    GState myState;
    Sprite* mySprite;
};


#endif // MOVING_OBJECT_H
