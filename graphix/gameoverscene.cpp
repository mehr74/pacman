#include "graphix/gameoverscene.h"

USING_NS_CC;

Scene* GameOverScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = GameOverScene::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool GameOverScene
::init()
{
    if ( !Layer::init() )
    {
        return false;
    }


    return true;
}

