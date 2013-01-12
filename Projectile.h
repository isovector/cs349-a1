#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Entity.h"

class Projectile : public Entity {
public:
    Projectile(Entity *owner, vec2 vel);

    virtual void update(float delta);
    virtual void draw() const;

private:
    vec2 velocity;
    Entity *parent;
};

#endif
