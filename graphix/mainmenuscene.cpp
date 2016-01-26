#include "graphix/mainmenuscene.h"
#include "gamescene.h"
#include "main.h"
#include "definitions.h"
USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = MainMenuScene::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    TTFConfig ttfConfig("fonts/PacFont.ttf", 72);
    auto headerLabel1 = Label::createWithTTF(ttfConfig, "pa", TextHAlignment::CENTER,100);
    auto headerLabel2 = Label::createWithTTF(ttfConfig, "c", TextHAlignment::CENTER,100);
    auto headerLabel3 = Label::createWithTTF(ttfConfig, "man", TextHAlignment::CENTER,100);

    headerLabel2->setColor(Color3B(248, 248, 50));

    headerLabel1->setPosition(visibleSize.width / 2 + origin.x - 137,
                             3*visibleSize.height / 4 + origin.y);
    headerLabel2->setPosition(visibleSize.width / 2 + origin.x - 51,
                             3*visibleSize.height / 4 + origin.y);
    headerLabel3->setPosition(visibleSize.width / 2 + origin.x + 90,
                             3*visibleSize.height / 4 + origin.y);

    this->addChild(headerLabel1);
    this->addChild(headerLabel2);
    this->addChild(headerLabel3);

    TTFConfig ttfConfig1("fonts/emulogic.ttf", 28);
    auto label1 = Label::createWithTTF(ttfConfig1, "PLAY", TextHAlignment::CENTER,100);
    auto label2 = Label::createWithTTF(ttfConfig1, "ABOUT", TextHAlignment::CENTER,100);
    auto label3 = Label::createWithTTF(ttfConfig1, "EXIT", TextHAlignment::CENTER,100);
    auto *menuItem1 = MenuItemLabel::create( label1,
                                           CC_CALLBACK_1( MainMenuScene::GoToGameScene, this ));
    auto *menuItem2 = MenuItemLabel::create( label2,
                                           CC_CALLBACK_1( MainMenuScene::GoToGameScene, this ));
    auto *menuItem3 = MenuItemLabel::create( label3,
                                           CC_CALLBACK_1( MainMenuScene::GoToGameScene, this ));

    menuItem3->setPosition(Point(visibleSize.width / 2 + origin.x,
                                 3*visibleSize.height / 8 + origin.y));
    menuItem2->setPosition(Point(visibleSize.width/ 2 + origin.x,
                                 3*visibleSize.height / 8 + origin.y + 60));
    menuItem1->setPosition(Point(visibleSize.width/ 2 + origin.x,
                                 3*visibleSize.height / 8 + origin.y + 120));

    auto menu = Menu::create(menuItem1, menuItem2, menuItem3, NULL);
    menu->setPosition(Point::ZERO);

    this->addChild(menu);

    return true;
}

void MainMenuScene::GoToGameScene(cocos2d::Ref *sender)
{
    auto scene = GameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create( TRANSITION_TIME, scene));

}

