#include "pinky.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

Pinky::Pinky(GPoint *pos, GPoint* origin)
    : Ghost(pos, EPinkyDown, origin)
{

}

string Pinky::ToString() const
{
    ostringstream out;
    out << std::left << setw(24) << "Pinky " << "Position: ("
        << std::right << setw(2) << this->getPosition()->getX() << ", "
        << std::right << setw(2) << this->getPosition()->getY() << ")";
    return out.str();
}

string Pinky::DeepToString() const
{

}
