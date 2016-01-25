#ifndef GAMEOVER_SCENE_H
#define GAMEOVER_SCENE_H

#include "cocos2d.h"

class GameOverScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(GameOverScene);
private :
	cocos2d::Label* label;
};

#endif // GAMEOVER_SCENE_H
