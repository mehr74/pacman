#include "logic/scoreobject.h"


ScoreObject::ScoreObject(GPoint *pnt, GTexture texture, GPoint *map)
    : WorldObject(pnt, texture),
      mapOrigin(map)
{
    setSprite(Sprite::create(ObjectNames::getTextureImage(texture)));
}

ScoreObject::~ScoreObject()
{
    mySprite->removeFromParentAndCleanup(true);
}

void ScoreObject::setSprite(Sprite *sprite)
{
    mySprite = sprite;
    mySprite->setPosition(this->getPosition()->getX() * 15 + mapOrigin->getX()
                          , this->getPosition()->getY() * 15  + mapOrigin->getY() );
}

Sprite* ScoreObject::getSprite() const
{
    return mySprite;
}


