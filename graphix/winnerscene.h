#ifndef WINNER_SCENE_H
#define WINNER_SCENE_H

#include "cocos2d.h"

class WinnerScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(WinnerScene)

private :
    void GoToMainMenuScene(float dt);

};

#endif // WINNER_SCENE_H
