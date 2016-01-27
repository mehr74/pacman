#ifndef FRUIT_H
#define FRUIT_H

#include "logic/scoreobject.h"

class Fruit : public ScoreObject
{
public:
    Fruit(GPoint* pos, GPoint* = new GPoint(0, 0));
    virtual string DeepToString() const;
    virtual string ToString() const;

    virtual int getScore() const;

    bool decrementTimer();

private:
    int myTimer;
};

#endif // FRUIT_H
