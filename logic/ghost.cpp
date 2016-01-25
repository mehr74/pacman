#include "ghost.h"


Ghost::Ghost(GPoint *pnt, GTexture texture)
    : MovingObject(pnt,texture, GHOST_NORMAL_SPEED, GHOST_ACTIVE_SPEED)
{

}
