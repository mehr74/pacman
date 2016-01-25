#ifndef MAIN_H
#define MAIN_H

#include "cocos2d.h"
using namespace std;


class MainScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(MainScene);
private :
	cocos2d::Label* label;
};

#endif // MAIN_H
