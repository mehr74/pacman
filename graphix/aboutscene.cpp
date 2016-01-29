#include "graphix/aboutscene.h"
#include "graphix/mainmenuscene.h"
#include "definitions.h"
USING_NS_CC;

Scene* AboutScene::createScene()
{
    auto scene = Scene::create();

    auto layer = AboutScene::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool AboutScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
      Vec2 origin = Director::getInstance()->getVisibleOrigin();

    this->schedule(schedule_selector(AboutScene::GoToMainMenuScene), DISPLAY_TIME_ABOUT_SCENE);

    // Pacman header
    TTFConfig ttfConfig("fonts/PacFont.ttf", 72);
    auto headerLabel = Label::createWithTTF(ttfConfig, "pacman", TextHAlignment::CENTER,100);
    headerLabel->setPosition(visibleSize.width / 2 + origin.x,
                             3*visibleSize.height / 4 + origin.y);
    this->addChild(headerLabel);

    // programmer : Mehrshad Lotfi
    TTFConfig ttfConfig2("fonts/Mistral.ttf", 36);
    auto nameLabel = Label::createWithTTF(ttfConfig2,
               "Pacman is a practical part of a course assignment"
               " on learning advanced programming course held in "
               "Sharif university of technology in 2015-2016\n\nMehrshad Lotfi\nAmirHossein Mohaddesi", TextHAlignment::CENTER,800);
    nameLabel->setPosition(visibleSize.width / 2 + origin.x,
                           2*visibleSize.height / 5 + origin.y);
    this->addChild(nameLabel);

    return true;
}

void AboutScene::GoToMainMenuScene(float dt)
{
    auto scene = MainMenuScene::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}


