#ifndef PLAYER_H
#define PLAYER_H

#include "logic/ghost.h"
#include "logic/scorepoint.h"
#include "logic/fruit.h"
#include "logic/bonus.h"
#include "movingobject.h"


class Player : public MovingObject
{
public:
    Player(GPoint* pnt, GPoint* = new GPoint(0, 0));

    bool isEmptyPoints() const;

    virtual string ToString() const;
    virtual string DeepToString() const;

    int getScore() const;
    int getLifeCount() const;

    void setBonuses(vector<Bonus*>bonuses);
    void setScorePoints(vector<ScorePoint*>scorePoints);

    void setDefaultLifeSprites();
    vector<Sprite*> getLifeSprites() const;

    void addFruit();
    Fruit* getFruit() const;

    void deleteLifeSprite();

    bool playerMove(int direction, vector<Ghost*> ghosts, bool arg = true);

    void updateScore();
    void updateFruit();
    void updateActiveMode();

    void changeStateToActive();

    void animate();

private:
    void setToInitial();
    int findScorePoint(int x, int y) const;
    int findBonus(int x, int y) const;
    int findFruit(int x, int y) const;
    vector<Ghost*> mapGhosts;
    vector<Bonus*> mapBonuses;
    vector<ScorePoint*> mapScorePoints;
    vector<Sprite*> lifeSprites;
    int myLifeCount;
    int myScore;
    Fruit* myFruit;
    int numberOfGhostEaten;
    int activeModeTimer;
};


#endif // PLAYER_H
