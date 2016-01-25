#ifndef CLYDE_H
#define CLYDE_H

#include "logic/ghost.h"
class Clyde : public Ghost
{
public:
    Clyde(GPoint* pnt);

    virtual string ToString() const;
    virtual string DeepToString() const;

private:

};

#endif // CLYDE_H
