#ifndef OBJNAMES_H
#define OBJNAMES_H

enum GGhost {
    INKY_GHOST,
    PINKY_GHOST,
    CLYDE_GHOST,
    BLINKY_GHOST
};

enum GState {
    DEAD_STATE,
    NORMAL_STATE,
    ACTIVE_STATE
};

enum GDirection {
    UP_DIR,
    DOWN_DIR,
    RIGHT_DIR,
    LEFT_DIR,
    NOT_SET_DIR
};

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

class ObjectNames
{
public:
    static char* getTextureImage(GTexture);
    static char* getTextureName(GTexture);
    static char* getDirectionName(int dir);
    static char* getStateName(int state);
};

#endif // OBJNAMES_H
