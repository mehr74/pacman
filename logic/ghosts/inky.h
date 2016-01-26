#ifndef INKY_H
#define INKY_H

#include "logic/ghost.h"
class Inky : public Ghost
{
public:
    Inky(GPoint* pos, GPoint* origin = new GPoint(0, 0));

    virtual string ToString() const;
    virtual string DeepToString() const;


    virtual void animate();

private:

};

#endif // INKY_H
