#include "brick.h"
#include <iostream>
#include <sstream>
USING_NS_CC;
using namespace std;

Brick::Brick(GPoint* pnt, GTexture texture, int width, int height)
    : WorldObject(pnt, texture, width, height)
{
}

string Brick::ToString() const
{
    ostringstream out;
    out << "Brick (" ;
    return out.str();
}

string Brick::DeepToString() const
{
    ostringstream out;
    out << *this;
    return out.str();
}
