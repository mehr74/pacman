#include "player.h"

Player::Player(GPoint *pnt)
    : MovingObject(pnt, EPacmanLeftOpen, PLAYER_NORMAL_SPEED, PLAYER_ACTIVE_SPEED)
{

}

string Player::ToString() const
{
}

string Player::DeepToString() const
{

}
