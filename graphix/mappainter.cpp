/*
#include "cocos2d.h"
#include "mappainter.h"
#include "logic/brick.h"
#include "logic/objectnames.h"
USING_NS_CC;


MapPainter::MapPainter(GameMap* gm, Size* widgetSize)
    : gameMap(gm)
{
    int maxWidth = gameMap->getMaxWidth() * 30;
    double scaleSize =  widgetSize->width / maxWidth;
    int scaleWidth = scaleSize * 30;

    for (auto brick: gameMap->getBricks())
    {
        Sprite * tmpSprt = Sprite::create(textureImage[brick->getTexture()]);
        tmpSprt->setScale(scaleSize);
        tmpSprt->setPosition(brick->getPosition()->getX() * scaleWidth + scaleWidth / 2, brick->getPosition()->getY() * scaleWidth + scaleWidth / 2);
        this->addChild(tmpSprt);
    }
}

*/
