#include "player.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include "definitions.h"
using namespace std;

Player::Player(GPoint *pnt, GPoint *origin)
    : MovingObject(pnt, EPacmanLeftOpen, PLAYER_NORMAL_SPEED, PLAYER_ACTIVE_SPEED, origin),
      myScore(0),
      myLifeCount(3)
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
    out << setfill('*') << setw(60) << "" << endl;
    out << setfill(' ') << "* " << std::left << setw(57) << *this << "*" << endl;
    out << "* Direction : " << setw(45) << ObjectNames::getDirectionName(this->getDirection()) << "*" << endl;
    out << "* Mode: " << setw(39) << ObjectNames::getStateName(this->getStatus()) << endl;
    out << setfill('*') << setw(60) << "" << endl;
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
    if(isGhostAt(getPosition()->getX(), getPosition()->getY()) == true)
    {
        myLifeCount--;
        deleteLifeSprite();
        return false;
    }
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

void Player::setDefaultLifeSprites()
{
    for(int i = 0; i < 3; i++)
    {
        Sprite *tmp = Sprite::create(ObjectNames::getTextureImage(EPacmanRightClose));
        tmp->setPosition(mapMaxWidth*15 + mapOrigin->getX() - i*20 - 15,
                         mapMaxHeight*15 + mapOrigin->getY() + 10);
        lifeSprites.push_back(tmp);
    }
}

vector<Sprite*> Player::getLifeSprites() const
{
    return lifeSprites;
}

void Player::deleteLifeSprite()
{
    Sprite* sprt = lifeSprites.back();
    sprt->removeFromParentAndCleanup(true);
    lifeSprites.pop_back();
}
