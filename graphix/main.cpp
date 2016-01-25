#include "main.h"
#include "logic/gamemap.h"
#include "logic/objectnames.h"
#include "logic/brick.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    
    auto layer = HelloWorld::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();

    GameMap gameMap("lvl_01.txt");
    int maxWidth = gameMap.getMaxWidth() * 30;
    double scaleSize =  visibleSize.width / maxWidth;
    int scaleWidth = scaleSize * 30;
    log("\nWindows size : (%lf, %lf)", visibleSize.width, visibleSize.height);
    log("Map print size : (%d, %d)", gameMap.getMaxWidth() * 30, gameMap.getMaxHeight() * 30);
    log("Scale size : %lf", scaleSize);
    
    for (auto brick: gameMap.getBricks())
    {
        Sprite * tmpSprt = Sprite::create(textureImage[brick->getTexture()]);
        tmpSprt->setScale(scaleSize);
        tmpSprt->setPosition(brick->getPosition()->getX() * scaleWidth + scaleWidth / 2, brick->getPosition()->getY() * scaleWidth + scaleWidth / 2);
        this->addChild(tmpSprt);
    }

    return true;
}

