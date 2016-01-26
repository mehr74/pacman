#include <iostream>
#include <iomanip>
#include "logic/gamemap.h"
#include "logic/brick.h"
#include "logic/gpoint.h"
#include "logic/ghost.h"
#include "logic/player.h"
#include "logic/ghosts/blinky.h"
#include "logic/ghosts/clyde.h"
#include "logic/ghosts/inky.h"
#include "logic/ghosts/pinky.h"

USING_NS_CC;
using namespace std;

GameMap::GameMap(string fileName, int windowWidth, int windowHeight)
    : winWidth(windowWidth), winHeight(windowHeight)
{
    log("Initializing map :");
    initializeMap(fileName);
}

vector<Brick*> GameMap::getBricks() const
{
    return bricks;
}

vector<Ghost*> GameMap::getGhosts() const
{
    return ghosts;
}

Player* GameMap::getPlayer() const
{
    return player;
}

int GameMap::getMaxWidth() const
{
    return maxWidth;
}

int GameMap::getMaxHeight() const
{
    return maxHeight;
}

GPoint* GameMap::getPlayerPos() const
{
    return player->getPosition();
}

void GameMap::setPlayerPos(GPoint* pos)
{
    player = new Player(pos);
}

GPoint* GameMap::getGhostPos(GGhost ghost) const
{
    for(int i = 0; i < ghostTypes.size(); i++)
    {
        if(ghostTypes[i] == ghost)
            return ghosts[i]->getPosition();
    }
}

void GameMap::setGhostPos(GGhost ghost, GPoint* pos) const
{
    for(int i = 0; i < ghostTypes.size(); i++)
    {
        if(ghostTypes[i] == ghost)
        {
            ghosts[i]->setPosition(pos);
            return;
        }
    }
}

void GameMap::initializeMap(string fileName)
{
    string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(fileName.c_str());
    cout << fullPath << endl;
    ssize_t fileSize = 0;
    unsigned char* fileContents = CCFileUtils::sharedFileUtils() -> getFileData(fullPath.c_str() , "r", &fileSize);
	stringstream fileBuffer;
	fileBuffer << fileContents;

    fileBuffer >> maxWidth;
    fileBuffer >> maxHeight;

    mapOrigin = new GPoint( (winWidth - this->getMaxWidth()*15)/2,
                            (winHeight - this->getMaxHeight()*15)/2 );

    cout << setfill('*') <<setw(60) << "" << endl;
    cout << setfill(' ') << std::left << setw(59) << "* Initializing map " << "*" << endl;
    cout << "*" << setw(58) << "" << "*" << endl;

    int number;
    int x = 0;
    int y = 0;

    while( fileBuffer >> number )
    {
        switch (number)
        {
            case 1:
                bricks.push_back(new Brick(new GPoint(x, y), EPoint));
                break;
            case 2:
                bricks.push_back(new Brick(new GPoint(x, y), EHorizontal));
                break;
            case 3:
                bricks.push_back(new Brick(new GPoint(x, y), EVertical));
                break;
            case 4:
                bricks.push_back(new Brick(new GPoint(x, y), EAngleLd));
                break;
            case 5:
                bricks.push_back(new Brick(new GPoint(x, y), EAangleRd));
                break;
            case 6:
                bricks.push_back(new Brick(new GPoint(x, y), EAngleRv));
                break;
            case 7:
                bricks.push_back(new Brick(new GPoint(x, y), EAngleLv));
                break;
            case 8:
                bricks.push_back(new Brick(new GPoint(x, y), EArcUp));
                break;
            case 9:
                bricks.push_back(new Brick(new GPoint(x, y), EArcLeft));
                break;
            case 10:
                bricks.push_back(new Brick(new GPoint(x, y), EArcRight));
                break;
            case 11:
                bricks.push_back(new Brick(new GPoint(x, y), EArcDown));
                break;
            case 12:
                bricks.push_back(new Brick(new GPoint(x, y), EArc2Up));
                break;
            case 13:
                bricks.push_back(new Brick(new GPoint(x, y), EArc2Right));
                break;
            case 14:
                bricks.push_back(new Brick(new GPoint(x, y), EArc2Left));
                break;
            case 15:
                bricks.push_back(new Brick(new GPoint(x, y), EArc2Down));
                break;
            case 16:
                bricks.push_back(new Brick(new GPoint(x, y), EBonus));
                break;
            case 85:
                bricks.push_back(new Brick(new GPoint(x, y), ENone));
                player = new Player(new GPoint(x, y), mapOrigin);
                break;
            case 90:
                bricks.push_back(new Brick(new GPoint(x, y), ENone));
                ghosts.push_back(new Blinky(new GPoint(x, y), mapOrigin));
                break;
            case 91:
                bricks.push_back(new Brick(new GPoint(x, y), ENone));
                ghosts.push_back(new Pinky(new GPoint(x, y), mapOrigin));
                break;
            case 92:
                bricks.push_back(new Brick(new GPoint(x, y), ENone));
                ghosts.push_back(new Clyde(new GPoint(x, y), mapOrigin));
                break;
            case 93:
                bricks.push_back(new Brick(new GPoint(x, y), ENone));
                ghosts.push_back(new Inky(new GPoint(x, y), mapOrigin));
                break;
            case 99:
                bricks.push_back(new Brick(new GPoint(x, y), ENone));
                break;
            default:
                bricks.push_back(new Brick(new GPoint(x, y), EBackground));

                break;
        }

        cout << "* NEW " << setw(53) << bricks.back()->DeepToString() << "*" << endl;
        
        x++;
        if(x == maxWidth)
        {
            x = 0;
            y++;
        }
    }

    for(int i = 0; i < ghosts.size(); i++)
    {
        ghosts[i]->setBricks(getBricks(), maxWidth, maxHeight);
        cout << "* NEW " << setw(53) << *ghosts[i] << "*" << endl;
    }
    cout << "* NEW " << setw(53) << *player  << "*" << endl;
    cout << "*" << setw(58) << "" << "*" << endl;
    cout << setfill('*') <<setw(60) << "" << endl;
}
