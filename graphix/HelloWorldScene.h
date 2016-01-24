#ifndef HELLOWORLDSCENE_H
#define HELLOWORLDSCENE_H

#include "cocos2d.h"
#include "logic/objNames.h"
using namespace std;

class Brick;
class GPoint;

class GameMap
{
    public:
        GameMap(std::string mapFile);
        vector<Brick*> getBricks() const;
        int getMaxWidth() const;
        int getMaxHeight() const;

        GPoint* getInkyPos() const;
        void setInkyPos(GPoint* pos);

        GPoint* getBlinkyPos() const;
        void setBlinkyPos(GPoint* pos);

        GPoint* getPinkyPos() const;
        void setPinkyPos(GPoint* pos);

        GPoint* getClydePos() const;
        void setClydePos(GPoint* pos);

        GPoint* getPlayerPos() const;
        void setPlayerPos(GPoint* pos);

    private:
        GPoint* inkyPos;
        GPoint* blinkyPos;
        GPoint* pinkyPos;
        GPoint* clydePos;
        GPoint* playerPos;
        void initializeMap(std::string mapFile);
        vector<Brick*> bricks;
        int maxWidth;
        int maxHeight;
};

class GPoint
{
    public:
        GPoint(int x, int y);
        int getX();
        int getY();

    private:
        int x;
        int y;
};

class WorldObject
{
    public:
        WorldObject(GPoint* pnt, GTexture texture, int width = 30, int height = 30);
        GTexture getTexture() const;
        GPoint* getPosition() const;

    protected:
        GPoint* position;

    private:
        GTexture gTexture;
        int width;
        int height;
};

class Brick : public WorldObject
{
    public:
        Brick(GPoint* pnt, GTexture texture, int width = 30, int height = 30);
};


#endif // HELLOWORLDSCENE_H
