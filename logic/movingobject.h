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

    void setPosition(GPoint* pnt);
    GPoint* getPreviousPosition();

    void setBricks(vector<Brick*> bricks, int maxWidth, int maxHeight);

protected:
    bool isActionDone() const;
    vector<int> findPossibleDirections(vector<MovingObject*> movingObjects);
    vector<int> findPossibleDirections() const;

    int getStatus() const;

    int getDirection() const;
    void setDirection(int dir);

    int getInverseDirection() const;

    void setTexture(GTexture texture);

    bool isGhostAt(int x, int y) const;

    GPoint *mapOrigin;
    int mapMaxWidth;
    int mapMaxHeight;

private:
    vector<Brick*>getBricks() const;
    Brick* getBrickAt(int x, int y) const;
    void setToNextPosition(int dirX, int dirY);
    void moveSprite(int dirX, int dirY);
    bool isDirectionAllowedForGhosts(int dir) const;
    bool isDirectionAllowedForPlayer(int dir) const;
    vector<Brick*> mapBricks;
    vector<MovingObject*>ghosts;
    int myNormalSpeed;
    int myActiveSpeed;
    int myDirection;
    GState myState;
    Sprite* mySprite;
    GPoint* myPreviousPos;
    CCFiniteTimeAction* myAction;
};


#endif // MOVING_OBJECT_H
