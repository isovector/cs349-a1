#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Body.h"

class Projectile : public Body {
public:
    Projectile(Entity *owner, vec2 vel, CollisionGroup group);

    virtual void update(float delta);
    virtual void draw() const;
    virtual void contactNotify(Body *body);

private:
    vec2 velocity;
    Entity *parent;
};

#endif
