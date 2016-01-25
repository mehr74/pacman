#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "cocos2d.h"
#include "logic/objectnames.h"
using namespace std;

class Brick;
class GPoint;
class Ghost;
class Player;
class Inky;
class Pinky;
class Blinky;
class Clyde;
class GameMap
{
    public:
        GameMap(std::string mapFile);
        vector<Brick*> getBricks() const;
        int getMaxWidth() const;
        int getMaxHeight() const;

        GPoint* getPlayerPos() const;
        void setPlayerPos(GPoint* pos);

        GPoint* getGhostPos(GGhost ghost) const;
        void setGhostPos(GGhost ghost, GPoint* pos) const;

    private:
        void initializeMap(std::string mapFile);
        vector<Brick*> bricks;
        Inky* inky;
        Pinky* pinky;
        Blinky* blinky;
        Clyde* clyde;
        Player* player;
        int maxWidth;
        int maxHeight;
};

#endif // GAMEMAP_H
