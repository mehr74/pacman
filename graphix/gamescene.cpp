#include <iostream>
#include "gamescene.h"
#include "logic/gamemap.h"
#include "logic/objectnames.h"
#include "logic/brick.h"
#include "logic/ghost.h"
#include "logic/player.h"
#include "definitions.h"

using namespace std;
USING_NS_CC;

Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = GameScene::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();


    gameMap = new GameMap("lvl_02.txt", visibleSize.width, visibleSize.height);
    widthGap = visibleSize.width - gameMap->getMaxWidth()*15;
    heightGap = visibleSize.height - gameMap->getMaxHeight()*15;

    // Draw bricks
    for (auto brick: gameMap->getBricks())
    {
        Sprite * tmpSprt = Sprite::create(ObjectNames::getTextureImage(brick->getTexture()));
        tmpSprt->setPosition(brick->getPosition()->getX() * 15 + widthGap/2,
                             brick->getPosition()->getY() * 15 + heightGap/2);
        this->addChild(tmpSprt);
    }

    for (auto ghost: gameMap->getGhosts())
    {
        Sprite * ghostSprt = ghost->getSprite();
        this->addChild(ghostSprt);
    }

//    auto player = gameMap.getPlayer();
//    Sprite * tmpSprt = Sprite::create(textureImage[player->getTexture()]);
//    tmpSprt->setPosition(player->getPosition()->getX() * 15 + widthGap/2,
//                         player->getPosition()->getY() * 15 + heightGap/2);
//    this->addChild(tmpSprt);

    this->schedule(schedule_selector(GameScene::update), UPDATE_TIME);

    return true;
}

void GameScene::update(float delta)
{
    for (auto ghost: gameMap->getGhosts())
    {
        ghost->randomMove();
    }
}

