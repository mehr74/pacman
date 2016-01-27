#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "cocos2d.h"
#include "logic/objectnames.h"
#include "gpoint.h"
#include "logic/scorepoint.h"
using namespace std;

class Brick;
class Ghost;
class Player;
class Inky;
class Pinky;
class Blinky;
class Clyde;
class Fruit;
class Bonus;
class GameMap
{
    public:
        GameMap(std::string mapFile, int winWidth, int winHeight);


        vector<Brick*> getBricks() const;
        vector<Ghost*> getGhosts() const;
        vector<ScorePoint*> getScorePoints() const;
        vector<Bonus*>getBonuses() const;
        Player* getPlayer() const;
        int getMaxWidth() const;
        int getMaxHeight() const;

        GPoint* getPlayerPos() const;
        void setPlayerPos(GPoint* pos);

        GPoint* getGhostPos(GGhost ghost) const;
        void setGhostPos(GGhost ghost, GPoint* pos) const;

    private:
        void initializeMap(std::string mapFile);
        GPoint* mapOrigin;
        vector<Brick*> bricks;
        vector<Ghost*> ghosts;
        vector<GGhost> ghostTypes;
        vector<Bonus*> bonuses;
        vector<ScorePoint*> scorePoints;
        Player* player;
        int maxWidth;
        int maxHeight;
        int winWidth;
        int winHeight;
};

#endif // GAMEMAP_H
