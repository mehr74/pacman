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
    GPoint* getPreviousPosition() const;

    void setBricks(vector<Brick*> bricks, int maxWidth, int maxHeight);

    GPoint* getInitialPosition() const;

    void changeState(int state);

    int getDirection() const;
    void setDirection(int dir);

    void setTexture(GTexture texture);

    int getStatus() const;

protected:
    bool isActionDone() const;
    vector<int> findPossibleDirections(vector<MovingObject*> movingObjects);
    vector<int> findPossibleDirections() const;

    int getInverseDirection() const;

    bool isGhostAt(int x, int y) const;
    int isGhostAtForPlayer(int x, int y) const;

    GPoint *mapOrigin;
    int mapMaxWidth;
    int mapMaxHeight;
    vector<MovingObject*>ghosts;

private:
    vector<Brick*>getBricks() const;
    Brick* getBrickAt(int x, int y) const;
    void setToNextPosition(int dirX, int dirY);
    void moveSprite(int dirX, int dirY);
    bool isDirectionAllowedForGhosts(int dir) const;
    bool isDirectionAllowedForPlayer(int dir) const;
    vector<Brick*> mapBricks;
    int myNormalSpeed;
    int myActiveSpeed;
    int myDirection;
    int myState;
    Sprite* mySprite;
    GPoint* myPreviousPos;
    GPoint* myInitialPos;
    CCFiniteTimeAction* myAction;
};


#endif // MOVING_OBJECT_H
