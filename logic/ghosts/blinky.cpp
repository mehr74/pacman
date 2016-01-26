#include "blinky.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

Blinky::Blinky(GPoint *pnt, GPoint *origin)
    : Ghost(pnt, EBlinkyLeft, origin)
{

}

string Blinky::ToString() const
{
    ostringstream out;
    out << std::left << setw(24) << "Blinky " << "Position: ("
        << std::right << setw(2) << this->getPosition()->getX() << ", "
        << std::right << setw(2) << this->getPosition()->getY() << ")";
    return out.str();
}

string Blinky::DeepToString() const
{

}

void Blinky::animate()
{
    switch(this->getDirection())
    {
    case UP_DIR:
        this->setTexture(EBlinkyUp);
        break;
    case DOWN_DIR:
        this->setTexture(EBlinkyDown);
        break;
    case RIGHT_DIR:
        this->setTexture(EBlinkyRight);
        break;
    case LEFT_DIR:
        this->setTexture(EBlinkyLeft);
        break;
    }
}
