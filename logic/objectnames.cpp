#include "logic/objectnames.h"
static char textureImage[ETextureLast][60] = {
"background.png",
"none.png",
"point.png",
"bonus.png",

"banana.png",
"apple.png",
"apple_red.png",
"vinograd.png",
"orange.png",
"cocos.png",

"horizontal.png",
"vertical.png",
"angle_ld.png",
"angle_rd.png",
"angle_rv.png",
"angle_lv.png",
"arc_up.png",
"arc_left.png",
"arc_right.png",
"arc_down.png",
"arc2_up.png",
"arc2_right.png",
"arc2_left.png",
"arc2_down.png",

"three_gold_star.png",
"two_gold_star.png",
"one_gold_star.png",
"silver_stars.png",
"lock_gold_star.png",
"lock.png",

"pacmanLeftOpen.png",
"pacmanLeftClose.png",
"pacmanRightOpen.png",
"pacmanRightClose.png",
"pacmanDownClose.png",
"pacmanDownOpen.png",
"pacmanUpClose.png",
"pacmanUpOpen.png",

"orbLeft.png",
"orbRight.png",
"orbUp.png",
"orbDown.png",

"spiritDefenceWhite.png",
"spiritDefence.png",

"clydeLeft.png",
"clydeRight.png",
"clydeDown.png",
"clydeUp.png",

"blinkyLeft.png",
"blinkyRight.png",
"blinkyDown.png",
"blinkyUp.png",

"inkyLeft.png",
"inkyRight.png",
"inkyDown.png",
"inkyUp.png",

"pinkyLeft.png",
"pinkyRight.png",
"pinkyDown.png",
"pinkyUp.png",

"arrow_left.png",
"arrow_right.png",
};

static char textureNames[ETextureLast][60] = {
"Background",
"None",
"Point",
"Bonus",

"Banana",
"Apple",
"Apple red",
"Vinograd",
"Orange",
"Cocos",

"Horizontal",
"Vertical",
"Angle left down",
"Angle right down",
"Angle right up",
"Angle left up",
"Arc up",
"Arc left",
"Arc right",
"Arc down",
"Arc2 up",
"Arc2 right",
"Arc2 left",
"Arc2 down",

"Three gold star",
"Two gold star",
"One gold star",
"Silver stars",
"Lock gold star",
"Lock",

"Pacman left open",
"Pacman left close",
"Pacman right open",
"Pacman right close",
"Pacman down close",
"Pacman down open",
"Pacman up close",
"Pacman up open",

"orb left",
"orb right",
"orb up",
"orb down",

"Spirit defence white",
"spirit defence",

"Clyde left",
"Clyde right",
"Clyde down",
"Clyde up",

"Blinky left",
"Blinky right",
"Blinky down",
"Blinky up",

"Inky left",
"Inky right",
"Inky down",
"Inky up",

"Pinky left",
"Pinky right",
"Pinky down",
"Pinky up",

"Arrow left",
"Arrow right",
};


char* ObjectNames::getTextureImage(GTexture texture)
{
    return textureImage[texture];
}

char* ObjectNames::getTextureName(GTexture texture)
{
    return textureNames[texture];
}


