#include <iostream>
#include <iomanip>
#include "scorepoint.h"
#include "definitions.h"
using namespace std;

const int ourScore = SCORE_POINT;

ScorePoint::ScorePoint(GPoint *pos, GPoint *origin)
    : ScoreObject(pos, EPoint, origin)
{

}

string ScorePoint::DeepToString() const
{
    ostringstream out;
    out << setfill('*') << setw(60) << "" << endl;
    out << setfill(' ') << "* " << std::left << setw(57) << *this << "*" << endl;
    out << setfill('*') << setw(60) << "" << endl;
    return out.str();
}

string ScorePoint::ToString() const
{
    ostringstream out;
    out << std::left << setw(24) << "Scorepoint: " << "Position: ("
        << std::right << setw(2) << this->getPosition()->getX() << ", "
        << std::right << setw(2) << this->getPosition()->getY() << ")";
    return out.str();
}

int ScorePoint::getScore() const
{
    return 10;
}
