#ifndef MAP_SELECTOR_SCENE_H
#define MAP_SELECTOR_SCENE_H

#include "cocos2d.h"

class MapSelectorScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(MapSelectorScene)

private:
    void GoToGameScene();
    void setToMap1(cocos2d::Ref *sender);
    void setToMap2(cocos2d::Ref *sender);
    void setToMap3(cocos2d::Ref *sender);
    void setToMap4(cocos2d::Ref *sender);
    void setToMap5(cocos2d::Ref *sender);
    void setToMap6(cocos2d::Ref *sender);
};

#endif // MAP_SELECTOR_SCENE_H
