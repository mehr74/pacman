#ifndef OBJNAMES_H
#define OBJNAMES_H

enum GTexture {
	EBackground = 0,
	ENone,
	EPoint,
	EBonus,

	EBanana,
	EApple,
	EAppleRed,
	EVinograd,
	EOrange,
	ECocos,

	EHorizontal,
	EVertical,
	EAngleLd,
	EAangleRd,
	EAngleRv,
	EAngleLv,
	EArcUp,
	EArcLeft,
	EArcRight,
	EArcDown,
	EArc2Up,
	EArc2Right,
	EArc2Left,
	EArc2Down,

	EThreeGoldStar,
	ETwoGoldStar,
	EOneGoldStar,
	ESilverStars,
	ELockGoldStar,
	Elock,

	EPacmanLeftOpen,
	EPacmanLeftClose,
	EPacmanRightOpen,
	EPacmanRightClose,
	EPacmanDownOpen,
	EPacmanDownClose,
	EPacmanUpOpen,
	EPacmanUpClose,

	EOrbLeft,
	EOrbRight,
	EOrbUp,
	EOrbDown,

	ESpiritDefenceWhite,
	EspiritDefence,

	EClydeLeft,
	EClydeRight,
	EClydeDown,
	EClydeUp,

	EBlinkyLeft,
	EBlinkyRight,
	EBlinkyDown,
	EBlinkyUp,

	EInkyLeft,
	EInkyRight,
	EInkyDown,
	EInkyUp,

	EPinkyLeft,
	EPinkyRight,
	EPinkyDown,
	EPinkyUp,

	EArrow_left,
	EArrow_right,

	ETextureLast,
};

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


#endif // OBJNAMES_H
