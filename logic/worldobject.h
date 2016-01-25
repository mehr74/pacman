#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include "cocos2d.h"
#include <iostream>
#include <string>
#include "logic/objectnames.h"
#include "logic/gpoint.h"
using namespace std;

class WorldObject
{
    public:
        WorldObject(GPoint* pnt, GTexture texture, int width = 30, int height = 30);

        GTexture getTexture() const;
        GPoint* getPosition() const;

        void setPosition(GPoint* pnt);

        virtual string ToString() const = 0;
        virtual string DeepToString() const = 0;

    protected:
        GPoint* position;

    private:
        GTexture gTexture;
        int width;
        int height;
};

ostream& operator <<(ostream& out, const WorldObject& obj);

#endif // WORLDOBJECT
