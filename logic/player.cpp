#include "player.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include "definitions.h"
using namespace std;

Player::Player(GPoint *pnt, GPoint *origin)
    : MovingObject(pnt, EPacmanLeftOpen, PLAYER_NORMAL_SPEED, PLAYER_ACTIVE_SPEED, origin)
{

}

string Player::ToString() const
{
    ostringstream out;
    out << std::left << setw(24) << "Pacman " << "Position: ("
        << std::right << setw(2) << this->getPosition()->getX() << ", "
        << std::right << setw(2) << this->getPosition()->getY() << ")";
    return out.str();
}

string Player::DeepToString() const
{
    ostringstream out;
    out << std::left << setw(24) << *this;
    return out.str();
}
