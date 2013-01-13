#include "Projectile.h"

Projectile::Projectile(Entity *owner, vec2 vel) :
    Entity(owner->position, false),
    parent(owner),
    velocity(vel)
{
}

void Projectile::update(float delta) {
    position += velocity * delta;
    
    if ((position.x < 0.0f || position.x > 600.0f)
        || (position.y < 0.0f || position.y > 400.0f)) {
        destroy();
    }
}

void Projectile::draw() const {
    XFillRectangle(display, win, gc, UNPACKI(position), 4, 10);
}
