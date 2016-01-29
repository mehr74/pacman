#include "movingobject.h"

bool AllowedDirections[14][4]
{
    {false, false, true, true},     // EHorizontal
    {true, true, false , false},    // EVertical
    {false, true, false, true},     // EAngleLd
    {false, true, true, false},     // EAngleRd
    {true, false, true, false},     // EAngleRv
    {true, false, false, true},     // EAngleLv
    {true, false, false, false},    // EArcUp
    {false, false, false, true},    // EArcLeft
    {false, false, true, false},    // EArcRight
    {false, true, false, false},    // EArcDown
    {false, true, true, true},      // EArc2Up
    {true, true, false, true},      // EArc2Right
    {true, true, true, false},      // EArc2Left
    {true, false, true, true}       // EArc2Down
};

MovingObject::MovingObject(GPoint *pnt, GTexture texture, double normalSpeed, double activeSpeed, GPoint* origin)
    : WorldObject(pnt, texture),
      myNormalSpeed(normalSpeed),
      myActiveSpeed(activeSpeed),
      mapOrigin(origin),
      myState(NORMAL_STATE),
      myDirection(NOT_SET_DIR),
      myInitialPos(pnt)
{
    setSprite(Sprite::create(ObjectNames::getTextureImage(texture)));
    myPreviousPos = this->getPosition();
}

bool MovingObject::isActionDone() const
{
    return true;
}

void MovingObject::setToNextPosition(int dirX, int dirY)
{
    GPoint* prevPos = this->getPosition();
    this->setPosition(new GPoint(prevPos->getX() + 1*dirX, prevPos->getY() + 1*dirY));
}

void MovingObject::moveSprite(int dirX, int dirY)
{
    myAction = MoveBy::create(getSpeed(), Point(15*dirX, 15*dirY));
    mySprite->runAction(myAction);
}

void MovingObject::Move()
{
    switch(myDirection)
    {
    case RIGHT_DIR:
        setToNextPosition(1, 0);
        moveSprite(1, 0);
        break;
    case LEFT_DIR:
        setToNextPosition(-1, 0);
        moveSprite(-1, 0);
        break;
    case UP_DIR:
        setToNextPosition(0, 1);
        moveSprite(0, 1);
        break;
    case DOWN_DIR:
        setToNextPosition(0, -1);
        moveSprite(0, -1);
        break;
    }
}

int MovingObject::getSpeed()
{
    switch(myState)
    {
    case NORMAL_STATE:
        return myNormalSpeed;
    case ACTIVE_STATE:
        return myActiveSpeed;
    case DEAD_STATE:
        return 0;
    }
    return -1;
}

void MovingObject::setSprite(Sprite *sprite)
{
    mySprite = sprite;
    mySprite->setPosition(this->getPosition()->getX() * 15 + mapOrigin->getX()
                          , this->getPosition()->getY() * 15  + mapOrigin->getY() );
}

Sprite* MovingObject::getSprite() const
{
    return mySprite;
}


vector<Brick*> MovingObject::getBricks() const
{
    return mapBricks;
}

Brick* MovingObject::getBrickAt(int x, int y) const
{
    return mapBricks[x + y*mapMaxWidth];
}

void MovingObject::setBricks(vector<Brick *> bricks, int maxWidth, int maxHeight)
{
    mapBricks = bricks;
    mapMaxHeight = maxHeight;
    mapMaxWidth = maxWidth;
}

vector<int> MovingObject::findPossibleDirections(vector<MovingObject*>movingObjects)
{
    ghosts = movingObjects;
    vector<int> directions;
    for(int i = UP_DIR; i <= LEFT_DIR; i++)
    {
        if(isDirectionAllowedForGhosts(i) == true)
            directions.push_back(i);
    }
    return directions;
}

vector<int> MovingObject::findPossibleDirections() const
{
    vector<int> directions;
    for(int i = UP_DIR; i <= LEFT_DIR; i++)
    {
        if(isDirectionAllowedForPlayer(i) == true)
            directions.push_back(i);
    }
    return directions;
}

