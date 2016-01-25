#ifndef PINKY_H
#define PINKY_H

#include "logic/ghost.h"
class Pinky : public Ghost
{
public:
    Pinky(GPoint *pos);

    virtual string ToString() const;
    virtual string DeepToString() const;
private:

};

#endif // PINKY_H
