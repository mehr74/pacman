#ifndef SCORE_POINT_H
#define SCORE_POINT_H

#include "logic/scoreobject.h"


class ScorePoint : public ScoreObject
{

public:
    ScorePoint(GPoint* pos, GPoint* = new GPoint(0, 0));
    virtual string DeepToString() const;
    virtual string ToString() const;

private:

};

#endif // SCORE_POINT_H
