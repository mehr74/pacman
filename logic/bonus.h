#ifndef BONUS_H
#define BONUS_H

#include "logic/scoreobject.h"

class Bonus : public ScoreObject
{
public:
    Bonus(GPoint* pos, GPoint* = new GPoint(0, 0));
    virtual string DeepToString() const;
    virtual string ToString() const;

    virtual int getScore() const;

private:
};

#endif // BONUS_H
