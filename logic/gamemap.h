#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "cocos2d.h"
#include "logic/objectnames.h"
#include "gpoint.h"
using namespace std;

class Brick;
class Ghost;
class Player;
class Inky;
class Pinky;
class Blinky;
class Clyde;
class GameMap
{
    public:
        GameMap(std::string mapFile, GPoint* origin = new GPoint(0, 0));


        vector<Brick*> getBricks() const;
        vector<Ghost*> getGhosts() const;
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
        Player* player;
        int maxWidth;
        int maxHeight;
};

#endif // GAMEMAP_H
