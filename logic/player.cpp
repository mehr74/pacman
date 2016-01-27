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

void Player::setBonuses(vector<Bonus *> bonuses)
{
    mapBonuses = bonuses;
}

void Player::setScorePoints(vector<ScorePoint *> scorePoints)
{
    mapScorePoints = scorePoints;
}


bool Player::playerMove(int direction, vector<Ghost*> ghosts)
{
    mapGhosts = ghosts;
    vector<int> possibleDirection = this->findPossibleDirections();
    bool isDirectionAllowed = false;
    for(int i = 0; i < possibleDirection.size(); i++)
    {
        if(possibleDirection[i] == direction)
        {
            isDirectionAllowed = true;
        }
    }
    if(!isDirectionAllowed)
        return true;

    this->setDirection(direction);
    this->Move();
    this->updateScore();

}

int Player::getScore() const
{
    return myScore;
}

void Player::updateScore()
{
    int target = findScorePoint(getPosition()->getX(), getPosition()->getY());
    if(target != -1)
    {
        myScore += 10;
        ScorePoint* tmp = mapScorePoints[target];
        mapScorePoints.erase(mapScorePoints.begin() + target);
        delete tmp;
    }
}

int Player::findBonus(int x, int y)
{
    for(int i = 0; i < mapBonuses.size(); i++)
    {
        if(x == mapBonuses[i]->getPosition()->getX() &&
           y == mapBonuses[i]->getPosition()->getY())
        {
            return i;
        }
    }
    return -1;
}

int Player::findScorePoint(int x, int y)
{
    for(int i = 0; i < mapScorePoints.size(); i++)
    {
        if(x == mapScorePoints[i]->getPosition()->getX() &&
           y == mapScorePoints[i]->getPosition()->getY())
        {
            return i;
        }
    }
    return -1;
}
