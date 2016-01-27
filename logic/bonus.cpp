#include <iostream>
#include <iomanip>
#include "bonus.h"
using namespace std;

Bonus::Bonus(GPoint *pos, GPoint *origin)
    : ScoreObject(pos, EBonus, origin)
{

}

string Bonus::DeepToString() const
{
    ostringstream out;
    out << setfill('*') << setw(60) << "" << endl;
    out << setfill(' ') << "* " << std::left << setw(57) << *this << "*" << endl;
    out << setfill('*') << setw(60) << "" << endl;
    return out.str();
}

string Bonus::ToString() const
{
    ostringstream out;
    out << std::left << setw(24) << "Bonus " << "Position: ("
        << std::right << setw(2) << this->getPosition()->getX() << ", "
        << std::right << setw(2) << this->getPosition()->getY() << ")";
    return out.str();
}

int Bonus::getScore() const
{
    return 0;
}
