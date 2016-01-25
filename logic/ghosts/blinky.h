#ifndef BLINKY_H
#define BLINKY_H

#include "logic/ghost.h"
class Blinky : public Ghost
{
public:
    Blinky(GPoint* pnt);

    virtual string ToString() const;
    virtual string DeepToString() const;

private:

};

#endif // BLINKY_H