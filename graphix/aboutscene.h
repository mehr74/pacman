#ifndef ABOUT_SCENE_H
#define ABOUT_SCENE_H

#include "cocos2d.h"
using namespace std;

class AboutScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(AboutScene)

private :
    void GoToMainMenuScene(float dt);
};

#endif // ABOUT_SCENE_H
