#include "main.h"
#include "graphix/mainmenuscene.h"
#include "definitions.h"
USING_NS_CC;

Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = MainScene::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
      Vec2 origin = Director::getInstance()->getVisibleOrigin();

    this->schedule(schedule_selector(MainScene::GoToMainMenuScene), DISPLAY_TIME_SPLASH_SCENE);

    // Pacman header
    TTFConfig ttfConfig("fonts/PacFont.ttf", 72);
    auto headerLabel = Label::createWithTTF(ttfConfig, "pacman", TextHAlignment::CENTER,100);
    headerLabel->setPosition(visibleSize.width / 2 + origin.x,
                             3*visibleSize.height / 4 + origin.y);
    this->addChild(headerLabel);

    // programmer : Mehrshad Lotfi
    TTFConfig ttfConfig2("fonts/emulogic.ttf", 28);
    auto nameLabel = Label::createWithTTF(ttfConfig2, "Mehrshad Lotfi", TextHAlignment::CENTER,100);
    nameLabel->setPosition(visibleSize.width / 2 + origin.x,
                           2*visibleSize.height / 5 + origin.y);
    this->addChild(nameLabel);

    return true;
}

void MainScene::GoToMainMenuScene(float dt)
{
    auto scene = MainMenuScene::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

