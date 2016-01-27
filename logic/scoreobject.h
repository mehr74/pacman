#ifndef SCORE_OBJECT_H
#define SCORE_OBJECT_H
#include "cocos2d.h"
#include "logic/worldobject.h"
USING_NS_CC;


class ScoreObject : public WorldObject
{
public:
    ScoreObject(GPoint* pnt, GTexture texture, GPoint* = new GPoint(0, 0));
    ~ScoreObject();

    virtual string ToString() const = 0;
    virtual string DeepToString() const = 0;

    void setSprite(Sprite *sprite);
    Sprite* getSprite() const;

private:
    GPoint *mapOrigin;
    int mapMaxWidth;
    int mapMaxHeight;
    Sprite* mySprite;
};

#endif // SCORE_OBJECT_H
