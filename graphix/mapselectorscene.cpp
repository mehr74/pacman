#include <iostream>
#include "graphix/mapselectorscene.h"
#include "gamescene.h"
#include "definitions.h"
using namespace std;
USING_NS_CC;

Scene* MapSelectorScene::createScene()
{
    auto scene = Scene::create();

    auto layer = MapSelectorScene::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool MapSelectorScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    auto *menuItem1 = MenuItemImage::create( "map1.png", "level 1",
                                           CC_CALLBACK_1( MapSelectorScene::setToMap1, this ));
    auto *menuItem2 = MenuItemImage::create( "map2.png", "level 2",
                                           CC_CALLBACK_1( MapSelectorScene::setToMap2, this ));
    auto *menuItem3 = MenuItemImage::create( "map3.png", "level 3",
                                           CC_CALLBACK_1( MapSelectorScene::setToMap3, this ));
    auto *menuItem4 = MenuItemImage::create( "map4.png", "level 4",
                                           CC_CALLBACK_1( MapSelectorScene::setToMap4, this ));
    auto *menuItem5 = MenuItemImage::create( "map5.png", "level 5",
                                           CC_CALLBACK_1( MapSelectorScene::setToMap5, this ));
    auto *menuItem6 = MenuItemImage::create( "map6.png", "level 6",
                                           CC_CALLBACK_1( MapSelectorScene::setToMap6, this ));


    menuItem4->setPosition(Point(visibleSize.width / 3 + origin.x - 175,
                                 1*visibleSize.height / 3 + origin.y + 40));

    menuItem5->setPosition(Point(2* visibleSize.width/ 3 + origin.x - 175,
                                 1*visibleSize.height / 3 + origin.y + 40));

    menuItem6->setPosition(Point(visibleSize.width + origin.x - 175,
                                 1*visibleSize.height / 3 + origin.y + 40));

    menuItem1->setPosition(Point(visibleSize.width / 3 + origin.x - 175,
                                 2*visibleSize.height / 3 + origin.y + 40));

    menuItem2->setPosition(Point(2* visibleSize.width/ 3 + origin.x - 175,
                                 2*visibleSize.height / 3 + origin.y + 40));

    menuItem3->setPosition(Point(visibleSize.width + origin.x - 175,
                                 2*visibleSize.height / 3 + origin.y + 40));

    auto menu = Menu::create(menuItem1, menuItem2, menuItem3, menuItem4, menuItem5, menuItem6, NULL);
    menu->setPosition(Point::ZERO);

    this->addChild(menu);

    return true;
}

void MapSelectorScene::GoToGameScene()
{
    auto scene = GameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create( TRANSITION_TIME, scene));
}

void MapSelectorScene::setToMap1(cocos2d::Ref *sender)
{
    GameScene::levelFile = "lvl_01.txt";
    GoToGameScene();
}

void MapSelectorScene::setToMap2(cocos2d::Ref *sender)
{
    GameScene::levelFile = "lvl_02.txt";
    GoToGameScene();
}

void MapSelectorScene::setToMap3(cocos2d::Ref *sender)
{
    GameScene::levelFile = "lvl_03.txt";
    GoToGameScene();
}

void MapSelectorScene::setToMap4(cocos2d::Ref *sender)
{
    GameScene::levelFile = "lvl_04.txt";
    GoToGameScene();
}

void MapSelectorScene::setToMap5(cocos2d::Ref *sender)
{
    GameScene::levelFile = "lvl_05.txt";
    GoToGameScene();
}

void MapSelectorScene::setToMap6(cocos2d::Ref *sender)
{
    GameScene::levelFile = "lvl_06.txt";
    GoToGameScene();
}

