#ifndef INKY_H
#define INKY_H

#include "logic/ghost.h"
class Inky : public Ghost
{
public:
    Inky(GPoint* pos);

    virtual string ToString() const;
    virtual string DeepToString() const;
private:

};

#endif // INKY_H
