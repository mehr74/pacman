#include "definitions.h"
#include "ghost.h"


Ghost::Ghost(GPoint *pnt, GTexture texture, GPoint *origin)
    : MovingObject(pnt,texture, GHOST_NORMAL_SPEED, GHOST_ACTIVE_SPEED, origin)
{

}
