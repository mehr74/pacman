#include "HelloWorldScene.h"
#include "logic/objNames.h"

USING_NS_CC;

GameMap::GameMap(string fileName)
{
    log("Initializing map :");
    initializeMap(fileName);
}

vector<Brick*> GameMap::getBricks() const
{
    return bricks;
}

int GameMap::getMaxWidth() const
{
    return maxWidth;
}

int GameMap::getMaxHeight() const
{
    return maxHeight;
}
void GameMap::setInkyPos(GPoint* pos)
{
    inkyPos = pos;
}

GPoint* GameMap::getInkyPos(void) const
{
    return inkyPos;
}

void GameMap::setBlinkyPos(GPoint* pos)
{
    blinkyPos = pos;
}

GPoint* GameMap::getBlinkyPos(void) const
{
    return blinkyPos;
}

void GameMap::setPinkyPos(GPoint* pos)
{
    pinkyPos = pos;
}

GPoint* GameMap::getPinkyPos(void) const
{
    return pinkyPos;
}

void GameMap::setClydePos(GPoint* pos)
{
    clydePos = pos;
}

GPoint* GameMap::getClydePos(void) const
{
    return clydePos;
}

void GameMap::setPlayerPos(GPoint* pos)
{
    playerPos = pos;
}

GPoint* GameMap::getPlayerPos(void) const
{
    return playerPos;
}
void GameMap::initializeMap(string fileName)
{
    string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(fileName.c_str());
    ssize_t fileSize = 0;
    unsigned char* fileContents = CCFileUtils::sharedFileUtils() -> getFileData(fullPath.c_str() , "r", &fileSize);
	stringstream fileBuffer;
	fileBuffer << fileContents;

    fileBuffer >> maxWidth;


    int number;
    int x = 0;
    int y = 0;

    while( fileBuffer >> number )
    {
        switch (number)
        {
            case 1:
                log("Insert %8s   at position (%-2d, %d)", "point", x, y);
                bricks.push_back(new Brick(new GPoint(x, y), EPoint));
                break;
            case 2:
                log("Insert %10s at position (%-2d, %2d)", "horizontal", x, y);
                bricks.push_back(new Brick(new GPoint(x, y), EHorizontal));
                break;
            case 3:
                log("Insert %9s  at position (%-2d, %2d)", "vertical", x, y);
                bricks.push_back(new Brick(new GPoint(x, y), EVertical));
                break;
            case 4:
                log("Insert %9s  at position (%-2d, %2d)", "angel(LD)", x, y);
                bricks.push_back(new Brick(new GPoint(x, y), EAngleLd));
                break;
            case 5:
                log("Insert %9s  at position (%-2d, %2d)", "angel(RD)", x, y);
                bricks.push_back(new Brick(new GPoint(x, y), EAangleRd));
                break;
            case 6:
                log("Insert %9s  at position (%-2d, %2d)", "angel(RV)", x, y);
                bricks.push_back(new Brick(new GPoint(x, y), EAngleRv));
                break;
            case 7:
                log("Insert %9s  at position (%-2d, %2d)", "angel(LV)", x, y);
                bricks.push_back(new Brick(new GPoint(x, y), EAngleLv));
                break;
            case 8:
                log("Insert %8s   at position (%-2d, %2d)", "Arc(U)", x, y);
                bricks.push_back(new Brick(new GPoint(x, y), EArcUp));
                break;
            case 9:
                log("Insert %8s   at position (%-2d, %2d)", "Arc(L)", x, y);
                bricks.push_back(new Brick(new GPoint(x, y), EArcLeft));
                break;
            case 10:
                log("Insert %8s   at position (%-2d, %2d)", "Arc(R)", x, y);
                bricks.push_back(new Brick(new GPoint(x, y), EArcRight));
                break;
            case 11:
                log("Insert %8s   at position (%-2d, %2d)", "Arc(D)", x, y);
                bricks.push_back(new Brick(new GPoint(x, y), EArcDown));
                break;
            case 12:
                log("Insert %9s  at position (%-2d, %2d)", "Arc2(U)", x, y);
                bricks.push_back(new Brick(new GPoint(x, y), EArc2Up));
                break;
            case 13:
                log("Insert %9s  at position (%-2d, %2d)", "Arc2(R)", x, y);
                bricks.push_back(new Brick(new GPoint(x, y), EArc2Right));
                break;
            case 14:
                log("Insert %9s  at position (%-2d, %2d)", "Arc2(L)", x, y);
                bricks.push_back(new Brick(new GPoint(x, y), EArc2Left));
                break;
            case 15:
                log("Insert %9s  at position (%-2d, %2d)", "Arc2(D)", x, y);
                bricks.push_back(new Brick(new GPoint(x, y), EArc2Down));
                break;
            case 16:
                log("Insert %8s   at position (%-2d, %2d)", "Bonus", x, y);
                bricks.push_back(new Brick(new GPoint(x, y), EBonus));
                break;
            case 90:
                log("Insert %7s    at position (%-2d, %2d)", "None", x, y);
                log("--->Set Blinky position to (%-2d, %2d)", x, y);
                setBlinkyPos(new GPoint(x, y));
                bricks.push_back(new Brick(new GPoint(x, y), ENone));
                break;
            case 91:
                log("Insert %7s    at position (%-2d, %2d)", "None", x, y);
                log("--->Set Pinky position to (%-2d, %2d)", x, y);
                setPinkyPos(new GPoint(x, y));
                bricks.push_back(new Brick(new GPoint(x, y), ENone));
                break;
            case 92:
                log("Insert %7s    at position (%-2d, %2d)", "None", x, y);
                log("--->Set Clyde position to (%-2d, %2d)", x, y);
                setClydePos(new GPoint(x, y));
                bricks.push_back(new Brick(new GPoint(x, y), ENone));
                break;
            case 93:
                log("Insert %7s    at position (%-2d, %2d)", "None", x, y);
                log("--->Set Inky position to (%-2d, %2d)", x, y);
                setInkyPos(new GPoint(x, y));
                bricks.push_back(new Brick(new GPoint(x, y), ENone));
                break;
            case 99:
                log("Insert %7s    at position (%-2d, %2d)", "None", x, y);
                bricks.push_back(new Brick(new GPoint(x, y), ENone));
                break;
            default:
                log("Insert %10s at position (%-2d, %2d)", "Background", x, y);
                bricks.push_back(new Brick(new GPoint(x, y), EBackground));
                break;
        }
        
        x++;
        if(x == maxWidth)
        {
            x = 0;
            y++;
        }
    }

    maxHeight = y;
}

GPoint::GPoint(int x, int y)
{
    this->x = x;
    this->y = y;
}

int GPoint::getX()
{
    return x;
}

int GPoint::getY()
{
    return y;
}


WorldObject::WorldObject(GPoint* pnt, GTexture texture, int width, int height)
{
    this->width = width;
    this->height = height;
    this->gTexture = texture;
    this->position = pnt;
}

GTexture WorldObject::getTexture() const
{
    return gTexture;
}


GPoint* WorldObject::getPosition() const
{
    return position;
}


Brick::Brick(GPoint* pnt, GTexture texture, int width, int height)
    : WorldObject(pnt, texture, width, height)
{

}
