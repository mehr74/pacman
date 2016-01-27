#ifndef MAINMENU_SCENE_H
#define MAINMENU_SCENE_H

#include "cocos2d.h"

class MainMenuScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(MainMenuScene)

private:
    void GoToGameScene(cocos2d::Ref *sender);
    void GoToAboutScene(cocos2d::Ref *sender);
    void menuCloseCallback(Ref* pSender);
};

#endif // MAINMENU_SCENE_H
