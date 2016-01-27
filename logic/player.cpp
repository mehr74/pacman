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
      myFruit(NULL),
      activeModeTimer(0),
      numberOfGhostEaten(0)
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


bool Player::playerMove(int direction, vector<Ghost*> myghosts, bool arg)
{
    if(arg && direction == this->getDirection())
        return true;
    mapGhosts = myghosts;
    vector<MovingObject*> movingObjects;
    for(int i = 0; i < myghosts.size(); i++)
    {
        movingObjects.push_back(mapGhosts[i]);
    }
    ghosts = movingObjects;
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
    this->animate();
    this->Move();

    if(this->getStatus() != ACTIVE_STATE &&
       isGhostAtForPlayer(getPosition()->getX(), getPosition()->getY()) != -1)
    {
        if(myLifeCount > 0)
        {
            myLifeCount--;
            deleteLifeSprite();
        }
        return false;
    }

    int target = findBonus(this->getPosition()->getX(), this->getPosition()->getY());
    if(target != -1)
    {
        changeStateToActive();
        Bonus* tmp = mapBonuses[target];
        mapBonuses.erase(mapBonuses.begin() + target);
        delete tmp;
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
            myFruit = NULL;
        }
    }

    if(this->getStatus() == ACTIVE_STATE)
    {
        target = isGhostAtForPlayer(this->getPosition()->getX(), this->getPosition()->getY());
        if(target != -1)
        {
            if(mapGhosts[target]->getStatus() == DEAD_STATE)
                return;
            myScore += (numberOfGhostEaten + 1) * 200;
            numberOfGhostEaten++;
            mapGhosts[target]->changeState(DEAD_STATE);
            mapGhosts[target]->setDeadTime(5);
            mapGhosts[target]->setTexture(EOrbDown);
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

void Player::updateFruit()
{
    if(myFruit == NULL)
        return;
    if(myFruit->decrementTimer() == false)
    {
        delete myFruit;
        myFruit = NULL;
    }

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

void Player::changeStateToActive()
{
    numberOfGhostEaten = 0;
    activeModeTimer += 8;
    this->changeState(ACTIVE_STATE);
    for(int i = 0; i < mapGhosts.size(); i++)
    {
        mapGhosts[i]->changeState(ACTIVE_STATE);
        mapGhosts[i]->setTexture(EspiritDefence);
    }
}

void Player::setToInitial()
{
    this->setPosition(this->getInitialPosition());
    for(int i = 0; i < mapGhosts.size(); i++)
    {
        mapGhosts[i]->setPosition(mapGhosts[i]->getInitialPosition());
    }
}

void Player::animate()
{
    switch(this->getDirection())
    {
    case UP_DIR:
        this->setTexture(EPacmanUpOpen);
        break;
    case DOWN_DIR:
        this->setTexture(EPacmanDownOpen);
        break;
    case RIGHT_DIR:
        this->setTexture(EPacmanRightOpen);
        break;
    case LEFT_DIR:
        this->setTexture(EPacmanLeftOpen);
        break;
    }
}

bool Player::isEmptyPoints() const
{
    return mapScorePoints.empty();
}

void Player::updateActiveMode()
{
    for(int i = 0; i < mapGhosts.size(); i++)
    {
        if(mapGhosts[i]->getStatus() == DEAD_STATE)
        {
            mapGhosts[i]->decrementDeadTime();
        }
    }
    if(activeModeTimer > 0)
    {
        activeModeTimer--;
        if(activeModeTimer == 3)
        {
            for(int i = 0; i < mapGhosts.size(); i++)
            {
                mapGhosts[i]->setTexture(ESpiritDefenceWhite);
            }
        }
        else if(activeModeTimer == 0)
        {
            this->changeState(NORMAL_STATE);
            for(int i = 0; i < mapGhosts.size(); i++)
            {
                if(mapGhosts[i]->getStatus() != DEAD_STATE)
                {
                    mapGhosts[i]->changeState(NORMAL_STATE);
                }
            }
        }
    }
}
