#include <iostream>
#include "gamescene.h"
#include "logic/gamemap.h"
#include "logic/objectnames.h"
#include "logic/brick.h"
#include "logic/ghost.h"
#include "logic/player.h"
#include "logic/bonus.h"
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
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

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
        this->addChild(ghostSprt,2);
    }

    for (auto bonus: gameMap->getBonuses())
    {
        Sprite * bonusSprt = bonus->getSprite();
        this->addChild(bonusSprt);
    }

    for (auto scorePoint : gameMap->getScorePoints())
    {
        Sprite * scorePntSprt = scorePoint->getSprite();
        this->addChild(scorePntSprt);
    }

    Player* player = gameMap->getPlayer();
    Sprite *playerSprt = player->getSprite();
    this->addChild(playerSprt);

    TTFConfig ttfConfig("fonts/Marker Felt.ttf", 24);
    auto scoreBoardLabel = Label::createWithTTF(ttfConfig, "SCORE: ", TextHAlignment::LEFT,0);
    scoreBoardLabel->setPosition(widthGap/2 + origin.x + 20,
                             heightGap/2 + origin.y + 15*gameMap->getMaxHeight() + 10);
    this->addChild(scoreBoardLabel);


    scoreBoard = Label::createWithTTF(ttfConfig, "0", TextHAlignment::LEFT,0);
    scoreBoard->setPosition(widthGap/2 + origin.x + 60,
                             heightGap/2 + origin.y + 15*gameMap->getMaxHeight() + 10);
    this->addChild(scoreBoard);


    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    this->schedule(schedule_selector(GameScene::update), UPDATE_TIME);

    return true;
}

void GameScene::update(float delta)
{
    for (auto ghost: gameMap->getGhosts())
    {
        ghost->randomMove(gameMap->getGhosts());
    }
}

void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    log("Key with keycode %d pressed", keyCode);
    bool isFailed = false;
    switch(keyCode)
    {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            cout << "keyboard left arrow" << endl;
            isFailed = gameMap->getPlayer()->playerMove(LEFT_DIR, gameMap->getGhosts());
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            isFailed = cout << "keyboard right arrow" << endl;
            gameMap->getPlayer()->playerMove(RIGHT_DIR, gameMap->getGhosts());
            break;
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W:
            cout << "keyboard up arrow" << endl;
            isFailed = gameMap->getPlayer()->playerMove(UP_DIR, gameMap->getGhosts());
            break;
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            cout << "keyboard down arrow" << endl;
            isFailed = gameMap->getPlayer()->playerMove(DOWN_DIR, gameMap->getGhosts());
            break;
    }

}

