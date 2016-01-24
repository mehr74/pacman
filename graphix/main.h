#ifndef MAIN_H
#define MAIN_H

#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "logic/objNames.h"
using namespace std;


class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(HelloWorld);
private :
	cocos2d::Label* label;
};

#endif // MAIN_H