bool MovingObject::isDirectionAllowedForGhosts(int dir) const
{
    int xAxis = this->getPosition()->getX();
    int yAxis = this->getPosition()->getY();
    Brick* brick;
    if(dir == UP_DIR)
    {
        if(yAxis == mapMaxHeight)
            return false;
        if(isGhostAt(xAxis, yAxis+1) == true)
            return false;
        brick = getBrickAt(xAxis, yAxis+1);
    }
    else if(dir == DOWN_DIR)
    {
        if(yAxis == 0)
            return false;
        if(isGhostAt(xAxis, yAxis-1) == true)
            return false;
        brick = getBrickAt(xAxis, yAxis-1);
    }
    else if(dir == LEFT_DIR)
    {
        if(xAxis == 0)
            return false;
        if(isGhostAt(xAxis-1, yAxis) == true)
            return false;
        brick = getBrickAt(xAxis-1, yAxis);
    }
    else if(dir == RIGHT_DIR)
    {
        if(xAxis == mapMaxWidth)
            return false;
        if(isGhostAt(xAxis+1, yAxis) == true)
            return false;
        brick = getBrickAt(xAxis+1, yAxis);
    }

    int texture = brick->getTexture();
    if(texture <= EArc2Down && texture >= EHorizontal)
        return AllowedDirections[texture-EHorizontal][dir];
    return true;
}

bool MovingObject::isDirectionAllowedForPlayer(int dir) const
{
    int xAxis = this->getPosition()->getX();
    int yAxis = this->getPosition()->getY();
    Brick* brick;
    if(dir == UP_DIR)
    {
        if(yAxis == mapMaxHeight)
            return false;
        brick = getBrickAt(xAxis, yAxis+1);
    }
    else if(dir == DOWN_DIR)
    {
        if(yAxis == 0)
            return false;
        brick = getBrickAt(xAxis, yAxis-1);
    }
    else if(dir == LEFT_DIR)
    {
        if(xAxis == 0)
            return false;
        brick = getBrickAt(xAxis-1, yAxis);
    }
    else if(dir == RIGHT_DIR)
    {
        if(xAxis == mapMaxWidth)
            return false;
        brick = getBrickAt(xAxis+1, yAxis);
    }

    int texture = brick->getTexture();
    if(texture <= EArc2Down && texture >= EHorizontal)
        return AllowedDirections[texture-EHorizontal][dir];
    return true;
}

int MovingObject::getDirection() const
{
    return myDirection;
}

void MovingObject::setDirection(int dir)
{
    myDirection = dir;
}

bool MovingObject::isGhostAt(int x, int y) const
{
    for(int i = 0; i < ghosts.size(); i++)
    {
        if(ghosts[i]->getPosition()->getX() == x &&
           ghosts[i]->getPosition()->getY() == y)
        {
            return true;
        }
        if(ghosts[i]->getPreviousPosition()->getX() == x &&
           ghosts[i]->getPreviousPosition()->getY() == y &&
           ghosts[i] != this)
        {
            return true;
        }
    }
    return false;
}

int MovingObject::isGhostAtForPlayer(int x, int y) const
{
    for(int i = 0; i < ghosts.size(); i++)
    {
        if(ghosts[i]->getPosition()->getX() == x &&
           ghosts[i]->getPosition()->getY() == y)
        {
            return i;
        }
    }
    return -1;
}

void MovingObject::setPosition(GPoint *pnt)
{
    myPreviousPos = this->getPosition();
    WorldObject::setPosition(pnt);
}

GPoint* MovingObject::getPreviousPosition() const
{
    return myPreviousPos;
}

int MovingObject::getInverseDirection() const
{
    switch(myDirection)
    {
    case UP_DIR:
        return DOWN_DIR;
    case DOWN_DIR:
        return UP_DIR;
    case LEFT_DIR:
        return RIGHT_DIR;
    case RIGHT_DIR:
        return LEFT_DIR;
    }
    return NOT_SET_DIR;
}

void MovingObject::setTexture(GTexture texture)
{
    WorldObject::setTexture(texture);
    Node* myParent = this->getSprite()->getParent();
    this->getSprite()->removeFromParentAndCleanup(true);
    this->setSprite(Sprite::create(ObjectNames::getTextureImage(texture)));
    myParent->addChild(this->getSprite());
}

int MovingObject::getStatus() const
{
    return myState;
}

void MovingObject::changeState(int state)
{
    myState = state;
}

GPoint* MovingObject::getInitialPosition() const
{
    return myInitialPos;
}
