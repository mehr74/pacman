#include "player.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include "definitions.h"
using namespace std;

Player::Player(GPoint *pnt, GPoint *origin)
    : MovingObject(pnt, EPacmanLeftOpen, PLAYER_NORMAL_SPEED, PLAYER_ACTIVE_SPEED, origin),
      myScore(0),
      myLifeCount(3),
      myFruit(NULL)
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
    out << setw(15) << "* Prev pos: " << "(" << std::right << setw(2) << this->getPreviousPosition()->getX() << ", "
        << std::right << setw(2) << this->getPreviousPosition()->getY() << ")" << setw(36) << " " << "*" << endl;
    out << std::left << setw(15) << "* Direction : " << setw(44) << ObjectNames::getDirectionName(this->getDirection()) << "*" << endl;
    out << setw(15) << "* Mode: " << setw(44) << ObjectNames::getStateName(this->getStatus()) << "*" << endl;
    out << setw(15) << "* Score: " << setw(44) << this->getScore() << "*" << endl;
    out << setw(15) << "* Lives : " << setw(44) << this->getLifeCount() << "*" << endl;
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

    if(myFruit != NULL)
    {
        target = findFruit(getPosition()->getX(), getPosition()->getY());
        if(target != -1)
        {
            myScore += 500;
            delete myFruit;
        }
    }
}

int Player::findBonus(int x, int y) const
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

int Player::findScorePoint(int x, int y) const
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

int Player::findFruit(int x, int y) const
{

    if(x == myFruit->getPosition()->getX() &&
       y == myFruit->getPosition()->getY())
    {
        return true;
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

int Player::getLifeCount() const
{
    return myLifeCount;
}


void Player::addFruit()
{

    if(mapScorePoints.empty())
        return;
    int index = rand() % mapScorePoints.size();
    ScorePoint *tmp = mapScorePoints[index];
    mapScorePoints.erase(mapScorePoints.begin() + index);
    myFruit = new Fruit(new GPoint(tmp->getPosition()->getX(), tmp->getPosition()->getY()), mapOrigin);
    delete tmp;
}

Fruit* Player::getFruit() const
{
    return myFruit;
}
