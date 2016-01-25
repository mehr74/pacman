#include "worldobject.h"

USING_NS_CC;

WorldObject::WorldObject(GPoint* pnt, GTexture texture, int width, int height)
{
    this->width = width;
    this->height = height;
    this->gTexture = texture;
    this->position = pnt;
}

GTexture WorldObject::getTexture() const
{
    return gTexture;
}


GPoint* WorldObject::getPosition() const
{
    return position;
}

void WorldObject::setPosition(GPoint* pnt)
{
    position = pnt;
}

ostream& operator << (ostream& out, const WorldObject& obj)
{
    out << obj.ToString();
    return out;
}
