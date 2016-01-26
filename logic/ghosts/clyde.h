#ifndef CLYDE_H
#define CLYDE_H

#include "logic/ghost.h"
class Clyde : public Ghost
{
public:
    Clyde(GPoint* pnt, GPoint* origin = new GPoint(0, 0));

    virtual string ToString() const;
    virtual string DeepToString() const;

    virtual void animate();

private:

};

#endif // CLYDE_H
