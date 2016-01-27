#include "bonus.h"

Bonus::Bonus(GPoint *pos, GPoint *origin)
    : ScoreObject(pos, EBonus, origin)
{

}

string Bonus::DeepToString() const
{
}

string Bonus::ToString() const
{

}

int Bonus::getScore() const
{
    return 0;
}
