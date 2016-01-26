#ifndef GAME_SCENE_H
#define GAME_SCENE_H
#include "cocos2d.h"
using namespace std;

class GameMap;
class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(GameScene)

private :
    void update(float delta);
    GameMap *gameMap;
    int widthGap;
    int heightGap;
};

#endif // GAME_SCENE_H
