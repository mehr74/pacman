#include "inky.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

Inky::Inky(GPoint *pos)
    : Ghost(pos, EInkyDown)
{

}

string Inky::ToString() const
{
    ostringstream out;
    out << std::left << setw(24) << "Inky " << "Position: ("
        << std::right << setw(2) << this->getPosition()->getX() << ", "
        << std::right << setw(2) << this->getPosition()->getY() << ")";
    return out.str();
}

string Inky::DeepToString() const
{

}
