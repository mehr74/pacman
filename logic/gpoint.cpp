#include "gpoint.h"

GPoint::GPoint(int x, int y)
{
    this->x = x;
    this->y = y;
}

int GPoint::getX()
{
    return x;
}

int GPoint::getY()
{
    return y;
}
