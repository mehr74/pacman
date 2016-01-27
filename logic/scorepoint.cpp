#include "scorepoint.h"
#include "definitions.h"

const int ourScore = SCORE_POINT;

ScorePoint::ScorePoint(GPoint *pos, GPoint *origin)
    : ScoreObject(pos, EPoint, origin)
{

}

string ScorePoint::DeepToString() const
{
}

string ScorePoint::ToString() const
{

}

int ScorePoint::getScore() const
{
    return 10;
}
