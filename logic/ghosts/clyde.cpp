#include "clyde.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

Clyde::Clyde(GPoint *pnt)
    : Ghost(pnt, EClydeDown)
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

}
