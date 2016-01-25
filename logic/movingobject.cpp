#include "movingobject.h"

MovingObject::MovingObject(GPoint *pnt, GTexture texture, double nSpeed, double aSpeed)
    : WorldObject(pnt, texture),
      normalSpeed(nSpeed),
      activeSpeed(aSpeed)
{

}
