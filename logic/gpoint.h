#ifndef GPOINT_H
#define GPOINT_H

#include "cocos2d.h"

class GPoint
{
    public:
        GPoint(int x, int y);
        int getX();
        int getY();

    private:
        int x;
        int y;
};

#endif // GPOINT_H
