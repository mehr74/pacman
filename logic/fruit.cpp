#include <iostream>
#include <iomanip>
#include "fruit.h"
#include "definitions.h"
using namespace std;

Fruit::Fruit(GPoint *pos, GPoint* origin)
    : ScoreObject(pos, EBanana, origin),
      myTimer(8)
{
}

string Fruit::DeepToString() const
{
    ostringstream out;
    out << setfill('*') << setw(60) << "" << endl;
    out << setfill(' ') << "* " << std::left << setw(57) << *this << "*" << endl;
    out << setfill('*') << setw(60) << "" << endl;
    return out.str();
}

string Fruit::ToString() const
{
    ostringstream out;
    out << std::left << setw(24) << "Fruit " << "Position: ("
        << std::right << setw(2) << this->getPosition()->getX() << ", "
        << std::right << setw(2) << this->getPosition()->getY() << ")";
    return out.str();
}

bool Fruit::decrementTimer()
{
    if(myTimer > 0)
    {
        myTimer--;
        return true;
    }
    return false;
}

int Fruit::getScore() const
{
    if(myTimer >= 3)
        return 500;
    return 200;
}
