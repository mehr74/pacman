#include "clyde.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

Clyde::Clyde(GPoint *pnt, GPoint* origin)
    : Ghost(pnt, EClydeDown, origin)
{

}

string Clyde::ToString() const
{
    ostringstream out;
    out << std::left << setw(24) << "Clyde " << "Position: ("
        << std::right << setw(2) << this->getPosition()->getX() << ", "
        << std::right << setw(2) << this->getPosition()->getY() << ")";
    return out.str();
}

string Clyde::DeepToString() const
{
    ostringstream out;
    out << setfill('*') << setw(60) << "" << endl;
    out << setfill(' ') << "* " << std::left << setw(57) << *this << "*" << endl;
    out << setw(15) << "* Prev pos: " << "(" << std::right << setw(2) << this->getPreviousPosition()->getX() << ", "
        << std::right << setw(2) << this->getPreviousPosition()->getY() << ")" << setw(36) << " " << "*" << endl;
    out << std::left << setw(15) << "* Direction : " << setw(44) << ObjectNames::getDirectionName(this->getDirection()) << "*" << endl;
    out << setw(15) << "* Mode: " << setw(44) << ObjectNames::getStateName(this->getStatus()) << "*" << endl;
    out << setfill('*') << setw(60) << "" << endl;
    return out.str();
}

void Clyde::animate()
{
    switch(this->getDirection())
    {
    case UP_DIR:
        this->setTexture(EClydeUp);
        break;
    case DOWN_DIR:
        this->setTexture(EClydeDown);
        break;
    case RIGHT_DIR:
        this->setTexture(EClydeRight);
        break;
    case LEFT_DIR:
        this->setTexture(EClydeLeft);
        break;
    }
}
