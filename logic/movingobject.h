#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H

#include "logic/worldobject.h"
#include "logic/brick.h"
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

    void setBricks(vector<Brick*> bricks, int maxWidth, int maxHeight);

protected:
    bool isActionDone() const;
    vector<int> findPossibleDirections() const;

    int getDirection() const;
    void setDirection(int dir);

private:
    vector<Brick*>getBricks() const;
    Brick* getBrickAt(int x, int y) const;
    void setToNextPosition(int dirX, int dirY);
    void moveSprite(int dirX, int dirY);
    bool isDirectionAllowed(int dir) const;
    vector<Brick*> mapBricks;
    GPoint *mapOrigin;
    int mapMaxWidth;
    int mapMaxHeight;
    int myNormalSpeed;
    int myActiveSpeed;
    int myDirection;
    GState myState;
    Sprite* mySprite;
    CCFiniteTimeAction* myAction;
    bool hasAction;
};


#endif // MOVING_OBJECT_H
