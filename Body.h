#ifndef BODY_H
#define BODY_H

#include "Math.h"
#include "Entity.h"

enum CollisionGroup {
    CG_ALL,
    CG_NEUTRAL,
    CG_FRIEND,
    CG_ENEMY
};

class Body : public Entity {
public:
    Body(vec2 pos, vec2 size, CollisionGroup group = CG_ALL, bool scrolls = true);

    virtual void contactNotify(Body *body);
    virtual rect2 getRect() const;

    CollisionGroup collisionGroup;
    vec2 size;
};

#endif
