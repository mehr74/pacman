#include "brick.h"
#include <iostream>
#include <iomanip>
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
    out << "Brick " << ObjectNames::getTextureName(this->getTexture());
    return out.str();
}

string Brick::DeepToString() const
{
    ostringstream out;
    out << std::left << setw(24) << *this;
    out << "Position: ("
        << std::right << setw(2) << this->getPosition()->getX() << ", "
        << std::right << setw(2) << this->getPosition()->getY() << ")";
    return out.str();
}
