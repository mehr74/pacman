#include "movingobject.h"

MovingObject::MovingObject(GPoint *pnt, GTexture texture, double normalSpeed, double activeSpeed, GPoint* origin)
    : WorldObject(pnt, texture),
      myNormalSpeed(normalSpeed),
      myActiveSpeed(activeSpeed),
      mapOrigin(origin)
{
    setSprite(Sprite::create(ObjectNames::getTextureImage(texture)));
}

void MovingObject::setToNextPosition(int speedX, int speedY)
{
    GPoint* prevPos = this->getPosition();
    this->setPosition(new GPoint(prevPos->getX() + speedX, prevPos->getY() + speedY));
}

void MovingObject::Move()
{
    switch(myDirection)
    {
    case RIGHT_DIR:
        setToNextPosition(getSpeed(), 0);
        break;
    case LEFT_DIR:
        setToNextPosition((-1)*getSpeed(), 0);
        break;
    case UP_DIR:
            setToNextPosition(0, getSpeed());
        break;
    case DOWN_DIR:
            setToNextPosition(0, (-1)*getSpeed());
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
