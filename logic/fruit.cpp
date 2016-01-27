#include "fruit.h"
#include "definitions.h"

Fruit::Fruit(GPoint *pos, GPoint* origin)
    : ScoreObject(pos, EBanana, origin),
      myTimer(8)
{
}


string Fruit::DeepToString() const
{
}

string Fruit::ToString() const
{

}

bool Fruit::decrementTimer()
{
    if(myTimer > 0)
    {
        myTimer--;
        return true;
    }
    return false;
}

int Fruit::getScore() const
{
    if(myTimer >= 3)
        return 500;
    return 200;
}
