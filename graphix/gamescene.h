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

    static string levelFile;

private :
    void update(float delta);
    void updateTimerForFruit(float delta);
    void GoToWinnerScene();
    void GoToGameOverScene();
    GameMap *gameMap;
    int widthGap;
    int heightGap;
    Label *scoreBoard;
    int fruitTimer;
};

#endif // GAME_SCENE_H
