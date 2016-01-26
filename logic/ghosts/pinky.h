#ifndef PINKY_H
#define PINKY_H

#include "logic/ghost.h"
class Pinky : public Ghost
{
public:
    Pinky(GPoint *pos, GPoint* origin = new GPoint(0, 0));

    virtual string ToString() const;
    virtual string DeepToString() const;

    virtual void animate();

private:

};

#endif // PINKY_H
