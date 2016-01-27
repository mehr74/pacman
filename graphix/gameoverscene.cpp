#include "graphix/gameoverscene.h"
#include "graphix/mainmenuscene.h"
#include "definitions.h"

USING_NS_CC;

Scene* GameOverScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = GameOverScene::create();

    scene->addChild(layer);

    return scene;
}

bool GameOverScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    this->schedule(schedule_selector(GameOverScene::GoToMainMenuScene), DISPLAY_TIME_SPLASH_SCENE);

    // programmer : Mehrshad Lotfi
    TTFConfig ttfConfig2("fonts/emulogic.ttf", 28);
    auto nameLabel = Label::createWithTTF(ttfConfig2, "GAME OVER", TextHAlignment::CENTER,500);
    nameLabel->setPosition(visibleSize.width / 2 + origin.x,
                           visibleSize.height /2 + origin.y);
    this->addChild(nameLabel);

    return true;
}

void GameOverScene::GoToMainMenuScene(float dt)
{
    auto scene = MainMenuScene::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

