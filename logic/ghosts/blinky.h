#ifndef BLINKY_H
#define BLINKY_H

#include "logic/ghost.h"
class Blinky : public Ghost
{
public:
    Blinky(GPoint* pnt, GPoint* origin = new GPoint(0, 0));

    virtual string ToString() const;
    virtual string DeepToString() const;

private:
    virtual void animate();

};

#endif // BLINKY_H
