#ifndef GAME_SCENE_H
#define GAME_SCENE_H
#include "cocos2d.h"
using namespace std;
USING_NS_CC;

class GameMap;
class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
    
    CREATE_FUNC(GameScene)

private :
    void update(float delta);
    GameMap *gameMap;
    int widthGap;
    int heightGap;
    Label *scoreBoard;
};

#endif // GAME_SCENE_H
